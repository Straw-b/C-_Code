#include <iostream>
using namespace std;



#if 0
// ע�⣺�����÷�ʽ��Ϊ�����ķ���ֵʱ��һ�����ܷ���ջ�ϵĿռ䣺���纯���еľֲ�����
// �Ժ�������ԭ���Ƿ������
int& Add(int left, int right)
{
	int ret = 0;
	ret = left + right;
	return ret;
}

int main()
{
	int& sum = Add(1, 2);
	Add(3, 4);
	Add(5, 6);
	return 0;
}
#endif




#if 0
// ע�⣺����ʵ�����������ֻҪ���溯���Ľ�������������
int g_a = 0;// ȫ�ֱ���

//int& Add(int left, int right)
//{
//	g_a = left + right;
//	return g_a;
//}
//int main()
//{
//	int& sum = Add(1, 2);
//	Add(3, 4);
//	Add(5, 6);
//	return 0;
//}


int& Add(int left, int right, int& ret)
{
	g_a = left + right;
	return ret;
}
int main()
{
	int r = 0;
	int& sum = Add(1, 2, r);
	Add(3, 4, r);
	Add(5, 6, r);
	return 0;
}
#endif




#if 0
// ����
// һ��������ز������
void test(int a)
{}

void test(int& a)
{}

int main()
{
	test(10);

	int r = 10;
	test(r);// �������������Ե���
	return 0;
}
#endif


#if 0
int main()
{
	int a = 10;   // a�ڶ���ʱ��������Ҫ��a�������ٿռ�
	int& ra = a;  // ra���������͵ı������ڶ���ʱ���������Ͳ����ra���ٿռ�

	cout << typeid(a).name() << endl; // ��֤����
	cout << typeid(ra).name() << endl;
	return 0;
}
#endif




#if 0
#include <ctime> // clock ��ͷ�ļ�

struct A
{
	int array[100000];
};

void TestValue(A a) // ��ֵ
{}
void TestRef(A& a) // ������
{}
void TestPtr(A* a) // ��ָ��
{}

void TestFunc()
{
	A a;

	// ��ֵ���ڴ����ڼ���Ҫ����ʵ�ε�һ�ݿ���
	size_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
		TestValue(a);
	size_t end1 = clock();

	// �����Ǳ������ڴ����ڼ䲻��Ҫ���п���
	size_t begin2 = clock();
	for (int i = 0; i < 100000; i++)
		TestRef(a);
	size_t end2 = clock();

	// ��ָ�룬�ڴ����ڼ䲻��Ҫ���ж���Ŀ���---�������Ƕ���ĵ�ַ---32ƽ̨�¾���4���ֽ�
	size_t begin3 = clock();
	for (int i = 0; i < 100000; i++)
		TestPtr(&a);
	size_t end3 = clock();

	cout << "��ֵ���ܣ�" << end1 - begin1 << " ms" << endl;
	cout << "���������ܣ�" << end2 - begin2 << " ms" << endl;
	cout << "��ָ�����ܣ�" << end3 - begin3 << " ms" << endl;

	// ����1��������Ч�ʱȴ�ֵЧ�ʸ�
	// ---ע�⣺��C++�У������Զ������͵Ĳ���һ�㶼�ǰ������õķ�ʽ�����ݵ�T&  constT&

	// ����2�������úʹ�ָ���Ч�ʲ��
}

int main()
{
	TestFunc();
	return 0;
}
#endif




#if 0
// ���ÿ��Դﵽ��ָ�����Ƶ�Ч�������磺������ͨ���β����ı��ⲿ��ʵ��
// ���⣺ָ���������ʲô�����أ�
// �ڵײ�ʵ���ϣ����þ��ǰ���ָ�뷽ʽʵ�ֵ�
int main()
{
	int a = 10;

	int* pa = &a;
	*pa = 100;

	// ������Ϊ�˴�Һ���⣬���þ��Ǳ����������������õ�ʵ�干��ͬһ���ڴ�ռ䣬
	// ��������������ñ������¿����ڴ�ռ�

	// ʵ�ָ��м������������ڵײ��ǰ���ָ��ķ�ʽ��ʵ��

	// �û�д�Ĵ��룺���ձ����ڴ����е�ĳ���ļ���
	// ϵͳִ�еĴ��룺����Ԥ�������롢��ࡢ����--->���ɿ�ִ�г���(exe)
	// ���б���---�����������﷨�������룬���Ƿ��в������﷨���������
	//          ���û���д������з���
	// ������ʹ�õ�������
	// �������ڷ����ʱ�򣬽����ð���ָ��ķ�ʽ������
	// ��������������֮��Ĵ��룬������û������
	int& ra = a;
	ra = 100;

	return 0;
}
#endif




#if 0
void Swap(int& left, int &right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	Swap(&a, &b);
	Swap(a, b);

	return 0;
}
#endif




#if 0
int main()
{
	int* p;

	int a = 10;
	int& ra = a;
	ra++;   // ע�⣺�ڵײ㴦���ϣ����������ra�������ҵ�a


	int b = 20;

	p = &a;
	p++;   // ָ��ֻ��ָ��һ�������Ŀռ䣬++/--��������

	p = &b;

	int* const cp = &a;
	// pc = &b;

	char c = 'a';
	char* pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;  // 4  ��32ƽ̨�£��κ�ָ�붼ռ��4���ֽ�
	cout << sizeof(rc) << endl;  // 1  ��������ʵ�ʾ���������ʵ�����͵Ĵ�С


	// �ж༶ָ��
	int* p1 = NULL;
	int** p2 = NULL;
	int*** p3 = NULL;


	// û�ж༶����--->��ʵ��û�ж༶�����������
	int d = 10;
	int& rd = d;

	//int&& rrd = d;
	// ��ֵ����--->C++11
	int&& rrd = 10; // ������д��
	return 0;
}
#endif




#if 0
// ԭ��
// �ڵײ㣺void Swap(int* left, int* right)
//        {
//           int temp = *left;
//           *left = *right;
//           *right = temp;
//        }

void Swap(int& left, int &right)
{
	int temp = left;
	left = right;   // �������
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	int* pb = NULL;
	// *pb = 100;     // �Կ�ָ������ã�������ִ���ڼ������

	// �ڴ���ʱ���������ǰ���ֵ�ķ�ʽ���ݵ�
	// ���������ڱ������ʱ����⵽Swap�������������������͵�
	// �����Ѿ���Swap�����������������͵Ĳ���ת��Ϊָ��
	// ��ˣ�Swap(a, *pb)--->����ɣ�Swap(&a, pb);

	Swap(a, *pb);   //  ���Ǹ�λ�õĿ�ָ��pb������ʱȴû�б���
	return 0;
}
#endif




#if 1
//1. ��ӡʲô100 10
//2. ִ����ɺ�a��ֵ�Ƕ��٣�  100

// ע�⣺��C++�У���const���ε��Ѿ��ǳ��������Ҿ��к��滻�����ԣ������滻ʵ���ڳ������ʱ
// �꣺����Ԥ����׶η����滻---���뻹û�б���---Ԥ������ֱ���滻������������ͼ��---��ȫ�Բ���
// const���Σ����ڱ���׶ν����滻---����в������ͼ��---��ȫ�Ը�

// ��C++�У�������const���γ�������곣��--- 

/*
�곣����Ϊ��ʵ�ּ򵥣��ᶨ��һЩ�곣��
#define MAX_SIZE 100  �ڳ����������õ�100��λ�ö�����ʹ��MAX_SIZE�����棬�������ֲ�100�����ʣ�һ��ȫ��
#define PI 3.14  ������߳���Ŀɶ���

ע�⣺�곣������Ԥ����׶��������滻��  ����������ͼ��  ��ȫ�Ƚϵ�
*/

#define PI "3.1415"

const double pi = 3.14;//"3.14";

void TestFunc()
{
	int r = 2;
	//double s = PI * r * r;   // double s = "3.1415" * r * r;

	double s = pi * r * r;
	cout << s << endl;


	// Ҫ��֤��const���ε�a�Ƿ�Ϊ������������������������
	// ��Ϊ����������ʱ����Ҫ��������Ĵ�С��������Ĵ�С�����ǳ���
	// ����ɹ�����Ϊa��const���Σ�a��һ������
	// ע�⣺��C�����У���const���εı������ܽ����Ϊ�������Ծ���һ��������ֻ�����ñ������ܹ����޸�
	//      ����C�����У���const���εı����ǣ�һ�����ܱ��޸ĵı��������ܽ����Ϊ����
	const int a = 10;
	int array1[a];

	// ����ʧ�ܣ���Ϊb��һ������������������ʱ����Ҫһ��������ָ������Ĵ�С
	//int b = 10;
	//int array2[b];
}


int main()
{
	const int a = 10;

	int* pa = (int*)&a;
	*pa = 100;

	cout << *pa << endl;   // *pa===a
	printf("%d\n", 10/*a*/);  // �����������д������ձ����printf("%d\n", 10);  û��ֱ�Ӵ�a���ڵĿռ���ȡ���ݣ����ǽ�a�滻��10
	cout << a << endl;
	return 0;
}
#endif

