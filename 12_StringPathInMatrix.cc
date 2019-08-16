// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H
#include <iostream>
#include <string>

// 用于判断从(row,col)这个位置开始，是否能在矩阵matrix中匹配到剩下的字符串str[pathlength:]
bool hasPathCore(const char* matrix,const char *str,int rows,int cols,int row,int col,int& pathLength,bool* visited)
{
    // 如果此时已经匹配到最后一个字符，则表示已经匹配完成，返回true
    if(str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    // 接下来判断(row,col)这个位置是否和str[pathlength]相等，
    // 如果相等，则递归检测(row,col)上下左右四个点
    if(row >= 0 && row < rows && col >= 0 && col < cols && !visited[row*cols+col] && matrix[row*cols+col] == str[pathLength])
    {
        ++pathLength; // 已匹配的字符增加1
        visited[row*cols+col] = true; // (row,col)位置已被占用

        // 递归判断上下左右四个点
        hasPath = hasPathCore(matrix,str,rows,cols,row-1,col,pathLength,visited)
                || hasPathCore(matrix,str,rows,cols,row,col-1,pathLength,visited)
                || hasPathCore(matrix,str,rows,cols,row+1,col,pathLength,visited)
                || hasPathCore(matrix,str,rows,cols,row,col+1,pathLength,visited);
        // 如果四个点都不符合，则应该退回上一个字符str[pathlength-1]，选择其后面的位置进行匹配
        if(!hasPath)
        {
            --pathLength; 
            visited[row*rows+col] = false;
        }
    }

    return hasPath;
}

bool hasPath(const char* matrix,int rows,int cols,const char *str)
{
    // 参数有效性检测
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;

    int pathLength = 0;// 记录此时已经找到第几个字符
    bool *visited = new bool[rows*cols]; // 统计哪些位置已经被占用了
    for(int i = 0;i < rows*cols;++i)
    {
        visited[i] = false;
    }

    // 首先选取一个出发点
    for(int row = 0;row < rows;++row)
    {
        for(int col = 0;col < cols;++col)
        {
            // 如果从（row,col）出发能够匹配完成，则返回true,否则选取下一个点作为出发点
            if(hasPathCore(matrix,str,rows,cols,row,col,pathLength,visited)) 
                return true;
        }
    }

    delete visited;
    return false;
}

int main()
{
    const char matrix[3][4] = {{'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'}};
    std::cout << "字符矩阵为：" << std::endl;
    for(int i = 0;i < 3;++i)
    {
        for(int j = 0;j < 4;++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "请输入待匹配的字符串：";
    std::string str;
    std::cin >> str;
    std::cout << "是否存在" << str << "这条路径?" 
    << (hasPath(reinterpret_cast<const char*>(matrix),3,4,str.c_str()) ? "是" : "否") << std::endl;

    return 0;



}