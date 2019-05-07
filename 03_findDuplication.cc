/*
面试题3（一）：找出数组中重复的数字
题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
那么对应的输出是重复的数字2或者3。
*/

#include<iostream>

using namespace std;

void exchange(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//数组中数字的范围大小和数组的大小正好相同，如果没有重复的数字，则每个数字正好出现一次，和下标一一对应；
//如果存在重复的数字，则可以通过把每个数字放到和它的值对应的位置处，这样就可以找到重复的数字
int duplicate(int numbers[], int length)
{
	for(int i = 0;i < length;++i)
	{	//遍历每个位置，如果数值和下标不等，则将其移到和数值相对应的位置处；
		//如果该处已经有该数值就说明这个数重复了
		while(numbers[i] != i)
		{
			if(numbers[i] == numbers[numbers[i]])
			{
				return numbers[i];
			}
			else
			{
				exchange(numbers[i],numbers[numbers[i]]);
			}
		}
	}
	return -1;
}

void Test()
{
	int numbers[] = {1,3,0,2,1,4};
	cout << "{1,3,0,2,1,4} " <<  duplicate(numbers,6) << endl;
	return;
}

int main()
{
	Test();
	return 0;
}
