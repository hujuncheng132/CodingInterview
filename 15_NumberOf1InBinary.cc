// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

/*
方法一：利用一个无符号的整数1，不断左移和n做与操作
*/
int NumberOf1_Solution1(int n)
{
    int numberOf1 = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
            ++numberOf1;
        flag << 1;
    }

    return numberOf1;
}

/*
方法二：把一个整数和它减1的结果做与运算，结果就相当于把它最右边的1变成0
*/
int NumberOf1_Solution2(int n)
{
    int numberOf1 = 0;
    while(n)
    {
        ++numberOf1;
        n = n & (n-1);
    }

    return numberOf1;
}