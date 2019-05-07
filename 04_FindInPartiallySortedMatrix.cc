/*
面试题4：二维数组中的查找
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
整数，判断数组中是否含有该整数。
*/

#include<iostream>

using namespace std;

//每次都和右上角的元素比较（也可以是左下角），这样每次比较之后都能拍出一行或者一列
bool find(int* matrix,int rows,int columns,int number)
{
	int row = 0;
	int column = columns - 1;
	while(row < rows && column >= 0)
	{
		int temp = matrix[row * columns + column];//将二维指针转换成一维指针的用法
		if(number == temp)
			return true;
		else if(number > temp)
			++row;
		else
			--column;
	}
	return false;
}

int main()
{
	int matrix[3][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}};
	cout << find((int*)matrix,3,4,3) << endl;
	cout << find(&matrix[0][0],3,4,7) << endl;
	return 0;
}	
