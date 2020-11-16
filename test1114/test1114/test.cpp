#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <queue>
#include <vector>



#if 0
#include "PriorityQueue.h"
#include <functional> //greater()��ͷ�ļ�

class Greater // ����
{
public:
	bool operator()(int left, int right)
	{
		return left > right;
	}
};


bool compare(int left, int right)
{
	return left > right;
}

typedef bool (*CMP) (int left, int right); // ����ָ�������


#include <stack>
#include <vector>

int main()
{
	stack<int, vector<int>> s; // Ĭ����deque�����Ըĳ�vector

	vector<int> v{ 3, 2, 5, 1, 4 };
	bite::priority_queue<int> q1{ v.begin(), v.end() };
	q1.push(0);

	//bite::priority_queue<int, vector<int>, greater<int>> q2{ v.begin(), v.end() };
	bite::priority_queue<int, vector<int>, CMP> q2{ v.begin(), v.end(), compare }; // ������ָ��
	q2.push(0);

	bite::priority_queue<int, vector<int>, Greater> q3{ v.begin(), v.end() }; // �º�������
	q3.push(0);

	return 0;
}
#endif





#if 0
size_t g_a = 10;
size_t g_b = 20;

namespace bite
{
	// T : ���Ͳ���
	// N : �����Ͳ���������const����-->��һ������
	template<class T, size_t N = 10>
	// template<class T, size_t N = g_a + g_b> // ����δ�ڱ�����ȷ�Ͻ��
	class array // ����
	{
	public:
		array()
			: _size(0)
		{
			//N = 10;
		}

		T& operator[](size_t index)
		{
			assert(index < _size);
			return _array[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < _size);
			return _array[index];
		}

		size_t size()const
		{
			return _size;
		}

		bool empty()const
		{
			return 0 == _size;
		}

	private:
		T _array[N];
		size_t _size;
	};
}

int main()
{
	bite::array<int> a1;
	return 0;
}
#endif




// ����ģ����ܶ���ĳЩ�������Ͳ��ܴ������ߴ�����߼����������
// ��ˣ���Ҫ����ģ������ڸ����������������⴦��
// �ػ�

// ���Ҫ��ģ������ػ���
// 1. ��Ҫ��ģ��Ĵ���
// 2. �÷�ģ�����͵Ĵ�������������Ͳ��ܴ���
// 3. �ø�����ȥ�ػ���ģ��

#if 1
template<class T>
const T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

// ר����Ե���char*���ػ�
//template<>
//const char*& Max<const char*&>(const char*& left, const char*& right)
//{
//	if (strcmp(left, right) > 0)
//		return left;
//
//	return right;
//}

// ���ú���ֱ�Ӹ���
char* Max(char* left, char* right)
{
	if (strcmp(left, right) > 0)
		return left;

	return right;
}

int main()
{
	cout << Max(10, 20) << endl;
	cout << Max(1.2, 3.4) << endl;

	const char* p1 = "hello";
	const char* p2 = "World";
	cout << Max(p1, p2) << endl;
	return 0;
}
#endif