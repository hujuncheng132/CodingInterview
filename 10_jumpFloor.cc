/*
面试题10：青蛙跳台阶问题
题目：一只青蛙一次可以跳上一级台阶，也可以跳上二级台阶，求该青蛙跳上一个n级台阶总共有多少中跳法。

相似问题：用一个2*1的小矩形横着或者竖着去覆盖一个更大的N*2的矩形，请问用N个2*1的小矩形无重复覆盖一个2*N的大矩形共有多少种方法，
该问题本质上也是斐波那契数列，用第一个2*1的小矩形去覆盖大矩形的最左边时有两种选择：竖着放或横着放，
当竖着放时，右边还剩(N-1)*2的区域，当横着放时，左下角必须再放一个2*1的小矩形，则右边还剩(N-2)*2的区域，
总结起来f(n) = f(n-1) + f(n-2)

*/

#include <iostream>

/*
青蛙跳台阶问题其实本质上就是斐波那契数列问题；
首先考虑最简单的情况，当n=1时，显然只有1种跳法，当n=2时有两种跳法，一种是每次跳1级，另一种是一次跳2级；
用f(n)表示n级台阶共有f(n)种跳法，跳n级阶梯可以分为两种：一种是第一次跳1阶，此时跳法数目等于后面剩下的n-1阶的跳法数目f(n-1)，
另一种是第一次跳2阶，此时跳法数目等于后面剩下的n-2阶的跳法数目f(n-2)，故总的跳法数目f(n) = f(n-1) + f(n-2);
*/

long long jumpFloor(unsigned int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	return jumpFloor(n-1) + jumpFloor(n-2);
}

int main()
{
    std::cout << jumpFloor(40) << std::endl;
    return 0;
}