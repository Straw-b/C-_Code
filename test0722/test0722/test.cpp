#include <iostream>
using namespace std;



#if 1
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
int g_a = 0;
int& Add(int left, int right, int& ret)
{
	g_a = left + right;
	// return g_a;

	return ret;
}

int main()
{
	int r = 0;
	int& sum = Add(1, 2, r);
	Add(3, 4);
	Add(5, 6);
	return 0;
}
#endif
