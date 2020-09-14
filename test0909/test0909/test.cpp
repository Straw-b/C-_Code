#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 1
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1) // ���캯��
	{
		_year = year;
		_month = month;
		_day = day;

		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d) // �������캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(const Date&):" << this << endl;
	}

	Date& operator=(const Date& d) // ��ֵ���������
	{
		cout << this << "=" << &d << endl;

		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	~Date() // ��������
	{
		cout << "~Date():" << this << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

Date TestDate1(Date d)
{
	Date temp(d);
	temp = d;
	return temp;
}

void Test1()
{
	Date d1(2020, 8, 8);
	Date d2(2020, 8, 9);
	d1 = TestDate1(d2);
}

Date& TestDate2(Date& d)
{
	Date temp(d);
	temp = d;
	return d;
}

void Test2()
{
	Date d1(2020, 8, 8);
	Date d2(2020, 8, 9);
	d1 = TestDate2(d2);
}

int main()
{
	// Test1();
	Test2();
	return 0;
}
#endif




// ������
class Complex
{
public:
	Complex(double real, double image)
	{
		_real = real;
		_image = image;
	}

	Complex& operator=(const Complex& C);
	bool operator>(const Complex& C);
	bool operator<(const Complex& C);
	bool operator==(const Complex& C);
	bool operator!=(const Complex& C);
	bool operator+(const Complex& C);
	bool operator-(const Complex& C);
	bool operator*(const Complex& C);
	bool operator/(const Complex& C);

	// ������Ĺ��캯�� + �������캯�� + ��ֵ���������--->�����������Բ���ʵ��
private:
	double _real; // ʵ��
	double _image; // �鲿

};