#include <iostream>
using namespace std;



// ���캯���﷨��˵�����캯��û�з���ֵ����
// ���캯�������з���ֵ��

class Test
{
public:
	Test(int t)
		: _t(t)
	{
		cout << "Test(int):" << this << " " << _t << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << " " << _t << endl;
	}

	int _t;
};


int test1()
{
	return 10;
}

void test2()
{}

int main()
{
	int a = 10;
	a = test1();   //test1()�����з���ֵ����˿��Է���=���Ҳ�
	// a = test2();  test2()����û�з���ֵ����Ȼû�з���ֵ���䲻�ܳ�����=���Ҳ�

	Test t1(10);

	// ��Ȼ���캯���Ϳ������캯�����Է���=���Ҳ࣬��֤������Ϳ������캯�����з���ֵ��
	// ���캯���Ϳ������캯�����ص��Ƕ��������
	t1 = Test(20);  // ���ù��캯������
	t1 = Test(t1);  // ���ÿ�������

	return 0;
}