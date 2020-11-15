#define _CRT_SECURE_NO_WARNINGS 1


// OJ��Ŀ
#if 0
// ��ջʵ�ֶ���
// �����ʹ������ջʵ�������ȳ�����
class MyQueue 
{
public:
	MyQueue() 
	{}

	void push(int x) 
	{
		s1.push(x);
	}

	int pop() 
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		int ret = s2.top();
		s2.pop();
		return ret;
	}

	int peek() // ���ض��п�ͷ��Ԫ��
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}

		return s2.top();
	}

	bool empty() 
	{
		return s1.empty() && s2.empty();
	}

private:
	stack<int> s1; // ģ����ջ
	stack<int> s2; // ģ���ջ
};




// �ö���ʵ��ջ
class MyStack {
public:

	MyStack() 
	{}

	void push(int x) 
	{
		if (!q1.empty())
			q1.push(x);

		else
			q2.push(x);
	}

	int pop() 
	{
		int ret = 0;
		if (!q1.empty())
		{
			// ��q1��ǰn-1��Ԫ�ص��뵽q2��
			while (q1.size() > 1)
			{
				q2.push(q1.front());
				q1.pop();
			}

			ret = q1.front();
			q1.pop();
		}
		else
		{
			// ��q2��ǰn-1��Ԫ�ص��뵽q1��
			while (q2.size() > 1)
			{
				q1.push(q2.front());
				q2.pop();
			}

			ret = q2.front();
			q2.pop();
		}

		return ret;
	}

	int top() 
	{
		if (!q1.empty())
			return q1.back();

		else
			return q2.back();
	}

	bool empty() 
	{
		return q1.empty() && q2.empty();
	}

private:
	queue<int> q1;
	queue<int> q2;
};



// �����еĵ�K�����Ԫ��
// ��δ������������ҵ��� k ������Ԫ��

class Solution 
{
public:
	int findKthLargest(vector<int>& nums, int k) 
	{
		priority_queue<int> q(nums.begin(), nums.end()); // С�ڷ�ʽ���������
		// �����ȼ�������ǰk-1��Ԫ��ɾ����
		for (int i = 0; i < k - 1; ++i)
			q.pop();

		return q.top();


		//sort(nums.begin(), nums.end(), greater<int>());
		//return nums[k-1];
	}
};


#endif