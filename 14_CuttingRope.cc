// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

/*
动态规划问题的三个特征：
1、求一个问题的最优解（如最大值或最小值）
2、整体问题的最优解依赖于各个子问题的最优解
3、子问题之间还要大量相互重叠的更小的子问题
动态规划问题的解决方案：由于子问题在大问题分解过程中重复出现，
为了避免重复求解子问题，我们可以用从下往上的顺序先计算小问题的最优解并存储下来（通常用一维数组或二维数组存储），
再以此为基础求解大问题的最优解
*/
#include<iostream>

int maxProductAfterCutting_solution(int length)
{

    /*
    当length<=3的时候，我们直接返回了结果。
    如果整个绳子的长度为3，我们必须把绳子剪开，因为题目要求m>1，其中一段为2，另一段为1，这样结果就是2。
     当length>=4的时候，我们可以把绳子剪成两段，其中一段为3另一段为１，这样长度为3的那一段的最大值就是3而不是2，
     因为这一段我们不需要再剪了。当然长度为4的最大值是2和2的组合，我们已经存储了2的长度。
    */
   // 这里讨论的是length=1,2,3时的情形
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;
    // 这里讨论的是length>=4时的情形
    int* products = new int[length+1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max;
    for(int i = 4;i <= length;++i)
    {
        max = 0;
        for(int j = 1;j <= i/2;++j)
        {
            int product = products[j] * products[i-j];
            if(max < product)
                max = product;
        }
        products[i] = max;
    }

    max = products[length];
    delete products;
    return max;
}

int main()
{
    std::cout << maxProductAfterCutting_solution(50) << " 50米长应该为86093442" << std::endl;
}