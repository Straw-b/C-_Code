#include <iostream>
using namespace std;


#if 0
// Student���俴����һ��ѧ��Ⱥ������
struct Student
{
	// ���ԣ���������ѧ���Ļ�����Ϣ��
	char _name[20];
	char _gender[3];
	int  _age;
	char _school[20];

	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
		strcpy(_school, school);
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
	}

	// ��Ϊ��ѧ������ɶ
	// �Է���˯�����ϿΡ�д��ҵ�����ԡ����---����һ�㶼��ͨ���������ֵ�
	void Eat()
	{
		cout << "�ú÷��Գ�����" << endl;
	}

	void Sleep()
	{
		cout << "ZZZ~~~" << endl;
	}

	void Exam()
	{
		cout << "����" << endl;
	}
};

int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("�ܴ�", "��", 5, "������԰");
	s2.SetStudentInfo("�ܶ�", "ĸ", 4, "������԰");
	s3.SetStudentInfo("ǿ��", "��", 28, "ɭ�ִ�ѧ");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();
	return 0;
}
#endif

#if 0
class Student
{
protected:
	// ���ԣ���������ѧ���Ļ�����Ϣ��
	char _name[20];
	char _gender[3];
	int  _age;
	char _school[20];

public:
	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
		strcpy(_school, school);
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
	}

	// ��Ϊ��ѧ������ɶ
	// �Է���˯�����ϿΡ�д��ҵ�����ԡ����---����һ�㶼��ͨ���������ֵ�
	void Eat()
	{
		cout << "�ú÷��Գ�����" << endl;
	}

	void Sleep()
	{
		cout << "ZZZ~~~" << endl;
	}

	void Exam()
	{
		cout << "����" << endl;
	}
};

int main()
{
	Student s1, s2, s3;
	s1.SetStudentInfo("�ܴ�", "��", 5, "������԰");
	s2.SetStudentInfo("�ܶ�", "ĸ", 4, "������԰");
	s3.SetStudentInfo("ǿ��", "��", 28, "ɭ�ִ�ѧ");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	s1._age = 10;
	return 0;
}
#endif

#if 0
// C++��4�������򣺺������еľֲ�������ȫ�������������ռ䡢��
void TestFunc()
{}

namespace N
{
	void TestFunc(int a)
	{}
}

class Test
{
public:
	void TestFunc(double d)
	{}
};
#endif


#if 0
// ���еĳ�Ա������ֻ�������Ա������ʹ�ã���Ա�����൱�������Ա������ȫ�ֱ���

class Test
{
public:
	void SetTest(int a)
	{
		_a = a;
		cout << &_a << endl;
	}

	void PrintTest()
	{
		cout << _a << endl;
		cout << &_a << endl;
	}

private:
	int _a;   // �ó�Ա�������ȿ�����SetTest������ʹ�ã�Ҳ������PrintTest������ʹ��
	          // ��ˣ���Ա�����Ϳ��Կ��������Ա������ȫ�ֱ���
};


// ע�⣺��Ա�����Ϳ��Կ��������Ա������ȫ�ֱ���---���Ǻ�������ȫ�ֱ�������������
//      ȫ����ʹ��֮ǰ������Ҫ���ж���



void TestFunc()
{
	cout << g_a << endl;
}

int g_a = 10;

int main()
{
	Test t;
	t.SetTest(10);
	t.PrintTest();

	cout << g_a << endl;
	return 0;
}
#endif


#if 0
// ������һ��ѧ����
// ע�����֣�ѧ����������ѧ����һ��Ⱥ�����𣬿��Խ�ѧ���࿴����һ���µ����ͣ���ѧ������ͬ
//          ��   ����
//         int   a
class Student
{
public:
	// ���ԣ���������ѧ���Ļ�����Ϣ��
	char _name[20];
	char _gender[3];
	int  _age;
	char _school[20];

public:
	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
		strcpy(_school, school);
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << "-" << _school << endl;
	}

	// ��Ϊ��ѧ������ɶ
	// �Է���˯�����ϿΡ�д��ҵ�����ԡ����---����һ�㶼��ͨ���������ֵ�
	void Eat()
	{
		cout << "�ú÷��Գ�����" << endl;
	}

	void Sleep()
	{
		cout << "ZZZ~~~" << endl;
	}

	void Exam()
	{
		cout << "����" << endl;
	}
};

int main()
{
	/*
	����������ʧ�ܣ���ΪStudent��һ��ѧ���������
	ѧ��Ⱥ����𣺾�������---����û������һ˵
	ͨ��ѧ������ ���������ѧ��ʵ��(ѧ��������������һ��ѧ��)����һ��������ѧ���������֡��Ա�����
	*/
	//Student._age = 10;

	Student s;  // s������ʵ�����Ľ����s����һ��������ѧ��
	s._age = 10;

	return 0;
}
#endif


#if 0
class Student
{
public:
	void SetStudentInfo(char name[], char gender[], int age, char school[])
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

public:
	// ���ԣ���������ѧ���Ļ�����Ϣ��
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1,s2,s3;

	// Ҫ���Student������ж������Ҫ֪�������ж���������Щ��Ա
	s1.SetStudentInfo("�ܴ�", "��", 5, "������԰");
	s2.SetStudentInfo("�ܶ�", "ĸ", 4, "������԰");
	s3.SetStudentInfo("ǿ��", "��", 28, "ɭ�ִ�ѧ");

	s1.PrintStudentInfo();
	s2.PrintStudentInfo();

	cout << sizeof(s1) << endl;
	return 0;
}
#endif










#if 0
class A1 
{
public:
	void f1(){}
private:
	int _a;
	char _b;
};

// ���н��г�Ա����
class A2 
{
public:
	void f2() {}
};


// ����ʲô��û��---����
// �﷨֧�ָ����࣬���Ǹ���û��ʵ������
// ע�⣺����Ҳ��һ���࣬���Զ��������
class A3
{};

struct A
{
	int a;
	char b;
	double c;
	char d;
};

int main()
{
	cout << sizeof(A1) << endl;

	cout << sizeof(A2) << endl;   // ��Ϊ����û�г�Ա�����������ϴ�СӦ����0�Ŷ�-->����ʵ�ʽ����С��1
	cout << sizeof(A3) << endl;   // ��Ϊ����û�г�Ա�����������ϴ�СӦ����0�Ŷ�-->����ʵ�ʽ����С��1

	A3 a1, a2, a3;
	cout << &a1 << " " << &a2 << " " <<&a3<< endl;

	cout << offsetof(A, b) << endl;
	cout << offsetof(A, c) << endl;
	return 0;
}
#endif

#if 0

// ע�⣺��C++�У��۾������Ĳ�һ���������----���������ڴ����͵͵�����޸�
// ���£��о�C++�Ƚ���ѧ��C++ѧ����

// ÿ����"��Ա����"����һ��Ĭ�ϵĲ������ò���ʱʱ�̿�ָ����øó�Ա�����Ķ��󣬽��ò�����Ϊthisָ��
// ע�⣺�����ص�thisָ���Ǳ������ڱ�������ڼ��Զ����ϵ�,����û�����Ҫ��ӣ�Ҳ����Ҫ����

class Student
{
public:
	void SetStudentInfo(/*Student* const this,*/char name[], char gender[], int age);
// 	{
// 		// this = nullptr;  thisָ��ָ�����޸ĵ�
// 		cout << this << endl;
// 		strcpy(this->_name, name);
// 		strcpy(this->_gender, gender);
// 		this->_age = age;
// 	}

	void PrintStudentInfo(/*Student* const this*/)
	{
		cout << this->_name << "-" << this->_gender << "-" << this->_age << endl;
	}

	void TestFunc(...);   // ...��ʾ��������
	//{}

public:
	// ���ԣ���������ѧ���Ļ�����Ϣ��
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	Student s1, s2, s3;

	// thisָ��û�а����ڶ����У���Ӱ�����Ĵ�С�����Ǳ���������Ա�������ӵ�һ���������ֲ�ͬ�����ָ�����
	cout << sizeof(s1) << endl;

	// �������thisֻ����"��Ա������ʹ��"����Ϊthisָ���Ǳ����������"��Ա����"���ӵ�һ��ָ�룬�ø�ָ�������ֲ�ͬ�Ķ�����
	// cout << this << endl;

	// Ҫ���Student������ж������Ҫ֪�������ж���������Щ��Ա
	cout << &s1 << endl;
	s1.SetStudentInfo(/*&s1,*/"�ܴ�", "��", 5);

	cout << &s2 << endl;
	s2.SetStudentInfo(/*&s2,*/"�ܶ�", "ĸ", 4);

	// thisָ��Ĵ��ݷ�ʽ��
	// 1. �ò������б��������ݵ�
	// 2. һ������ò�����ͨ��ecx�Ĵ��������ݵ�
	// ע�⣺һ������³�Ա�������Ǳ�this_call����Լ�����Σ�����this_call����Լ�����εĳ�Ա����
	//      thisָ����ͨ��ecx�Ĵ�������, ��_cdecl����Լ�����εĳ�Ա������this��ͨ������ѹջ�ķ�ʽ����
	cout << &s3 << endl;
	s3.SetStudentInfo(/*&s3,*/"ǿ��", "��", 28);
	// 3. ���������ͨ������ѹջ�ķ�ʽ����
	s3.TestFunc();

	s1.PrintStudentInfo(/*&s1,*/);
	s2.PrintStudentInfo(/*&s2,*/);

	cout << sizeof(s1) << endl;
	return 0;
}

/*
�������û�д�Ĵ��룬�������������޸�֮�󣬴���ͱ��
// ��C�����У����Ǵ�����ôд������������ô�����������Դ�������κ��޸�--�㿴���ľ��Ǳ�����ִ�е�
// ��C������ģ��ʱ����������
struct Student
{
	char name[20];
	char gender[3];
	int age;
};


// Ҫ��name��gender��age�������õ�psָ���ѧ����Ϣ��
void SetStudentInfo(Student* this, char name[], char gender[], int age)
{
	strcpy(this->name, name);
	strcpy(this->gender, gender);
	this->age = age;
}

// ��ӡpsָ���ѧ��
void PrintSutdentInfo(Student* this)
{
	printf("%s %s %d", this->name, this->gender, this->age);
}

int main()
{
	Student s1, s2, s3;
	SetStudentInfo(&s1, "�ܴ�", "��", 5);
	SetStudentInfo(&s2, "�ܶ�", "ĸ", 4);
	SetStudentInfo(&s3, "ǿ��", "��", 28);

	PrintSutdentInfo(&s1);
	PrintSutdentInfo(&s2);
	PrintSutdentInfo(&s3);
	return 0;
}
*/
#endif


#if 0
// ��C�����У����Ǵ�����ôд������������ô�����������Դ�������κ��޸�--�㿴���ľ��Ǳ�����ִ�е�
// ��C������ģ��ʱ����������
struct Student
{
	char name[20];
	char gender[3];
	int age;
};


// Ҫ��name��gender��age�������õ�psָ���ѧ����Ϣ��
void SetStudentInfo(Student* ps, char name[], char gender[], int age)
{
	strcpy(ps->name, name);
	strcpy(ps->gender, gender);
	ps->age = age;
}

// ��ӡpsָ���ѧ��
void PrintSutdentInfo(Student* ps)
{
	printf("%s %s %d", ps->name, ps->gender, ps->age);
}

int main()
{
	Student s1, s2, s3;
	SetStudentInfo(&s1, "�ܴ�", "��", 5);
	SetStudentInfo(&s2, "�ܶ�", "ĸ", 4);
	SetStudentInfo(&s3, "ǿ��", "��", 28);

	PrintSutdentInfo(&s1);
	PrintSutdentInfo(&s2);
	PrintSutdentInfo(&s3);
	return 0;
}
#endif


/*
��Ա�������Կ����ǳ�Ա������ȫ�ֱ���
���⣺����ǰ֪ʶ--->ȫ�ֱ���������������ʹ�ã��������Ա�����������£�Ϊʲô��������֮ǰ�ĳ�Ա������ʹ���أ�


�������������ô�����ࣿ-----����18���ˣ����������ͬѧ/���Ѹ��ҽ���һ��Ů����
1. ʶ������
2. ʶ�����г�Ա����
3. ʶ�����еĳ�Ա����&�Գ�Ա�������и�д
*/
class Student
{
public:
	/*
	void SetStudentInfo(Student* const this, char name[], char gender[], int age)
	{
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	*/
	void SetStudentInfo(char name[], char gender[], int age)
	{
	    strcpy(_name, name);
	 	strcpy(_gender, gender);
	 	_age = age;
	}

	/*
	void PrintStudentInfo()
	{
	    cout << this->_name << "-" << this->_gender << "-" << this->_age << endl;
	}
	*/
	void PrintStudentInfo()
	{
		cout << _name << "-" << _gender << "-" << _age << endl;
	}

public:
	char _name[20];
	char _gender[3];
	int  _age;
};

int main()
{
	return 0;
}
