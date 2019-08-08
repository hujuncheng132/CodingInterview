/*
面试题4：二维数组中的查找
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
整数，判断数组中是否含有该整数。
*/

#include<iostream>

//每次都和右上角的元素比较（也可以是左下角），这样每次比较之后都能排除一行或者一列
bool find(int* matrix,int rows,int columns,int number) //这里采用int*来表示二维数组（而不是用int**）
{	
	// 参数有效性检测
	if(matrix != nullptr && rows > 0 && columns > 0)
	{	
		
		int row = 0;
		int column = columns - 1;
		while(row < rows && column >= 0)
		{
			int temp = matrix[row * columns + column];//由于二维数组在内存中连续存放，因此可通过移动指针进行访问
			if(number == temp)
				return true;
			else if(number > temp)
				++row;
			else
				--column;
		}
	}
	return false;
}

int main()
{
	int matrix[3][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}};
	std::cout << "源数组为{{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}}" << std::endl;
	std::cout << "数组是否含有元素4：" << (find(reinterpret_cast<int*>(matrix),3,4,4) ? "true" : "false") << std::endl; // 在传入二维数组时将其显式转换为int*指针(原始类型为int[4] *)
	std::cout << "数组是否含有元素4：" << (find(&matrix[0][0],3,4,7) ? "true" : "false") << std::endl;
	return 0;
}	
