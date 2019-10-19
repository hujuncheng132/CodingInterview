// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include<cstdio>
#include<cstring>
// 直接用int或者long long可能会溢出，因此可以用字符串或者数组来表示大数

/*
字符串方法：
用一个长度为n+1的字符串（第n+1为为'\0'）表示最大为n位的数字，当实际数字不足n位时，在字符串前半部分补0。
1、如何在字符串表示的数字上模拟加法；
2、如何把字符串表达的数字打印出来
*/

//对number模拟加一操作，并判断是否到达最大的n位，防止溢出
bool increment(char* number)
{
    bool isOverflow = false; //用来判断是否达到了最大的n位
    int nTakeOver = 0; //记录是否需要进位
    int length = strlen(number); //字符串的长度

    //从最低位，即number[length-1]开始
    for(int i = length-1;i >= 0;--i)
    {
        int sum = number[i]-'0'+nTakeOver; //记录当前位表示多少（把进位也计算在内了）
        if(i == length-1) //只有在最低位才进行加一操作
            sum++;

        if(sum >= 10) //如果加一之后大于等于10，表示需要进位
        {
            if(i == 0) //如果当前位已经在最高位，则表示已经溢出了
                isOverflow = true;
            else
            {
                sum -= 10; //减10之后表示的是进位之后剩下的(不是0就是1)
                nTakeOver = 1; //表示进1位
                number[i] = '0'+sum; //将数字转换成对应的字符
            }
        }
        else //如果不需要进位，则直接在当前位加一，并退出循环
        {
            number[i] = '0'+sum;
            break;
        }
    }
    return isOverflow; //返回是否已经溢出，用于判断是否需要继续加一
}

//对number的字符串进行打印，为了符合日常习惯，打印时应该去掉前面的零
void printNumber(char* number)
{
    int length = strlen(number);
    int i;
    for(i = 0;i < length;++i)
    {
        //遇到第一个非0字符就开始退出并从该位置开始打印
        if(number[i] != '0')
            break;
    }
    printf("%s ",number+i);
}

void printToMaxOfNDigits(int n)
{
    if(n <= 0)
        return;
    
    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';

    // 循环加一并打印，直到最大的n位数
    while(!increment(number))
    {
        printNumber(number);
    }
    printf("\n");
    delete[] number;
}

int main()
{
    printToMaxOfNDigits(3);
    return 0;
}