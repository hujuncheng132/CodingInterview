// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include<iostream>
#include <exception>

int minInOrder(int A[],int start,int end)
{
    int min = A[start];
    for(int i = start+1;i <= end;++i)
    {
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

/*
根据旋转数组的特点，如果中间的元素大于第一个元素，说明最小的元素在右半区间，如果中间元素小于第一个元素，说明最小的元素在左半区间，
利用二分法的思想进行处理，但要考虑特设情况，即中间元素、第一个元素、最后一个元素三者相等时，只能顺序查找
*/
int findMinNumberInRotatedArray(int A[],int length)
{
    // 参数有效性检测
    if(A == nullptr || length <= 0)
        throw new std::exception();

    int start = 0,end = length-1,mid = start;
    while(A[start] >= A[end]) // 第一个元素大于等于最后一个元素，就说明start-end这个区间仍然满足旋转数组的特点
    {
        if(end - start == 1) // 当第一个元素和最后一个元素只相差一位时，说明此时已经找到了最小的元素，即end所指的元素
        {
            mid = end;
            break;
        }

        mid = (start + end) / 2; // 利用二分法的方法，将mid指向的元素分别和start、end指向的元素做对比，
                                 // 确定最小元素在左半区间还是右半区间

        if(A[mid] == A[start] && A[mid] == A[end]) // 如果出现start、mid、end这三个元素相等的情况，此时无法判断，只能顺序查找
            return minInOrder(A,start,end);

        if(A[mid] >= A[start]) // 如果中间元素大于等于第一个元素，说明左半区间符合递增序列的要求，则最小序列在右半区间
            start = mid;
        else if(A[mid] <= A[end]) // 如果中间元素小于等于最后一个元素，说明右半区间符合递增序列的要求，则最小序列在左半区间
            end = mid;
    }
    return A[mid];
}

int main()
{
    int A[] = {3,4,5,1,2};
    std::cout << findMinNumberInRotatedArray(A,sizeof(A)/sizeof(*A)) << std::endl;
    return 0;
}