/*
面试题6：从尾到头打印链表
题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
*/

#include<iostream>
#include<stack>

using namespace std;

struct listNode
{
	int m_value;
	listNode *next;
	
	listNode(int value)
	{
		m_value = value;
		next = nullptr;
	}
};

//利用栈从头到尾打印链表
void printListReverst(listNode *pHead)
{
	stack<listNode*> nodeStack;
	listNode* pointer = pHead;
	while(pointer != nullptr)
	{
		cout << pointer->m_value << " ";
		nodeStack.push(pointer);
		pointer = pointer->next;
	}
	cout << endl;

	while(!nodeStack.empty())
	{
		pointer = nodeStack.top();
		cout << pointer->m_value << " ";
		nodeStack.pop();
	}
	cout << endl;
	
	return;
}

int main()
{
	listNode node1(1);
	listNode node2(2);		
	listNode node3(3);
	listNode node4(4);
	listNode node5(5);
	listNode *pHead = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	printListReverst(pHead);
	
	return 0;
}
