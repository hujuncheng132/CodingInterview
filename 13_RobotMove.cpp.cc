// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
#include <iostream>

/*
threshold为k值
rows和cols为矩形方格的行和列
*/
int moveCount(int threshold,int rows,int cols)
{
    bool* visit = new bool[rows*cols];
    // 默认所有的位置都不可访问
    for(int row = 0;row < rows;++row)
    {
        for(int col = 0;col < cols;++col)
            visit[row*cols+col] = false;
    }

    int count = moveCountCore(threshold,visit,rows,cols,0,0);

    delete visit;
    return count;
}

// 用于统计从(row,col)这个位置出发可以到达的格子数
int moveCountCore(int threshold,bool* visit,int rows,int cols,int row,int col)
{
    int count = 0;
    if(check(threshold,visit,rows,cols,row,col))
    {
        visit[row*cols+col] = true;
        count = moveCountCore(threshold,visit,rows,cols,row,col-1) 
                + moveCountCore(threshold,visit,rows,cols,row,col+1)
                + moveCountCore(threshold,visit,rows,cols,row-1,col)
                + moveCountCore(threshold,visit,rows,cols,row+1,col)
                + 1;
    }
    return count;
}

// 检查(row,col)点是否符合要求
bool check(int threshold,bool* visit,int rows,int cols,int row,int col)
{
    if(row >= 0 && row < rows && col >= 0 && col < cols && !visit[row*cols+col] &&
        (getGigitSum(col) + getGigitSum(col) <= threshold))
        return true;
    return false;
}

// 求一个整数各个位置上的数相加之和
int getGigitSum(int number)
{
    int sum = 0;
    while(number > 0)
    {
        sum += number % 10;
        number = number / 10;
    }
    return sum;
}