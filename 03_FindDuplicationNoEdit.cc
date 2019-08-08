/*
面试题3（二）：不修改数组找出重复的数字
题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
输出是重复的数字2或者3。
*/

#include<iostream>

using namespace std;

// 统计数组中值在某个范围[min,max]内的元素的数量
int countRange(const int numbers[],int length,int min,int max)
{
	// 参数有效性检查
	if(numbers == nullptr)
		return 0;

	int count = 0;
	for(int i = 0;i < length;++i)
	{
		if(numbers[i] >= min && numbers[i] <= max)
			count++;
	}
	return count;
}

//数组的元素值范围是1到n,但数组的大小是n+1，故至少存在一个重复的数字；
//将数组的元素值范围等分成两部分，分别统计这两个元素值范围内的元素的数量，如果元素数量大于元素值范围的大小，则该元素值范围内一定存在重复的元素值
int FindDuplicationNoEdit(const int *numbers,int length)
{
	// 参数有效性检查
	if(numbers == nullptr || length <= 0)
		return -1;

	// 数组元素的值范围为[min,max]
	int min = 1;
	int max = length - 1;
	while(max >= min)
	{	
		// 将元素值范围等分并统计范围内的元素个数
		int mid = (min + max) / 2; // 或者((max - min) >> 1) + min
		int count = countRange(numbers,length,min,mid);
		// 当max == min时表示已经找到那个元素值
		// 此时还需要统计该元素值的数量，如果大于1则表示正确，否则说明数组存在问题
		if(max == min)
		{
			if(count > 1) //count>1表示找到了这个数
				return min;
			else //否则说明输入的数组有问题
				break;
		}
		// 重复元素的值在 元素个数 > 值范围大小 的一方
		if(count > (mid - min  + 1))
			max = mid;	
		else
			min = mid + 1;
	}
	return -1;
}

int main()
{
	int number[] = {0,2,4,6,8,1,3,5,7,9,3};
	std::cout << "源数组为：{0,2,4,6,8,1,3,5,7,9,3}，重复的数字为：" << FindDuplicationNoEdit(number,sizeof(number)/sizeof(*number)) << std::endl;
	
	return 0;
}
