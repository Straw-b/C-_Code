#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


#if 0
// �ڲ���
class A
{
private:
	static int k;
	int h;
public:
	// ע�⣺B��ֻ����A���ж����ˣ����ǲ�����A���һ���֣�����ʵ�ʻ��Ƕ�����
	// �ⲿ�����ڲ������Ԫ�࣬˵�����������ڲ�����ֱ�ӷ����ⲿ���˽�еĳ�Ա

	// ����ڲ�����Ҫ��ȫ���������д�������ʱ���������ⲿ���ж���ʱ����ʹ��public������
	// ����ڲ�����Ҫ��ȫ���������в���Ҫ��������ʱ���������ⲿ���ж���ʱ����ʹ��private������
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;//OK
			cout << a.h << endl;//OK // ���ֵ

			// cout << h << endl; // ����ʧ�ܣ���Ϊh���ⲿ�����ͨ��Ա����������Ҫͨ���ⲿ��Ķ��������з���
		}
		int b;
	};
};

int A::k = 1;

int main()
{
	cout << sizeof(A) << endl;

	A::B b;
	b.foo(A());
	return 0;
}
#endif




#if 0
// ����˵������Ҫʵ��һ����ͷ�ڵ��˫��ѭ������
class List
{
	// ����ڲ�����Ҫ��ȫ���������д�������ʱ���������ⲿ���ж���ʱ����ʹ��public������
	// ����ڲ�����Ҫ��ȫ���������в���Ҫ��������ʱ���������ⲿ���ж���ʱ����ʹ��private������
private:
public:
	struct ListNode
	{
		ListNode* _next;
		ListNode* _prev;
		int _data;
		ListNode(int data = 0)
			: _next(nullptr)
			, _prev(nullptr)
			, _data(data)
		{}
	};

public:
	List()
		:head(nullptr)
	{}

	void PushBack(int data)
	{}

	void PopBack()
	{}

	size_t size() const
	{
		return 0;
	}

private:
	ListNode* head;
};

int main()
{
	List::ListNode node(10);
	return 0;
}
#endif




#include <malloc.h>

int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	// ...����һֱ�����±�ķ�ʽ�����в���
	// �ӳ���ĽǶ�������malloc����Ŀռ����������

	*(p + 1) = 10; // �ȼ���p[1]=10
	*((int*)&p + 1) = 10;

	free(p);
	return 0;
}