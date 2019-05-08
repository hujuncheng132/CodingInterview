/*
面试题9：用两个栈实现队列
题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能
*/

#include<stack>
#include<iostream>
using namespace std;

//使用两个栈代替一个队列
//stack1用于存储入队数据，入队时直接把数据压入stack1
//stack2用于存储出队数据，出队时如果stack2为空，则将stack1中的数据依次全部弹出并压入stack2,这样stack2的顶部就是最先入队的数据
template <typename T> class Queue
{
public:
	void appendTail(T t);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
void Queue<T>::appendTail(T t)
{
	stack1.push(t);
}

template <typename T>
T Queue<T>::deleteHead()
{
	if(!stack2.empty())
	{	
		T t = stack2.top();
		stack2.pop();
		return t;
	}
	else if(!stack1.empty())
	{
		while(!stack1.empty())
		{
			T t = stack1.top();
			stack2.push(t);
			stack1.pop();
		}
		T t = stack2.top();
                stack2.pop();
                return t;
	}
	else
	{
		return NULL;
	}
}

int main()
{
	Queue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	char temp = queue.deleteHead();
	cout << temp << endl;
	temp = queue.deleteHead();
        cout << temp << endl;
	temp = queue.deleteHead();
        cout << temp << endl;
	queue.deleteHead();
        
	return 0;
}
