// 面试题5（课后）:
// 题目：合并两个排序数组A和B，且A有足够的空间容纳B
#include <iostream>

/*从后往前比较数字大小*/
void merge(int A[],int B[],int m,int n)
{
	// 参数有效性检查
	if(A == nullptr || B == nullptr || m <= 0 || n <= 0)
		return;

	int i = m-1; //数组A的下标
	int j = n-1; //数组B的下标
	int k = m+n-1; //合并之后数组A的下标
	while(i >= 0 || j >= 0)
	{
		//比较A和B末尾的元素大小，将较大的元素依次移动到末尾
		if(A[i] > B[j])
			A[k--] = A[i--];
		else
			A[k--] = B[j--];
	}
}

int main()
{
	int A[10] = {2,4,6,8,10};
	int B[5] = {1,3,5,7,9};
	merge(A,B,5,5);
	for(auto item:A)
	{
		std::cout << item << " ";
	}
	
	return 0;
}

