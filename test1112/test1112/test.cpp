#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <queue>
#include <vector>
#include <functional> //greater()��ͷ�ļ�



#if 0
#include "Stack.h"

int main()
{
	bite::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << s.size() << endl;
	cout << s.top() << endl;

	s.top() = 5;
	cout << s.size() << endl;
	cout << s.top() << endl;

	s.pop();
	cout << s.size() << endl;
	cout << s.top() << endl;
	return 0;
}
#endif




#if 0
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << endl;
	q.front() = 0;
	cout << q.front() << endl;

	cout << q.back() << endl;
	q.back() = 50;
	cout << q.back() << endl;

	cout << q.size() << endl;

	q.pop();
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() << endl;

	return 0;
}
#endif





#if 0
#include "Queue.h"
int main()
{
	bite::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << q.front() << endl;
	q.front() = 0;
	cout << q.front() << endl;

	cout << q.back() << endl;
	q.back() = 50;
	cout << q.back() << endl;

	cout << q.size() << endl;

	q.pop();
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.size() << endl;

	return 0;
}
#endif





// ���ȶ��У��ѣ�
#if 0
int main()
{
	// ע�⣺Ĭ�ϰ���С�ڽ��бȽϣ����
	priority_queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	cout << q1.size() << endl;
	cout << q1.top() << endl;

	q1.pop();
	cout << q1.top() << endl;


	vector<int> v{ 1, 2, 3, 4, 5 };
	priority_queue<int, vector<int>, greater<int>>  q2(v.begin(), v.end()); //С��

	cout << q2.top() << endl;
	return 0;
}
#endif




#if 0
class Date // �Զ���������
{
public:
	Date(int year = 1900, int month = 1, int day = 1) 
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return _day < d._day;
	}

	bool operator>(const Date& d)const
	{
		return _day > d._day;
	}

	int _year;
	int _month;
	int _day;
};


void TestPriorityQueue1()
{
	Date d1(2020, 11, 12);
	Date d2(2020, 11, 11);
	Date d3(2020, 11, 13);

	priority_queue<Date> q1;
	q1.push(d1);
	q1.push(d2);
	q1.push(d3);
}


//  �º���/��������---��������һ��ʹ�õĶ���
//  ԭ��ֻ��Ҫ�����н�()����һ��
//  ()��Ϊ�������������
//  ���ã������㷨����
class Greater
{
public:
	bool operator()(const Date* left, const Date* right)
	{
		return left->_day > right->_day;
	}
};

bool gg(const Date* left, const Date* right)
{
	return left->_day > right->_day;
}


int main()
{
	Date* p1 = new Date(2020, 11, 12);
	Date* p2 = new Date(2020, 11, 11);
	Date* p3 = new Date(2020, 11, 13);

	// q1����һ���ѣ����ⲻ���ڴ���less����greater
	// ����Ϊpriority_queue�ڲ� ����ָ���ֵ ֱ�ӽ��бȽ�---ֱ���õ�ַ�Ƚ�
	priority_queue<Date*> q1; // ���
	//priority_queue<Date*, vector<Date*>, Greater> q1; // С��
	q1.push(p1);
	q1.push(p2);
	q1.push(p3);


	Greater g;
	g(p1, p2);    // �������ã�g��һ������
	gg(p1, p2);   // �������ã�gg��һ��������

	return 0;
}
#endif




#if 0
struct Goods
{
	Goods(const string& name, double price)
	: _name(name)
	, _price(price)
	{}

	bool operator<(const Goods& g)const
	{
		return _price < g._price;
	}

	bool operator>(const Goods& g)const
	{
		return _price > g._price;
	}

	string _name;
	double _price;
};

struct Greater
{
	bool operator()(const Goods& g1, const Goods& g2)
	{
		return g1._price > g2._price;
	}
};


#include <algorithm>

int main()
{
	// Ĭ�ϰ���С�ڱȽ�--->����
	vector<int> v{ 2, 5, 0, 8, 1, 7, 6, 4, 3, 9 };
	sort(v.begin(), v.end());

	// ����greater���бȽ�--->����
	//greater<int>()����һ��greater<int>���͵���������
	sort(v.begin(), v.end(), greater<int>());


	Goods gs[] = { { "apple", 2.5 }, { "banana", 1.8 }, { "orange", 3.2 } };

	sort(gs, gs + sizeof(gs) / sizeof(gs[0])); //����
	//sort(gs, gs + sizeof(gs) / sizeof(gs[0]), greater<Goods>());
	sort(gs, gs + sizeof(gs) / sizeof(gs[0]), Greater()); //����

	return 0;
}
#endif




#if 1
#include "PriorityQueue.h"

int main()
{
	vector<int> v{ 3, 2, 5, 1, 4 };
	bite::priority_queue<int> q1{ v.begin(), v.end() };
	q1.push(0);
	bite::priority_queue<int, vector<int>, greater<int>> q2{ v.begin(), v.end() };
	q2.push(0);
	return 0;
}
#endif