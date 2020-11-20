#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
#include <string>

// ����/����
class Person
{
public:
	void Eat()
	{
		cout << "�Է�" << endl;
	}

	void Sleep()
	{
		cout << "˯��" << endl;
	}

private:
	string _name;
	string _gender;
	int _age;
};

// ������/����
class Student : public Person
{
public:
	void Study()
	{
		cout << "ѧϰ" << endl;
	}

private:
	int _stuid;
};

int main()
{
	Student s;
	s.Eat();
	s.Sleep();
	s.Study();

	cout << sizeof(Student) << endl; // 28+28+4+4=64
	return 0;
}
#endif





#if 0
#include <string>

class Person
{
public:
	void Eat()
	{
		cout << "�Է�" << endl;
	}

	void Sleep()
	{
		cout << "˯��" << endl;
	}

private:
	// �Ȳ���������ֱ��ʹ��
	// Ҳ��������������ֱ��ʹ��
	string _name;
	string _gender;

protected:
	// ����������ֱ��ʹ��
	// ���ǿ�����������ʹ��
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		// ������protected��Ա�������п���ֱ��ʹ�ã�Ȩ�ޣ�protected
		_age = 18;

		// ������private���εĳ�Ա�������в��ɼ�(����ֱ��ʹ��)
		//_name = "lily";
		cout << "ѧϰ" << endl;
	}

private:
	int _stuid;
};

class A : public Student
{
public:
	void Test()
	{
		_age = 10;
	}
};

int main()
{
	Student s;

	// ����public��Ա�������еķ���Ȩ��Ҳ��public
	s.Eat();
	s.Sleep();

	//s._age = 10;
	cout << sizeof(Student) << endl;
	return 0;
}
#endif





#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : protected Base
{
public:
	void test()
	{
		// ������public���γ�Ա�������е�Ȩ�ޱ��protected
		_pub = 10;

		// ������protected���εĳ�Ա�������е�Ȩ��Ҳ��protected
		_pro = 10;

		// ������privage���εĳ�Ա�������в��ɼ�
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 20;
		_pro = 30;
	}
};

int main()
{
	Derive d;
	//d._pub = 10;
	return 0;
}
#endif





#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

class Derive : private Base
{
public:
	void test()
	{
		// ������public���γ�Ա�������е�Ȩ�ޱ��private
		_pub = 10;

		// ������protected���εĳ�Ա�������е�Ȩ��Ҳ��private
		_pro = 10;

		// ������privage���εĳ�Ա�������в��ɼ�
		//_pri = 10;
	}
};

class A : public Derive
{
public:
	void test()
	{
		//_pub = 20;
		//_pro = 30;
	}
};

int main()
{
	Derive d;
	//d._pub = 10;
	return 0;
}
#endif





#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};

// classĬ�ϼ̳з�ʽ��private
// structĬ�ϼ̳з�ʽ��struct
struct Derive : Base
{
public:
	void test()
	{
		_pub = 10;
		_pro = 20;
		//_pri = 30;
	}
};

class A : public Derive
{
public:
	void test()
	{
		_pub = 20;
		_pro = 30;
	}
};

int main()
{
	Derive d;
	d._pub = 1;
	return 0;
}
#endif





// ��ֵ���ݹ���---ǰ�᣺������public�̳з�ʽ
// 1. ���������Ը��������ֵ������������
// 2. ����ֵָ��������ÿ���ֱ��ָ������Ķ���
// 3. �����ָ�벻��ֱ��ָ�����Ķ���

//�����public�ļ̳з�ʽ��
//����ͻ���Ĺ�ϵ��is-a(��һ��) ���Խ�������󿴳���һ���������
//����ģ�ͣ������г�Ա���ڴ��еķֲ���ʽ
#if 0
class Person
{
public:
	void Eat()
	{
		cout << "�Է�" << endl;
	}

	void Sleep()
	{
		cout << "˯��" << endl;
	}

	string _name;
	string _gender;
	int _age;
};

class Student : public Person
{
public:
	void Study()
	{
		cout << "ѧϰ" << endl;
	}

	int _stuid;
};

int main()
{
	// 1. ���������Ը��������ֵ������������
	Person p;
	Student s;
	p = s;
	// s = p;

	// 2. ����ֵָ��������ÿ���ֱ��ָ������Ķ���
	Person* pp = &s;
	Person& rp = s;

	// 3. �����ָ�벻��ֱ��ָ�����Ķ���,����ǿת����---����ȫ
	// Student* ps = &p;
	Student* ps = (Student*)&p;
	ps->_name = "lily";
	ps->_gender = "��";
	ps->_age = 18;
	//ps->_stuid = 100; // ������Խ�����
	return 0;
}
#endif





#if 1
class Base
{
public:
	void Set(int b) //���̳�����
	{
		_b = 10;
	}

private:
	int _b;
};

class Derive : public Base
{
public:
	void Set() //���̳�����
	{
		Base::Set(10);
		__super::Set(10);
		_d = 100;
	}
private:
	int _d;
};

int main()
{
	Derive d;
	d.Base::Set(10);
	return 0;
}
#endif