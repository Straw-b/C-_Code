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




#if 1
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
