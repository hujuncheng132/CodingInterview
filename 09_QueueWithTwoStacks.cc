/*
面试题9：用两个栈实现队列
题目：用两个栈实现一个队列。
*/

#include <iostream>
#include <stack>
#include <string>

/*
使用两个栈代替一个队列
stack1用于存储入队数据，入队时直接把数据压入stack1
stack2用于存储出队数据，出队时如果stack2为空，则将stack1中的数据依次全部弹出并压入stack2,
这样stack2的顶部就是最先入队的数据
*/
template <typename T> 
class Queue
{
public:
	void push(T t); //在队尾添加一个元素
	void pop(); //弹出队首元素，但不返回
	T front(); //返回队首元素，但不弹出
	bool empty(); //判断队列是否为空
private:
	std::stack<T> stack1; //入队元素
	std::stack<T> stack2; //出队元素
};

template <typename T>
void Queue<T>::push(T t)
{
	stack1.push(t);
}

template <typename T>
void Queue<T>::pop()
{
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			T t = stack1.top();
			stack2.push(t);
			stack1.pop();
		}
	}
	stack2.pop();         
	
	return;
}

template <typename T>
T Queue<T>::front()
{
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			T t = stack1.top();
			stack2.push(t);
			stack1.pop();
		}
	}
	return stack2.top();         
}

template <typename T>
bool Queue<T>::empty()
{
	return stack1.empty() && stack2.empty();
}

int main()
{
	Queue<std::string> queue;
	queue.push("hello");
	queue.push("world");
	queue.push("!");
	while(!queue.empty())
	{
		std::string item = queue.front();
		queue.pop();
		std::cout << item << std::endl;
	}
        
	return 0;
}
