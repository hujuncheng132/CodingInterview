/*
面试题10：斐波那契数列
题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。f(n) = f(n-1) + f(n-2)
*/
#include<iostream>
#include<time.h>

// 斐波那契额数列的递归算法十分简洁，但是存在大量重复计算的问题，并不是高效的解法
long long FibonacciRec(unsigned int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	return FibonacciRec(n-1) + FibonacciRec(n-2);
}

// 由于递归算法存在大量重复计算的问题，因此我们应该采用自下而上的方法，并保存中间的计算结果
long long Fibonacci(unsigned int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	long long FibonacciOne = 0,FibonacciTwo = 1,Fibonacci = 0;
	for(unsigned int i = 2;i <= n;++i)
	{
		Fibonacci = FibonacciOne + FibonacciTwo;
		FibonacciOne = FibonacciTwo;
		FibonacciTwo = Fibonacci;
	}

	return Fibonacci;
}

int main()
{
	clock_t startTime1 = clock();
	long long result1 =  FibonacciRec(40);
	clock_t endTime1 = clock();
	std::cout << result1 <<  " " << "递归方法时间:" <<  (double)(endTime1 - startTime1) / CLOCKS_PER_SEC << "s" << std::endl;

	clock_t startTime2 = clock();
	long long result2 =  Fibonacci(40);
	clock_t endTime2 = clock();
	std::cout << result2 <<  " " << "非递归方法时间:" <<  (double)(endTime2 - startTime2) / CLOCKS_PER_SEC << "s" << std::endl;

	return 0;

}
