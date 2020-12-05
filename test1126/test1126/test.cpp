#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


#if 0
class B
{
public:
	int _b;
};

// ����̳�
class D : virtual public B
{
public:
	D()
	{
		cout << "D()" << endl;
	}

	int _d;
};

int main()
{
	D  d; // ���������޸Ĺ��캯��
	return 0;
}
#endif




#if 0
class B
{
public:
	void f()
	{}

	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl; // 24���ֽ�

	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;
	d.f(); // �����������ѽ��

	C1& c1 = d;
	c1._c1 = 5;
	c1._b = 6;

	C2& c2 = d;
	c2._c2 = 7;
	c2._b = 8;

	char* str = "hello";
	str[0] = 'H';

	int* p = (int*)(*(int*)&d);
	++p;
	(*p) = 100;

	return 0;
}
#endif




#if 0
class B
{
public:
	void f()
	{}

	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

class E : virtual public D
{
public:
	int _e;
};

int main()
{
	cout << sizeof(E) << endl;
	E e;
	e._c1 = 1;
	e._c2 = 2;
	e._d = 3;
	e._b = 4;
	e._e = 5;

	return 0;
}
#endif




/////////////////////////////////////////////////��̬

#if 0
// ��ͨ��
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "ȫ��Ʊ" << endl;
	}

protected:
	string _name;
	string _gender;
	int _age;
};

class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "���Ʊ" << endl;
	}

protected:
	int _stuID;
};

class Soldier : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "���Ʊ" << endl;
	}

protected:
	int _solID;
};

// ����ֻ��һ�ݣ������������Ľ��ȴ��ͬ

//void TestBuyTicket(Person& p)
//{
//	p.BuyTicket(); //����
//}
//int main()
//{
//	Person p;
//	Student stu;
//	Soldier sol;
//
//	TestBuyTicket(p);
//	TestBuyTicket(stu);
//	TestBuyTicket(sol);
//	return 0;
//}

void TestBuyTicket(Person* p)
{
	p->BuyTicket(); //ָ��
}
int main()
{
	Person p;
	Student stu;
	Soldier sol;

	TestBuyTicket(&p);
	TestBuyTicket(&stu);
	TestBuyTicket(&sol);
	return 0;
}
#endif




#if 0
class A{};
class B : public A{};

class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2(int a)
	{
		cout << "Base::TestFunc2()" << endl;
	}

	//virtual void TestFunc3()
	//{
	//    cout << "Base::TestFunc3()" << endl;
	//}

	virtual A* TestFunc4() // Э��
	{
		cout << "Base::TestFunc4()" << endl;
		return nullptr;
	}
};

class Derived :public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	// ����ֵ���Ͳ�ͬ�����ܹ�����д
	//virtual int TestFunc3()
	//{
	//    cout << "Derived::TestFunc3()" << endl;
	//    return 0;
	//}

	virtual B* TestFunc4() // Э��
	{
		cout << "Derived::TestFunc4()" << endl;
		return nullptr;
	}
};

void TestDynamic(Base* pb)
{
	pb->TestFunc1();

	// �ڱ���׶Σ�������ֻ�Ὣpb���ɻ����ָ�봦��
	// ��ˣ�pbֻ�ܵ��û���ĳ�Ա����
	pb->TestFunc2(10);
	//pb->TestFunc3();

	pb->TestFunc4();
}

int main()
{
	Base b;
	Derived d;
	TestDynamic(&b);
	TestDynamic(&d);
	return 0;
}
#endif




#if 0
class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

    virtual ~Base()
	{
		cout << "~Base()" << endl;
	}

	int _b;
};

class Derived: public Base
{
public:
	Derived()
	{
		pb = new int[10];
		cout << "Derived()" << endl;
	}

	~Derived() // �������������Ի���������������д
	{
		if (pb)
		{
			delete[] pb;
			pb = nullptr;
			cout << "~Derived()" << endl;
		}
	}
	int *pb;
};

int main()
{
	Base* pb = new Derived;
	delete pb;
	return 0;
}
#endif





#if 1
class A{};
class B : public A{};

class Base
{
public:
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}
};

class Derived :public Base
{
private:
	virtual void TestFunc() // ����Ȩ�޿��Բ�ͬ
	{
		cout << "Derived::TestFunc()" << endl;
	}
};

void TestDynamic(Base* pb)
{
	pb->TestFunc();
}

int main()
{
	Base b;
	Derived d;
	TestDynamic(&b);
	TestDynamic(&d);
	return 0;
}
#endif

