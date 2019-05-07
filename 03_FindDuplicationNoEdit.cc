/*
面试题3（二）：不修改数组找出重复的数字
题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
输出是重复的数字2或者3。
*/

#include<iostream>

using namespace std;

int countRange(const int *numbers,int length,int start,int end)
{
	int count = 0;
	for(int i = 0;i < length;++i)
	{
		if(numbers[i] >= start && numbers[i] <= end)
			count++;
	}
	return count;
}

//数组的范围大小是n,但数组的大小是n+1，故至少存在一个重复的数字；
//按数值范围的中位数划分数组，则元素个数大于数值范围大小的那方一定存在重复数字
int FindDuplicationNoEdit(const int *numbers,int length)
{
	int start = 1;
	int end = length - 1;
	while(start < end)
	{
		int mid = (end + start) / 2;
		int count = countRange(numbers,length,start,mid);
		
		if(count > (mid - start + 1))
		{
			end = mid;	
		}
		else
		{
			start = mid + 1;
		}
	}
	//当start和end相等时,即找到了重复的数字
	return start;
}

//=================测试代码=================

int main()
{
	int numbers[] = {1,2,2,3,4,5,6,7};
	cout << "{1,2,2,3,4,5,6,7}" <<  FindDuplicationNoEdit(numbers,sizeof(numbers)/sizeof(int)) << endl;
	return 0;

}
