/*
面试题5：替换空格
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
则输出“We%20are%20happy.”。
*/

#include<iostream>

using namespace std;

//先计算好需要替换的空格总数，然后从后往前替换
void replaceBlank(char *str,int length)
{
	int blankCount = 0;
	int oriLength = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		++oriLength;
		if(str[i] == ' ')
			++blankCount;
		++i;
	}

	int newLength = oriLength + 2*blankCount;
	cout << oriLength << " " <<  blankCount << endl;
	if(length > newLength)//确保内存空间足够
	{
		int p1 = oriLength;//p1指向原始字符串的末尾(包含空字符‘\0‘)
		int p2 = newLength;//p2指向替换之后字符串的末尾(同样包含空字符'\0')
		//若指向的是非空格字符，则p1处的字符移到p2处，然后p1、p2同时前移一位
		//若指向的是空格字符，则p1前移1位，p2前移3位，且将p2的后三个位置填上“%20"
		//当p1和p2相遇时，代表替换完成
		while(p1 != p2)
		{
			if(str[p1] != ' ')
			{
				str[p2--] = str[p1--];
			}
			else
			{
				str[p2--] = '0';
				str[p2--] = '2';
				str[p2--] = '%';
				p1--;
			}
		}
	
	}
	return;
}

int main()
{
	char str[100] = "we are happy";
	cout << str << endl;
	replaceBlank(str,100);
	cout << str << endl;
	return 0;
}
