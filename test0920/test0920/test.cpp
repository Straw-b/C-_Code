#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// 1.��1 + 2 + 3 + ... + n��
// Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж����
class Sum
{
public:
	Sum() // �������Զ��������캯��
	{
		count++;
		sum += count;
	}

	static void Reset()
	{
		count = 0;
		sum = 0;
	}

	static int GetSum() // ����
	{
		return sum;
	}

private:
	// ��̬���͵ĳ�Ա����
	static int count; // ������ʾ�ӵ�ÿһ��
	static int sum; // �����ۼ����ӵĽ��
};

int Sum::count = 0; // ����
int Sum::sum = 0;

class Solution 
{
public:
	int Sum_Solution(int n) 
	{
		Sum::Reset();
		Sum s[n];
		return Sum::GetSum();
	}
};

//int main()
//{
//	Sum s1[3];
//	cout << Sum::GetSum() << endl; // 1+2+3=6
//
//	// ����һ�εĽ������
//	Sum::Reset();
//
//	Sum s2[5];
//	cout << Sum::GetSum() << endl; // 1+2+3+4+5=15
//	
//	return 0;
//}
#endif





#if 0
// �������ʵ��
// ������������ã�Ϊ����ߴ���Ŀɶ���
// �������أ�һЩ��������ͬ�����򡢺���������ͬ�������б�ͬ���뺯������ֵ�����Ƿ���ͬ�޹�
// ע�⣺��Щ������������أ�
class Date
{
public:
	// ȫȱʡ�Ĺ��캯��
	// ��������Ƿ������ڣ��������ڹ���Ĭ�ϵ�����
	Date(int year = 1900, int month = 1, int day = 1)// ����Ĭ�ϲ���
		: _year(year)
		, _month(month)
		, _day(day)
	{
		if (!((year > 0) &&
			(month >= 1 && month <= 12) &&
			(day >= 1 && day <= GetMonthDay(year, month))))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}

	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2)
		{
			// �������Ƿ�Ϊ����
			if (isLeapYear(year))
				days[2] += 1;
		}
		return days[month];
	}

	bool isLeapYear(int year)const
	{
		// ����һ����겻��ÿ�İ�����һ��
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return true;
		}
		return false;
	}

	// �������캯��
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	// ��ֵ���������
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// ��������
	~Date()
	{}

	friend ostream& operator<<(ostream& _cout, const Date& d);


	//////////////////////////////////////////////////////////////////////////////
	// ע�⣺����֮ǰ���ص�������������ô���ʵ���������ӵļ�
	// >���������
	bool operator>(const Date& d)const
	{
		if ((_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day))
		{
			return true;
		}
		return false;
	}

	// ==���������
	bool operator==(const Date& d)const
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	// ע�⣺==��!=��ͬʱ���ֵ�
	// !=���������
	bool operator != (const Date& d)const
	{
		return !(*this == d);
	}

	// >=���������
	bool operator >= (const Date& d)
	{
		if (*this > d || *this == d)
			return true;
		return false;
	}

	// <���������
	bool operator < (const Date& d)const
	{
		if (!(*this > d || *this == d))
			return true;
		return false;
	}

	// <=���������
	bool operator <= (const Date& d)const
	{
		if (*this < d || *this == d)
			return true;
		return false;
	}


	//////////////////////////////////////////////////////////////////////////////
	// ����+����
	Date operator+(int days)
	{
		// ����Ҫ��days�ӵ���ǰ������
		//_day += days;
		//return *this;
		// ע�⣺���ܽ������ӵ���ǰ�����ϣ���Ϊ+����������ͱ��޸���
		// ������+�Ĺ���

		if (days < 0)
		{
			return *this - (0 - days);
		}

		Date temp(*this);
		temp._day += days;

		// temp���ڿ��ܻ�Ƿ������_day�������걾�µ����������ڿ϶����ǷǷ���
		int daysOfMonths = 0;
		while (temp._day >(daysOfMonths = temp.GetMonthDay(temp._year, temp._month)))
		{
			temp._month += 1;
			if ((temp._month > 12))
			{
				temp._year += 1;
				temp._month = 1;
			}
			temp._day -= daysOfMonths;
		}
		return temp;
	}

	// ����-����
	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}

		Date temp(*this);
		temp._day -= days;

		// temp���ڷǷ�
		while (temp._day <= 0)
		{
			temp._month -= 1;
			if (temp._month == 0)
			{
				temp._year -= 1;
				temp._month = 12;
			}
			temp._day += temp.GetMonthDay(temp._year, temp._month);
		}
		return temp;
	}

	// ǰ��++
	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}

	// ǰ��--
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}

	// ����--
	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	// ����-���� ��������
	// *this��d֮��Ĳ�ֵ
	int operator-(const Date& d)
	{
		Date minDate(*this);
		Date maxDate(d);
		if (minDate > maxDate)
		{
			minDate = d;
			maxDate = *this;
		}

		int count = 0;
		while (minDate != maxDate)
		{
			count++;
			minDate++;
		}

		return count;
	}

private:
	int _year;
	int _month;
	int _day;
};

// <<������
// 1.����Ҫ���س�ȫ�ֺ���---��Ϊ���ĵ�һ������������ostream&
// 2.������سɳ�Ա�����������һ����������thisָ�룬�����Ƿ��� d<<cout;
// 3.����Ҫ�з���ֵ��Ϊ��֧���������
// 4.�ں����������ʱ����������һЩ��ʽ���Ĳ��������绻��

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int main()
{
	Date d1(2020, 9, 20);
	Date d2;
	//d2 = d1 + 999;
	d2 = d1 - 999;
	cout << d1 << endl;
	cout << d2 << endl;

	Date d3(2020, 9, 100);
	cout << d3 << endl;

	Date d4(2021, 1, 1);
	cout << d1 - d4 << endl;
	return 0;
}
#endif





#if 0
// 2.�������ڵ�������ת��
// ������������ڣ���������һ��ĵڼ���
// ��ϸ������
// ����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿

int main()
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year, month, day;

	// ���裺2020,9,20
	// 1. ֻ�轫ǰ8����ÿ���µ�����������
	// 2. ������9�·ݵ�20��
	// 3. ע������

	// ѭ�����ն����������
	while (cin >> year >> month >> day)
	{
		// ÿ�ν��ܵ�һ�����������Ȼ������������
		// ͳ��month-1ÿ���µ�����
		int totalDays = 0;
		for (int i = 0; i < month; ++i)
		{
			totalDays += days[i];
		}

		if ((0 == year % 4 && 0 != year % 100) || (0 == year % 400))
		{
			if (month>2)
				totalDays += 1;
		}

		totalDays += day;
		cout << totalDays << endl;
	}
	return 0;
}
#endif




// ��Ŀ��һ���ж������
// ��������һ�������һ������

int main()
{
	char sz[1024] = { 0 };

	// ע�⣺�����Ҫ����һ�����ַ���������£�����ֱ��ʹ��scanf��cin
	// ��Ϊscanf��cin�����ո��ֹͣ���գ��ո�֮������ݽ��ղ���
	//cin >> sz;
	//scanf("%s", sz);

	while (gets(sz))
	{
		// ʵ�ʴӺ���ǰ�ң��ҵ���һ���ո�
		int i = strlen(sz);
		for (; i >= 0; i--)
		{
			if (sz[i] == ' ')
				break;
		}

		// ����һ��ֻ��һ�����ʣ����о�û�пո�
		if (i < 0)
		{
			i = 0;
			cout << sz + i << endl;
		}
		else
			cout << sz + i + 1 << endl;
	}

	return 0;
}

