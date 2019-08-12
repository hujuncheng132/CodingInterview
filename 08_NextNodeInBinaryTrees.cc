/*
面试题8：二叉树的下一个结点
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
*/
#include<iostream>

//二叉树结点定义
struct binaryTreeNode
{
	int value;
	binaryTreeNode *pLeft;
	binaryTreeNode *pRight;
	binaryTreeNode *pFather;

	binaryTreeNode(int val)
	{
		value = val;
		pLeft = nullptr;
		pRight = nullptr;
		pFather = nullptr;
	}
};

//讨论中序遍历的下一节点要分为三种情况：
//1、该节点的右子树不为空，则下一节点为右子树的最左节点
//2、该节点的右子树为空且该节点是其父节点的左节点，则下一个节点就是其父节点
//3、该节点的右子树为空且该节点是其父节点的右节点，从下往上寻找其祖先节点中第一个是其父节点的左节点的节点，该节点的父节点就是下一个节点
binaryTreeNode* getNext(binaryTreeNode* pNode)
{
	// 参数检查
	if(pNode == nullptr)
		return nullptr;

	// 记录pNode的下一个节点
	binaryTreeNode *pNext = nullptr;
	
	//右子树不为空，则下一个节点是右子树的最左节点
	if(pNode->pRight != nullptr)
	{
		pNext = pNode->pRight;
		while(pNext->pLeft != nullptr)
			pNext = pNext->pLeft; // 右子树的最左子节点
	}
	//右子树为空，则需要讨论pNode是左节点还是右节点
	//如果右子树为空，且该节点为根节点，则该节点已经是中序遍历的最后一个结点，返回nullptr
	else if(pNode->pFather != nullptr)
	{	
		binaryTreeNode *pCurrent = pNode;
		binaryTreeNode *pFather = pNode->pFather;
		/*
		如果为左节点且没有右子树，则下一个节点为父节点
		如果为右节点且没有右子树，则向上回溯到某一节点为左节点，该节点的父节点则为下一个节点
		如果回溯到了父节点还没有找到，则没有下一个节点
		两种情况汇总到一起表示在其从下往上回溯祖先节点的路径中，第一个发生"右拐"的节点
		*/
		// “pFather == nullptr”表示回溯到父节点仍然没有找到“右拐”的点，则说没有下一个节点
		// "pCurrent == pFather->pLeft"表示已经找到了那个"右拐"的节点
		while(pFather != nullptr &&  pCurrent != pFather->pLeft) 
		{
			// 回溯，将父节点置为当前结点，然后父节点上移
			pCurrent = pFather;
			pFather = pFather->pFather;
		}
		pNext = pFather;	
	}
	
	return pNext;
}


int main()
{
	std::cout << "中序遍历为：4 7 2 1 5 3 8 6" << std::endl;

	binaryTreeNode *p1 = new binaryTreeNode(1);
	binaryTreeNode *p2 = new binaryTreeNode(2);
	binaryTreeNode *p3 = new binaryTreeNode(3);
	p1->pLeft = p2;
	p1->pRight = p3;
	p2->pFather = p1;
	p3->pFather = p1;
	binaryTreeNode *p4 = new binaryTreeNode(4);
	binaryTreeNode *p5 = new binaryTreeNode(5);
	binaryTreeNode *p6 = new binaryTreeNode(6);
	p2->pLeft = p4;
	p3->pLeft = p5;
	p3->pRight = p6;
	p4->pFather = p2;
	p5->pFather = p3;
	p6->pFather = p3;
	binaryTreeNode *p7 = new binaryTreeNode(7);
	binaryTreeNode *p8 = new binaryTreeNode(8);
	p4->pRight = p7;
	p6->pLeft = p8;
	p7->pFather = p4;
	p8->pFather = p6;

	std::cout << getNext(p3)->value << " 8 " << std::endl;
	std::cout << getNext(p2)->value << " 1 " << std::endl;
	return 0;
}	