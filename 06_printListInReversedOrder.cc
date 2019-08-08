/*
面试题6：从尾到头打印链表
题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
*/
#include <iostream>
#include <stack>

// 链表节点结构体
struct listNode
{
	int value;
	listNode *pNext;
	
	listNode(int val = 0,listNode *p = nullptr):value(val),pNext(p) { }
};

//方法一：利用栈先进后出的特点
void printListReversingly_Iteratively(listNode *pHead)
{
	//利用栈实现先进后出
	std::stack<listNode*> nodeStack;
	listNode *pNode = pHead;
	// 从头到尾遍历链表，依次入栈
	while(pNode != nullptr)
	{
		nodeStack.push(pNode);
		pNode = pNode->pNext;
	}
	// 从栈中依次弹出元素,元素的弹出顺序正好和加入时的顺序相反
	while(!nodeStack.empty())
	{
		pNode = nodeStack.top();
		std::cout << pNode->value << " ";
		nodeStack.pop();
	}
}

//方法二：利用递归
void printListReversingly_Recursively(listNode *pHead)
{
	if(pHead != nullptr)
	{
		if(pHead->pNext != nullptr)
		{
			printListReversingly_Recursively(pHead->pNext);
		}
		std::cout << pHead->value << " ";
	}
}

int main()
{
	listNode *pHead = new listNode(0);
	listNode *p = pHead;
	for(int i = 1;i < 10;++i)
	{
		p->pNext = new listNode(i);
		p = p->pNext; 
	}
	std::cout << "链表的顺序为：0 1 2 3 4 5 6 7 8 9" << std::endl;
	std::cout << "链表的逆序为：";
	printListReversingly_Iteratively(pHead);
	std::cout << std::endl;
	std::cout << "链表的逆序为：";
        printListReversingly_Recursively(pHead);
        std::cout << std::endl;
	
	return 0;
}




