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

#if 0
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
#endif

#if 0
// ����
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a1;
	int a2 = 10;
	int a3(10);


	// ���󣺵�Date�ཫ���󴴽��ã��ö����о�Ҫ�г�ʼֵ
	Date d1;
	d1.SetDate(2020, 8, 1);  // Date::SetDate(&d, 2020,8,1)
	d1.PrintDate();

	Date d2(2020, 8, 1);   // ����d2���󲢶�����г�ʼ��--���캯��������ɶԶ���ĳ�ʼ������
	d2.PrintDate();
	return 0;
}

#endif


#if 0
class Date
{
public:
	// ���캯����һ������ĳ�Ա���������⣺
	// ���캯�������ֱ�����������ͬ
	// ���캯��û�з���ֵ���ͣ���ʹ��voidҲ����
	// ���캯�����ڴ�������ʱ�ɱ������Զ����е��ã������ڶ��������������ֻ����һ��
	// ���ã���Ҫ�Ǵ�������ʱ��ɶԵ�ǰ����ĳ�ʼ������
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		//return;   // return;����д����ʾ����û�з���һ��ʵ�ʵ����ݣ����������Ӹ�λ���˳�

		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	// d�����Ǻ����е�һ���ֲ��Ķ����ں����˳�ʱ�ö����Ҫ������
	// d�������������ź����Ľ���������
	Date d(2020, 8, 1);
	d.PrintDate();
}

int main()
{
	TestDate();

	Date d1(2020, 8, 1);  // ���ǲ�û����ʽ(�û�û��д�����ù��캯�������)���ù��캯��
	d1.PrintDate();
	return 0;
}
#endif

#if 0
// ���캯����������
class Date
{
public:
	// �ù��캯��ֻ�ܴ����������������Ķ��󣬲��ܴ����޲εĶ���
	Date(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 8, 1);   // call Date(2020, 8, 1)
	d1.PrintDate();

	Date d2(2020, 8, 2);

	Date d3;              // call Date()
	Date d4;
	Date d5;
	return 0;
}
#endif


#if 0
// ���һ����û����ʽ����(�û�д��)�κι��캯����������������һ��Ĭ�ϵĹ��캯����
// ע�⣺���������ɵĹ��캯��һ�����޲εģ��û�һ���������캯�����������Ͳ���������
class Date
{
public:
	Date(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	//Date()
	//{
	//	_year = 1900;
	//	_month = 1;
	//	_day = 1;
	//}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
	Date d2(2020, 8, 1);  // �ڴ�������ʱ��Ҫ����Date(int,int,int)
	return 0;
}
#endif


#if 0
// ȫȱʡ�Ĺ��캯�� �� �޲εĹ��캯��ͳ��Ϊ Ĭ�ϵĹ��캯��
// ���ң�ȫȱʡ�Ĺ��캯�� �� �޲εĹ��캯������ͬʱ����
class Date
{
public:
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		this->_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	// �޲εĹ��캯��
	//Date()
	//{
	//	_year = 1900;
	//	_month = 1;
	//	_day = 1;
	//}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
	Date d2(2020, 8, 1);
	return 0;
}
#endif


#if 0
// �û�û�ж��幹�캯��ʱ�������������޲εĹ��캯������ô���������ʼ����ʲôֵ�����������ֵ��
// ���������ɵ�Ĭ�Ϲ��캯���У�
// ���������������Ͷ���ĳ�Ա������ʼ��Ϊ���ֵ
// �������а������������Ͷ����Ա---���ó�Ա��Ӧ���Ĭ�Ϲ��캯������ʼ����
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;

		cout << "Time(int,int,int)" << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	// ����û�û����ʽ���幹�캯�����������Ż�����һ��Ĭ�ϵĹ��캯��
	// ע�⣺���������ɵĹ��캯��һ�����޲ε�

	// �Լ�д���캯�����������Ժ���Ҳ�����޸���
	// ��Date�๹�캯��ִ��ʱ������ת��Time�๹�캯��λ��ִ�У������������е�_t�Ķ����ʼ������
	// Ȼ����ִ��Date��Ĺ��캯�����_year\_month\_day�����и�ֵ
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;

	Time _t;
};


int main()
{
	// ��������������������һ��Ĭ�ϵĹ��캯��
	// �����ɵ�Ĭ�ϵĹ��캯���е�����Time��Ĺ��캯����Ŀ�ģ����������а�����Time��Ķ����ʼ�����
	Date d;   // call Time() // ����ñ��������ɵ�Ĭ�Ϲ��캯��(�޲�)   call Date()
	
	// Date dd(2020, 8, 1);  dd�����ڴ���ʱ����Ҫ���ô�������int���Ͳ����Ĺ��캯��
	                       // ���ù��캯���û���û���ṩ��������ֻ�������޲ε�Ĭ�Ϲ��캯��
	                       // ��ʾ����û�д�������int���͵Ĺ��캯��---dd����û�а취����--->����ʧ��
	return 0;
}
#endif


#if 0
#include <malloc.h>

typedef int DataType;

class SeqList
{
public:
	// �����ڴ���ʱ���������з�����(��Դ)
	SeqList(size_t capacity = 10)
	{
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		_capacity = capacity;
		_size = 0;
	}

	// �ڶ�������ʱ������Ҫ�������е���Դ�����
	// ��������
	// �ڶ�������ʱ���ɱ������Զ����е��ã�������������Դ������
	// ��������һ�����޲εģ����ܴ����κ����͵Ĳ���
	// �������������з���ֵ
	// һ����ֻ����һ����������
	~SeqList()
	{
		if (_array)
		{
			free(_array);
			_capacity = 0;
			_size = 0;
		}

		// return 0;
	}

	void PushBack(DataType data)
	{
		// ����
		_array[_size++] = data;
	}

	void PopBack()
	{
		if (Empty())
			return;

		--_size;
	}

	size_t Size()
	{
		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}

	bool Empty()
	{
		return _size == 0;
	}

	// ....
private:
	DataType* _array;
	size_t _capacity;
	size_t _size;
};


void TestSeqList()
{
	SeqList s;
	s.PushBack(1);
	s.PushBack(2);
	s.PushBack(3);
	s.PushBack(4);
	cout << s.Size() << endl;
	cout << s.Capacity() << endl;
}

int main()
{
	TestSeqList();
	return 0;
}
#endif

#include <malloc.h>
#include <string.h>


class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


void TestString()
{
	String s1;
	String s2("hello");
}


class Person
{
private:
	String _name;
	int _age;
};


void TestPerson()
{
	Person p;
	// �ڹ���Person����pʱ���ӻ������п�������������Person��������һ��Ĭ�ϵĹ��캯��
	// �����ɵ�Ĭ�Ϲ��캯���У���Ҫ������String��Ĺ��캯����Ŀ�ľ��Ƕ�p��������������String���͵�name
	// �����г�ʼ��
	// ע�⣺��989�в���ֱ�ӵ���call String(), ��Ϊ��989�д�������һ��Person���͵Ķ��󣬾�Ҫ����Person
	// �Ĺ��캯���������Person��������������String���͵�name�ĳ�ʼ����������˱�������Person������һ��Ĭ�ϵĹ��캯��


	// ��P��������ʱ����Ϊp�����а�����String���͵�name��name�й�����Դ����˱���Ҫ����String�����������
	// ���p��������������String���͵�name����Դ������
	// �����ں����˳�ʱ������ֱ�ӵ���String���������������Ϊ������������Person��Ķ���ֱ�ӵ���String���������������ͨ
	// �����Ǹ���Ķ��󣬵����Ǹ������������
	// ��ˣ���������Person��������һ��Ĭ�ϵ�������������Ĭ�ϵ����������е���String����������������p��������������String����name����Դ������
	/*
	��������Person�����ɵ���������
	~Person()
	{
	    call ~String();  // ����Person������а�����String���ͳ�Աname�е���Դ
	}
	*/
}

int main()
{
	TestPerson();
	TestString();
	return 0;
}