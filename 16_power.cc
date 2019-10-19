// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent次方。
// 不得使用库函数，同时不需要考虑大数问题。

#include<iostream>
#include<stdexcept>

using namespace std;

bool equal(double a,double b)
{
    if(-0.0000001 < (a-b) && (a-b) < 0.0000001)
        return true;
    return false;
}

double PowerWithUnsignedExponent1(double base,unsigned int exponent)
{
    double result = 1.0; //如果指数为0，返回1（指数为0，底数也为0的情况没有意义，因此无论输出0还是1都可以，这里输出1）
    for(int i = 1;i <= exponent;++i)
        result *= base; //如果底数为0，返回0
    return result;
}

double PowerWithUnsignedExponent2(double base,unsigned int exponent)
{
    if(exponent == 0)
        return 1.0;
    if(exponent == 1)
        return base;
    
    double result = PowerWithUnsignedExponent2(base,exponent>>1); //采用递归的方式减少运算(用右移代替除2)
    result *= result;
    if(exponent & 0x1 == 1) //如果指数为奇数，则还需要再乘一个base(用位与代替求取)
        result *= base;

    return result;
}

double Power(double base, int exponent)
{
    //考虑异常情况，即base为零，exponent为负的情况
    if(equal(base,0.0) && exponent < 0)
        throw runtime_error("异常输入！");

    // 统一将指数转为正数，最后再根据指数的正负决定是否求倒
    unsigned int absExponent = static_cast<unsigned int>(exponent);
    if(exponent < 0)
        absExponent = static_cast<unsigned int>(-exponent);

    double result = PowerWithUnsignedExponent2(base,absExponent);

    if(exponent < 0)
        result = 1.0/result;
    return result;
}

int main()
{
    cout << Power(2,10) << endl;
    return 0;
}