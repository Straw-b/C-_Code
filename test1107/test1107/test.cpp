#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

#include <list>
#include <vector>




#if 0
// ������ʧЧ
// erase / pop_back �������������һ���ڵ��ʧЧ��
// pop_front ���������ڵ�һ���ڵ��ʧЧ��
// clear() 
int main()
{
	list<int> L{ 1, 2, 3, 4, 5 };
	auto rit = L.rbegin();
	while (rit != L.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	auto it = L.begin();
	//L.pop_back();
	//L.pop_front();
	cout << *it << endl;
	while (it != L.end())
	{
		it = L.erase(it);
		//++it;
	}
	return 0;
}
#endif




#if 0
//#include "abc.h"
#include "List.h"

int main()
{
	//TestMyList1();
	//TestMyList2();
	//TestMyList3();
	TestMyList4();
	return 0;
}
#endif




#if 0
#include<stack>

int main()
{
	stack<int> s;
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





// �沨�����ʽ��ֵ
// �����沨����ʾ��������ʽ��ֵ��
// ��Ч����������� + , -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ

class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s;
		for (auto& e : tokens) // e����RPN�е�ÿһ��
		{
			// ������������֣�Ҳ�����Ƿ���
			if (!(e == "+" || e == "-" || e == "*" || e == "/"))
			{
				s.push(atoi(e.c_str())); // atoi�Ѳ��� str ��ָ����ַ���ת��Ϊһ������
			}
			else
			{
				// e��һ��������
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();

				switch (e[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left * right);
					break;
				case '/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};




// ջ�ĵ���ѹ������
// ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
// ����ѹ��ջ���������־�����ȡ�
// ��������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		if (pushV.size() != popV.size())
			return false;

		stack<int> s;
		int outIdx = 0;
		int inIdx = 0;
		while (outIdx < popV.size())
		{
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx >= pushV.size())
					return false;
				else
					s.push(pushV[inIdx++]);
			}

			s.pop();
			++outIdx;
		}
		return true;
	}
};




// ��Сջ
// ���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ

class MinStack 
{
public:
	MinStack() 
	{}

	void push(int x) 
	{
		dataStack.push(x);
		if (minStack.empty() || x <= minStack.top())
			minStack.push(x);
	}

	void pop() 
	{
		if (dataStack.top() == minStack.top())
			minStack.pop();

		dataStack.pop();
	}

	int top() 
	{
		return dataStack.top();
	}

	int getMin() 
	{
		return minStack.top();
	}

private:
	stack<int> dataStack;
	stack<int> minStack;
};