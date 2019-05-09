/*
面试题10：斐波那契数列
 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
*/

#include<iostream>

using namespace std;

//通常斐波那契数列都是讲解递归的经典例子，但是真正高效的解法确实非递归的方法
int Fibonacci(int n)
{
	if(n == 0 || n == 1)
		return n;

	int pre = 1;
	int prepre =0;
	int current = 0;
	for(int i = 2;i <= n;++i)
	{
		current = pre + prepre;//f(n) = f(n-1) + f(n-2)
		prepre = pre;
		pre = current;
	}
	return current;
}

int main()
{
	for(int i = 0;i < 10;++i)
	{
		cout << Fibonacci(i) << " ";
	}
	cout << endl;

	return 0;

}
