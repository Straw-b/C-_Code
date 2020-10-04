#define _CRT_SECURE_NO_WARNINGS 1




/*
const:
��C�����У����Ա���  �������κ����Ĳ���   �������κ����ķ���ֵ
��C++�У�
const�������Ա����----�ó�Ա���������޸ģ����ұ���Ҫ�ڹ��캯����ʼ���б��λ�÷���
const�������Ա����
*/

/*
Date����Time�����Ԫ�࣬�������Date����ֱ�ӷ���Time���˽�г�Ա��
*/
class Time
{
	friend class Date;
public:
	Time(int hour, int minute, int second)
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
		, _t(12, 15, 13)
	{}


	/*
	const���ηǾ�̬��Ա�����������������γ�Ա������thisָ��
	����thisָ��ָ������е����ݾͲ��ܱ��޸�
	*/
	const Date* TestDate(const int& a)const
	{
		//_day = 10;
		return this;
	}


	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << "  " << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};


int main()
{


	return 0;
}