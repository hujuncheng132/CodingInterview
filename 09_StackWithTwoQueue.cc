/*
面试题9：用两个队列实现栈
题目：用两个队列实现一个栈。
*/
#include<iostream>
#include<queue>

/*
通过两个队列实现一个栈
入栈时始终把元素添加到非空的队列末尾，保持另一个队列为空，
出栈时将非空队列的元素依次加入到另一个空队列（除开最后一个元素），并返回最后一个元素作为栈顶元素
*/

template <typename T>
class Stack
{
public:
    void push(T t);
    T top();
    void pop();
    bool empty();
private:
    std::queue<T> queue1;
    std::queue<T> queue2;
    bool flag = true; //flag为true表示queue1为空，为false表示queue2为空
};

template <typename T>
void Stack<T>::push(T t)
{
    if(flag)
        queue2.push(t);
    else
        queue1.push(t);
}

template <typename T>
T Stack<T>::top()
{
    if(flag)
        return queue2.back();
    else
        return queue1.back();
}

template <typename T>
void Stack<T>::pop()
{
    if(flag)
    {
        T t;
        while(!queue2.empty())
        {
            t = queue2.front();
            queue2.pop();
            if(!queue2.empty()) //队列2的最后一个元素不用再进入队列1
                queue1.push(t);
        }
        flag = false;
    }
    else
    {
        T t;
        while(!queue1.empty())
        {
            t = queue1.front();
            queue1.pop();
            if(!queue1.empty()) //队列1的最后一个元素不用再进入队列2
                queue2.push(t);
        }
        flag = true;
    }
}

template <typename T>
bool Stack<T>::empty()
{
	if(flag)
        return queue2.empty();
    else
        return queue1.empty();
}

int main()
{
	Stack<std::string> stack;
	stack.push("hello");
	stack.push("world");
	stack.push("!");
	while(!stack.empty())
	{
		std::string item = stack.top();
		stack.pop();
		std::cout << item << std::endl;
	}
        
	return 0;
}