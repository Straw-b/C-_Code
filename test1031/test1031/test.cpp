#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#include <vector>


#if 0
int** Create(int row, int col)
{
	int** p = new int*[row];
	for (int i = 0; i < row; ++i)
		p[i] = new int[col];

	return p;
}

void TestVector(size_t n)
{
	//vector<int> v;
	//v.reserve(10); // ��Ԫ��
	//v.resize(10); // ����Ԫ��
	//cout << v[0] << endl;

	vector<vector<int>> vv;

	// ���ٱ���ÿ��vectorԪ�صĿռ�
	vv.resize(n);

	// ����ÿ�еĿռ�
	for (size_t i = 0; i < n; ++i)
	{
		vv[i].resize(i + 1, 1);
	}

	// ����������ǳ���0�кͶԽ���֮���Ԫ��
	for (size_t i = 2; i < n; ++i)
	{
		for (size_t j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < vv[i].size(); ++j)
		{
			printf("%3d", vv[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	TestVector(10);
	return 0;
}
#endif




#if 0
int main()
{
	vector<int> v;
	v.push_back(1);

	auto it = v.erase(v.begin());
	if (it == v.end())
		cout << "it == end" << endl;
	else
		cout << "it != end" << endl;
	return 0;
}
#endif




#if 0
#include "Vector.h"

int main()
{
	//TestMyVector1();
	//TestMyVector2();
	TestMyVector3();
	return 0;
}
#endif




#if 1
#include "Vector.h"

int main()
{
	// ��ͨ���͵Ķ���
	bite::vector<int> v1(10, 5);

	// v1[0]--->v1.operator[](0)-->t
	v1[0] = 6;

	const bite::vector<int> v2(10, 5);
	cout << v2[0] << endl;
	return 0;
}
#endif
