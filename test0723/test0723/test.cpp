#include <iostream>
using namespace std;




#if 0
// 引用可以达到和指针类似的效果，比如：都可以通过形参来改变外部的实参
// 问题：指针和引用有什么区别呢？
// 在底层实现上：引用就是按照指针方式实现的
int main()
{
	int a = 10;

	int* pa = &a;
	*pa = 100;

	// 概念上为了大家好理解，引用就是别名，引用与其引用的实体共用同一块内存空间，
	// 编译器不会给引用变量重新开辟内存空间

	// 实现该中技术：编译器在底层是按照指针的方式来实现

	// 用户写的代码：最终保存在磁盘中的某个文件中
	// 系统执行的代码：首先预处理、编译、汇编、链接--->生成可执行程序(exe)
	// 其中编译---编译器按照语法来检测代码，看是否有不满足语法的问题存在
	//            对用户所写代码进行翻译
	// 如果程序中使用到了引用
	// 编译器在翻译的时候，将引用按照指针的方式翻译了
	// 经过编译器编译之后的代码，根本就没有引用
	int& ra = a;
	ra = 100;

	return 0;
}
#endif




#if 0
// 原因？
// 在底层：void Swap(int* left, int* right) // 指针
//        {
//           int temp = *left;
//           *left = *right;
//           *right = temp;
//        }

void Swap(int& left, int& right) // 引用
{
	int temp = left;
	left = right;   // 代码崩溃
	right = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	int* pb = NULL;
	// *pb = 100;     // 对空指针解引用，代码在执行期间崩溃了

	// 在传参时，看起来是按照值的方式传递的
	// 但编译器在编译代码时，检测到Swap的两个参数是引用类型的
	// 编译已经将Swap函数的两个引用类型的参数转换为指针
	// 因此：Swap(a, *pb)--->编译成：Swap(&a, pb);
	Swap(a, *pb);   //  但是该位置的空指针pb解引用时却没有崩溃
	return 0;
}
#endif




#if 0
//1. 打印什么100 10
//2. 执行完成后a的值是多少？  100

// 注意：在C++中，被const修饰的已经是常量，而且具有宏替换的属性，但是替换实际在程序编译时
// 宏：是在预处理阶段发生替换--->代码还没有编译--->预处理器直接替换，不会进行类型检测--->安全性不高
// const修饰：是在编译阶段进行替换，会进行参数类型检测--->安全性高

// 在C++中，建议用const修饰常量代替宏常量

//宏常量：为了实现简单，会定义一些宏常量
//#define MAX_SIZE 100  在程序中所有用到100的位置都可以使用MAX_SIZE来代替，将来发现100不合适，一改全改
//#define PI 3.14  可以提高程序的可读性

//注意：宏常量是在预处理阶段来进行替换的，不会进行类型检测，安全性比较低

#define PI "3.1415"

const double pi = 3.14;//"3.14";

void TestFunc()
{
	int r = 2;
	//double s = PI * r * r;   // double s = "3.1415" * r * r;

	double s = pi * r * r;
	cout << s << endl;

	// 要验证被const修饰的a是否为常量，借助定义数组来测试
	// 因为：定义数组时必须要给出数组的大小，而数组的大小必须是常量
	// 编译成功，因为a被const修饰，a是一个常量
	// 注意：在C语言中，被const修饰的变量不能将其称为常量，仍旧是一个变量，只不过该变量不能够被修改
	//       即在C语言中，被const修饰的变量是：一个不能被修改的变量，不能将其称为常量
	const int a = 10;
	int array1[a];

	// 编译失败，因为b是一个变量，而定义数组时，需要一个常量来指定数组的大小
	//int b = 10;
	//int array2[b];
}

int main()
{
	const int a = 10;

	int* pa = (int*)&a;
	*pa = 100;

	cout << *pa << endl;   // *pa===a
	printf("%d\n", a);   // 编译器将该行代码最终编译成printf("%d\n", 10);  
	                    // 没有直接从a所在的空间中取数据，而是将a替换成10
	//cout << a << endl;

	TestFunc();
	return 0;
}
#endif



// 宏和内联函数的区别？
// 在C++中，有什么方式可以替代宏？
// 说说宏的优缺点。

//宏常量
//优点：一改全改，降低出错率，提高代码可读性
//缺点：在预处理节点进行替换，不会进行类型检测，代码的安全性较低
//在C++中，提出建议：尽量使用const修饰的常量替换宏常量
//
//宏函数
//优点：
//1. 不是函数，少了函数调用的开销，可以提高程序的运行效率
//2. 少写一些代码：因为宏函数可以封装多条语句---注意：不是提高了代码的复用率，因为宏函数在预处理节点展开了
//3. 可以提高代码的可读性，方便修改
//缺点：
//1. 宏函数在预处理阶段被替换，不会进行类型检测，存在安全隐患
//2. 不能调试
//3. 容易出错，在写的时候每个部分都要加括号
//4. 每个使用宏函数的位置都会被展开，会造成代码膨胀
//5. 宏函数可能会有副作用
//在C++中，对于宏函数建议尽量使用内联函数进行代替


#if 1
#define MUL(a,b) ((a)*(b))

int Mul(int left, int right)
{
	return left*right;
}

#define MAX(a,b) (((a) > (b))? (a) : (b))

int main()
{
	// MUL是一个宏函数，不是函数，在预处理节点已经将MUL宏用宏题展开了
	// 因为MUL不是函数，则不会有函数调用的开销，可以提高程序的运行效率
	cout << MUL(2, 3) << endl; // cout << 2 * 3 << endl;
	
	// Mul是一个函数，在代码执行期间就有函数调用的一些开销：比如开辟栈环境、要进行参数压栈、请清零栈空间、要返回
	cout << Mul(2, 3) << endl;

	int x = 10;
	int y = 20;

	int z = MAX(x,++y);
	cout << z << endl;  // MAX求的较大值是22，而不是21，MAX宏产生了副作用
	return 0;
}
#endif


//内联函数
//优点：
//1. 因为是函数，参数有类型，因此在编译阶段会进行参数类型检测，代码安全性高
//2. 在Debug模式下默认不会展开，可以进行调试-- - 也可以通过对编译器设置来验证到底是否展开
//3. 写时候期间不用向宏函数导出加括号，实现简单
//4. 不会有副作用
//5. 在编译阶段已经展开了，少了函数调用的开销，可以提高程序的运行效率
//缺点：每个使用内联函数的位置几乎都会被展开，会造成代码膨胀


#if 1
// 在C++中，被inline关键字修饰的函数称为内联函数
// 内联函数特性：在编译时，编译器会对内联函数进行展开，少了函数调用的开销，可以提高程序的运行效率

inline int Add(int left, int right)
{
	Add(left, right);
	return left + right;
}

inline int Max(int left, int right)
{
	return left > right ? left : right;
}


/*
release模式下，main函数相当于称为了以下的代码
int main()
{
return 0;
}

*/

#include "InlineFunc.h"

int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;

	// 检测内联函数到底有么有展开？
	// 如果没有展开，sum = Add(a,b);在该条语句中调用Add函数，有call Add
	// 如果展开，编译器已经用Add函数的函数体替换了函数调用

	// Debug模式，调试模式，Debug模式下情况下，默认是不会展开的---因为Debug为调试模式
	// 如果展开，就不能调试

	// Release模式，发布程序时所采用的模式，Release模式编译器会对代码进行大量的优化，让程序在运行时速度更快

	// Debug模式来摸索：
	// 需要对编译器来设置，具体参考课件
	sum = Add(a, b);

	cout << Max(++b, a) << endl;

	// 因为Sub函数被inline修饰，而且定义和声明分离开
	// Sub具有文件作用域，只能在其定义文件中使用
	// 在其他文件中不能使用
	// 使用时，会发生链接错误---因为编译器在编译时，发现Sub是内联函数，并没有给Sub函数生成具体函数体
	Sub(a, b);
	return 0;
}
#endif


