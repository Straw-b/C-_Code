#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��ͨƱ" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "���Ʊ" << endl;
	}
};

// �ڱ���׶Σ��������޷�ȷ������Ҫ�����Ǹ�����麯��
// ֻ���ڳ�������ʱ��֪��pbָ���Ǹ���Ķ���Ȼ����ö�Ӧ������麯��
void TestVirtual(Person* pb)
{
	pb->BuyTicket();   // call Base::BuyTicket()
}

int main()
{
	Person p;
	Student s;
	TestVirtual(&p);
	TestVirtual(&s);
	return 0;
}
#endif




#if 0
class A
{
public:
	A(int a)
		: _a(a)
	{}

	virtual ~A()
	{
		cout << "~A()" << endl;
	}

protected:
	int _a;
};

class B : public A
{
public:
	B(int a, int b)
		: A(a)
		, _b(b)
	{
		_p = new int[10];
	}

private:
	~B()
	{
		delete[] _p;
		cout << "~B()" << endl;
	}

protected:
	int _b;
	int* _p;
};

int main()
{
	A* pa = new B(1, 2);

	// �����̬������û����ȫ���㣬����ʵ�ֶ�̬
	// �����������ڱ�������ڼ䣬��֪������Ҫ�����Ǹ�����
	delete pa;
	pa = nullptr;

	return 0;
}
#endif




#if 0
// override: ��������Ƿ񽫻����麯����д�ɹ�
class Base
{
public:
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}

	virtual void f1() /*final*/
	{
		cout << "Base::f1()" << endl;
	}
};

// Derived��˵��f1()�麯�����������ҵ�������д��
class Derived : public Base
{
public:
	virtual void TestFunc() override
	{
		cout << "Derived::TestFunc()" << endl;
	}

	virtual void f1() /*final*/
	{
		cout << "Derived::f1()" << endl;
	}
};

class D : public Derived
{
public:
	/*virtual void f1()
	{
	cout << "D::f1()" << endl;
	}*/
};

void TestVirtual(Base& b)
{
	b.TestFunc();
}

int main()
{
	Base b;
	Derived d;
	TestVirtual(b);
	TestVirtual(d);
	return 0;
}
#endif




#if 0
// A ���ü̳�
class A final
{
public:
	A(int a)
		: _a(a)
	{}

protected:
	int _a;
};

class B : public A
{};

#endif




#if 0
// A ���ü̳�
class A
{
public:
	static A* GetIntrance(int a) // ��̬�Ĺ��г�Ա����
	{
		return new A(a);
	}

	static void Destroy(A* pa)
	{
		delete pa;
	}

private:
	A(int a) // ���캯��˽�л�
		: _a(a)
	{}

protected:
	int _a;
};

//class B : public A
//{
//public:
//	B(int a, int b)
//		: A(a)
//		, _b(b)
//	{}
//
//protected:
//	int _b;
//};

int main()
{
	A* pa = A::GetIntrance(1);
	A::Destroy(pa);
	return 0;
}
#endif





#if 0
class Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual Base* f2()
	{
		cout << "Base::f2()" << endl;
		return this;
	}

	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}

	void f4()
	{
		cout << "Base::f4()" << endl;
	}

	void f5()
	{
		cout << "Base::f5()" << endl;
	}

	virtual int f6()
	{
		cout << "Base::f6()" << endl;
		return 0;
	}

	int f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}
};

class Derived : public Base
{
public:
	///////////////////////////////////// ��д
	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual Derived* f2()
	{
		cout << "Derived::f2()" << endl;
		return this;
	}

	///////////////////////////////////// ͬ������
	virtual void f3(int)
	{
		cout << "Derived::f3(int)" << endl;
	}

	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	void f5()
	{
		cout << "Derived::f5()" << endl;
	}

	char f7()
	{
		cout << "Base::f7()" << endl;
		return 0;
	}

	/////////////////////////////////// ����ʧ�ܣ���Ϊû�й���Э��
	//virtual char f6()
	//{
	//	cout << "Derived::f6()" << endl;
	//	return 0;
	//}
};
#endif




#if 0
#include <windows.h>

class WashRoom
{
public:
	void ManWC()
	{
		cout << "go to left" << endl;
	}

	void WomanWC()
	{
		cout << "go to right" << endl;
	}
};

// ������
class Person
{
public:
	virtual void GotoWC(WashRoom& wc) = 0; // ���麯��
};

// ��������һ��Ҫ���̳е�
// ����̳�һ��������֮�����û����д����Ĵ��麯����������Ҳ�ǳ�����
class Man : public Person
{
public:
	virtual void GotoWC(WashRoom& wc) //��д
	{
		wc.ManWC();
	}
};

class Woman : public Person
{
public:
	virtual void GotoWC(WashRoom& wc) //��д
	{
		wc.WomanWC();
	}
};

void TestWC()
{
	Person* p = nullptr;
	WashRoom wr;
	for (size_t i = 0; i < 10; ++i)
	{
		if (rand() % 2 == 0)
		{
			p = new Man;
		}
		else
		{
			p = new Woman;
		}

		p->GotoWC(wr);
		delete p;

		Sleep(1000);
	}
}

int main()
{
	// Person p;  ����ʧ�ܣ������಻��ʵ��������
	// Man m;
	TestWC();
	return 0;
}
#endif




#if 1
class  Base
{
public:
	virtual void f1()
	{
		cout << "Base::f1()" << endl;
	}

	virtual void f2()
	{
		cout << "Base::f2()" << endl;
	}

	virtual void f3()
	{
		cout << "Base::f3()" << endl;
	}
	int _b;
};

class Derived :public Base
{
public:
	virtual void f4()
	{
		cout << "Derived::f4()" << endl;
	}

	virtual void f1()
	{
		cout << "Derived::f1()" << endl;
	}

	virtual void f3()
	{
		cout << "Derived::f3()" << endl;
	}

	virtual void f5()
	{
		cout << "Derived::f5()" << endl;
	}
	int _d;
};


#include <string>

typedef void(*PVF)();

void PrintfVFT(Base& b, const string& info)
{
	PVF* pVFT = (PVF*)(*(int*)(&b));
	//pVFT[0]();
	cout << info << endl;
	while (*pVFT)
	{
		//*pVFT = nullptr; // ����е����ݲ������޸�

		(*pVFT)();
		++pVFT;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(Base) << endl;

	Base b, b1, b2;
	b._b = 1;
	PrintfVFT(b, "Base virtual function table:");

	Derived d;
	d._b = 1;
	d._d = 2;
	PrintfVFT(d, "Derived virtual function table:");
	return 0;
}
#endif
