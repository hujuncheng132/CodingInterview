/*
面试题5：替换空格
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
则输出“We%20are%20happy.”。
*/

#include<iostream>

//先计算好需要替换的空格总数，然后从后往前替换
//length 为字符数组str的总容量，大于或等于字符串str的实际长度
void replaceBlank(char str[],int length)
{
	// 参数有效性检查
	if(str == nullptr || length <= 0)
		return;

	int blankCount = 0; //空格数
	int oriLength = 0; //字符串原始长度（不包括末尾字符'\0'）
	int i = 0; //下标
	// 统计字符串的空格数和原始长度
	while(str[i] != '\0')
	{
		++oriLength;
		if(str[i] == ' ')
			++blankCount;
		++i;
	}
	
	int newLength = oriLength + 2*blankCount; //替换后的总长度，每替换一个空格，字符串的总长度增加2（不包括末尾字符'\0'）
	if(newLength + 1 > length)//检查内存空间是否足够
		return;
	
	int p1 = oriLength;//p1指向原始字符串的末尾位置(包含空字符‘\0‘)
	int p2 = newLength;//p2指向替换之后字符串的末尾位置(包含空字符'\0')
	//若p1指向的是非空格字符，则p1处的字符移到p2处，然后p1、p2同时回移一位
	//若p1指向的是空格字符，则p1回移1位，p2回移3位，且将包括p2在内的后三个位置填上“%20"
	//当p1和p2相遇时，代表替换完成
	while(p1 >= 0 && p2 > p1)
	{
		if(str[p1] != ' ')
		{
			str[p2--] = str[p1];
		}
		else
		{
			str[p2--] = '0';
			str[p2--] = '2';
			str[p2--] = '%';
		}
		--p1;
	}
	
}

int main()
{
	char str[100] = "we are happy";
	replaceBlank(str,sizeof(str)/sizeof(*str));
	std::cout << str << std::endl;
	return 0;
}
