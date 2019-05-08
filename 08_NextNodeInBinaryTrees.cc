/*
面试题8：二叉树的下一个结点
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
*/
#include<iostream>

using namespace std;

struct binaryTreeNode
{
	int m_value;
	binaryTreeNode *left;
	binaryTreeNode *right;
	binaryTreeNode *father;

	binaryTreeNode(int value)
	{
		m_value  = value;
		left = nullptr;
		right = nullptr;
		father = nullptr;
	}
};

//讨论中序遍历的下一节点要分为三种情况：
//1、该节点的右子树不为空，则下一节点为右子树的最左节点
//2、该节点的右子树为空且该节点是其父节点的左节点，则下一个节点就是其父节点
//3、该节点的右子树为空且该节点是其父节点的右节点，从下往上寻找其祖先节点中第一个是其父节点的左节点的节点，该节点的父节点就是下一个节点
binaryTreeNode* getNext(binaryTreeNode* pNode)
{
	if(pNode == nullptr)
		return nullptr;

	binaryTreeNode *pNext = nullptr;
	//右子树不为空，则下一个节点是右子树的最左节点
	if(pNode->right != nullptr)
	{
		binaryTreeNode *pRight = pNode->right;
		while(pRight->left != nullptr)
		{
			pRight = pRight->left;
		}
		pNext = pRight;//最左子节点
	}
	//右子树为空，则需要讨论pNode在左节点还是右节点
	//若为根节点且没有右子树，则没有下一个节点
	else if(pNode->father != nullptr)
	{	
		binaryTreeNode *pCurrent = pNode;
		binaryTreeNode *pFather = pNode->father;
		//如果为左节点且没有右子树，则下一个节点为父节点
		//如果为右节点且没有右子树，则向上遍历存在左子树的那个节点的父节点为下一个节点
		//两种情况汇总到一起表示在其从下往上回溯祖先节点的路径中，第一个发生"右拐"的节点
		while(pFather != nullptr &&  pCurrent == pFather->right)
		{
			pCurrent = pFather;
			pFather = pFather->father;
		}
		pNext = pFather;	
	}
	
	return pNext;
}



//=========================测试代码===============================
int main()
{
	binaryTreeNode root(0);
	binaryTreeNode node1(1);
	binaryTreeNode node2(2);
	binaryTreeNode node3(3);
	binaryTreeNode node4(4);
	binaryTreeNode node5(5);
	binaryTreeNode node6(6);
	binaryTreeNode node7(7);
	binaryTreeNode node8(8);

	root.left = &node1;
	root.right = &node2;
	
	node1.left = &node3;
	node1.right = &node4;
	node1.father = &root;
	
	node2.left = &node5;
        node2.right = &node6;
        node2.father = &root;

	node3.left = &node7;
        node3.right = &node8;
        node3.father = &node1;

	node4.father = &node1;

	node5.father = &node2;
	node6.father = &node2;

	binaryTreeNode *node = getNext(&node3);
	
	cout << node->m_value << endl;//输出结果应该为8

	return 0;
}	
