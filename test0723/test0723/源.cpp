#include <iostream>
using namespace std;







#if 0
// C��������auto�Ĺؼ���
// auto�ؼ���ר���������κ����ж���ı������������ñ���Ϊ�Զ��洢���͵ı��������ñ����ᱻ�Զ����ٵ�

// ���C++11�У��ϳ���auto��C�����е����ã���ȫ�µĺ���:
//   auto������һ���洢����ָʾ����������Ϊһ���µ�����
//   ָʾ����ָʾ��������auto�����ı��������ɱ������ڱ���ʱ���Ƶ�����������


int Add(int left, int right)
{
	return left + right;
}

int main()
{
	// auto int a = 10;  // �ֲ����������ֲ������ں�������ʱ�����ͻ��Զ�����

	auto a = 10;
	auto b = "1234";
	auto c = 12.34;

	// ע�⣺auto��������
	// auto��ʱֻ��һ��ռλ��
	// �ڱ���������ʱ������������d�ĳ�ʼ�����ʽa+10������Ϊint��������int�滻d֮ǰ��auto
	auto d = a + 10;   // ������������ɺ�  auto d = a + 10;--->int d = a+10;
	// cout << sizeof(auto) << endl;

	auto ret = Add(10, 20);
	cout << typeid(ret).name() << endl;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;


	// ����auto�������ʱ������Ա������г�ʼ��
	// ��Ϊ���������ڱ����ڼ䣬Ҫ���ݱ����ĳ�ʼ�����ʽ�����ݸñ�����ʵ������
	// ����ʵ���������ݳ���֮���滻auto
	// auto e;
	return 0;
}
#endif



#if 0
void TestAuto1()
{
	auto a = 10;

	// ʹ��auto����ָ�����ͱ���ʱ���Ӳ���*������ν
	auto pa = &a;   // auto---> �滻Ϊint*
	auto *pb = &a;  // auto---> �滻Ϊint
	cout << typeid(pa).name() << endl;
	cout << typeid(pb).name() << endl;

	// ע�⣺auto�����������ͱ���ʱ��auto֮�����Ҫ&
	auto& ra = a;   // ��ra����a
	auto rra = a;   // ע�⣺rra������a�����ã�ֻ�Ƕ�����һ��rra�ı������ñ���ʹ��a�����г�ʼ����

	cout << &a << endl;
	cout << &ra << endl;
	cout << &rra << endl;
}

void TestAuto2()
{
	// ʹ��auto��һ�ж���������ʱ��ÿ�������ĳ�ʼ�����ʽ�����ͱ���һ��
	auto a = 1, b = 2, c = a + b;

	// ������������auto��ʵ������ʱ��
	// 12.34--->double auto Ӧ��Ϊdouble
	// 10--->int  autoӦ��Ϊint����
	// �������壺���������ھͲ�֪��auto������Ӧ�ø���int�����ػ���Ӧ�ø���double���ͣ������ڶ�����
	//auto d = 12.34, e = 10;

}


// ע�⣺auto�����������������Ĳ���
// ��Ϊ�����Ĳ����ڶ���û�г�ʼ������Ȼû�г�ʼ����������Ҳ�޷������βε�ʵ������
// ����auto�����β�ʱ������ȱʡֵ֮��ΪʲôҲ���У�
// ԭ����Ϊ�������к����Ĳ�������Ĭ��ֵ
void TestAutoParam(auto a = 10)
{
	a++;
}

void TestAutoArray()
{
	int array0[10];
	int array1[] = { 1, 2, 3 };   // array1��һ�����ε����飬�������3��Ԫ��
	int array2[10] = { 1, 2, 3 }; // array2��һ�����ε����飬�������10��Ԫ�أ�ǰ����Ԫ��Ϊ1 2 3������Ԫ��Ϊ0


	// ע�⣺auto����������������
	auto array4[] = { 1, 2, 3 };
}

int main()
{
	TestAuto1();
	return 0;
}
#endif



#if 0
int main()
{
	// [array, array+sizeof(array)/sizeof(array[0]))
	// ���⣺��Ȼ���鶨�����֮������ķ�Χ��ȷ����
	// ��ô�û��ڷ�������������߶�����������в���ʱ���ܷ��ø���Χ���ñ������Լ�����ȷ��
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// ��ӡ�����е�Ԫ��
	// ��һ����̫�õĵ㣺
	// �ڶ��������ʱ������Ҫ�����û���ȷ������ķ�Χ
	// ���ǣ����鶨�����֮�󣬷�Χ����ȷ����
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i] << " ";
	cout << endl;

	// ��������ÿ��Ԫ��*2
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	cout << endl;

	// ��ӡ�����Ԫ��
	for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << " ";
	cout << endl;

	return 0;
}
#endif


#if 0
// ��Ϊ��������Ϊ�����Ĳ���ʱ��ʵ���Ѿ��˻���һ��ָ����
void TestFor(int array[])  // void TestFor(int* array)
{
	for (auto e : array)   // array��ʾ�Ŀռ�ķ�Χ��ȷ��
		cout << e << " ";
	cout << endl;
}

// ��Χforѭ�� + ���auto
int main()
{
	// [array, array+sizeof(array)/sizeof(array[0]))
	// ��ô�û��ڷ�������������߶�����������в���ʱ���ܷ��ø���Χ���ñ������Լ�����ȷ��
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	// ��ӡ����--e:ʵ�ʾ���array������ÿ��Ԫ�ص�һ�ݿ���
	for (auto e : array)
	{
		// e *= 2; ֻ��Ϊ����֤e�ı�֮�������еĶ�ӦԪ���Ƿ����ı�--->��֤e�Ƿ�Ϊ������ÿ��Ԫ�صĿ���
		cout << e << " ";
	}
	cout << endl;

	// ��������ÿ��Ԫ�س�2�Ĳ���
	// e����������ÿ��Ԫ�صı���
	for (auto& e : array)
		e *= 2;
	cout << endl;

	for (auto& e : array)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif