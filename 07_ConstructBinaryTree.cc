/*
面试题7：重建二叉树（只有前序+中序或者后序+中序才能重建）
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
{1,2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则输出其后序遍历
*/
#include<iostream>
#include<stack>

//二叉树结点定义
struct binaryTreeNode
{
	int value;
	binaryTreeNode *pLeft;
	binaryTreeNode *pRight;

	binaryTreeNode(int val)
	{
		value = val;
		pLeft = nullptr;
		pRight = nullptr;
	}
};

//前序遍历中的第一个数就是根节点;
//通过在中序遍历中找到这个数，这个数前面的就是左子树的中序遍历，后面就是右子树的中序遍历
//再通过左子树和右子树的大小，在前序遍历中确定左子树的前序遍历，右子树的前序遍历
//然后递归进行操作，当前序和中序没有节点时，则说明已经是叶子节点了
binaryTreeNode* constructCore(int preOrder[],int inOrder[],int preStart,int preEnd,int inStart,int inEnd)
{
	int root_value = preOrder[preStart]; //前序遍历的第一个就是根节点的值
	binaryTreeNode *root = new binaryTreeNode(root_value);// 根据这个值新建一个根节点
	
	// 根据根节点的值在中序遍历中寻找它的位置
	int i = inStart;
	while(i <= inEnd && inOrder[i] != root_value)
		++i;
	int lenLeft = i - inStart;//得到根节点左子树的长度
	int lenRight = inEnd - i;//得到根节点右子树的长度
	
	// 然后递归在其左右子树的前序+中序遍历中寻找左右子树的根节点，并返回当前根节点的左右节点
	if(lenLeft > 0)
		root->pLeft = constructCore(preOrder,inOrder,preStart+1,preStart+lenLeft,inStart,inStart+lenLeft-1);
	if(lenRight > 0)
		root->pRight = constructCore(preOrder,inOrder,preEnd-lenRight+1,preEnd,inEnd-lenRight+1,inEnd);

	return root;

}

//前序遍历和中序遍历以数组的格式传入
binaryTreeNode* construct(int preOrder[],int inOrder[],int length)
{
	if(preOrder == nullptr || inOrder == nullptr || length <= 0)
	{
		return nullptr;
	}
	
	return constructCore(preOrder,inOrder,0,length-1,0,length-1);
}

// 前序遍历（递归）
void preDisplayRec(binaryTreeNode *root)
{
	if(root)
	{
		std::cout << root->value << " ";
		preDisplayRec(root->pLeft);
        preDisplayRec(root->pRight);
	}
}

// 前序遍历（非递归）
/*
前序遍历的访问顺序是“根左右”,
首先将根节点入栈，然后开始依次访问栈顶的节点，
对于每个栈顶的节点都视为根节点，访问完之后应该继续访问左右节点，
由于栈是先进后出，而我们需要先访问左再访问右，因此先将右节点入栈，再将左节点入栈
*/ 
void preDisplay(binaryTreeNode *root)
{
	std::stack<binaryTreeNode*> preStack;
	preStack.push(root);

	while(!preStack.empty())
	{
		binaryTreeNode* current = preStack.top();
		std::cout << current->value << " ";
		preStack.pop();

		//由于栈是先进后出，因此先将右节点压栈，再将左节点压栈（这样就能先访问左节点，再访问右节点）
		if(current->pRight)
			preStack.push(current->pRight);
		if(current->pLeft)
			preStack.push(current->pLeft);
	}
}

// 中序遍历（递归）
void inDisplayRec(binaryTreeNode *root)
{
	if(root)
	{
		inDisplayRec(root->pLeft);
		std::cout << root->value << " ";
		inDisplayRec(root->pRight);
	}	
}

// 中序遍历（非递归）
/* 
中序遍历的访问顺序是“左根右”,
首先访问的是左节点，左节点中最先访问的是最左节点，因此依次将左节点入栈，直到最左节点，
如果current为空，表示此时栈顶的已经的最左节点，故弹出栈顶节点并访问，
如果该左节点有右子树，则需要访问右子树，但是访问右子树又要执行一次上述的入栈操作来访问右子树的最左节点，
如果该左节点没有右子树，表示为叶子节点，那么下一个需要访问的就是其父节点，即此时栈顶的元素
*/
void inDisplay(binaryTreeNode *root)
{
	std::stack<binaryTreeNode*> inStack;
	binaryTreeNode* current = root;
	
	while(current != nullptr || !inStack.empty())
	{
		// 依次将左节点入栈，按照栈先进后出的顺序，最左子节点放在栈顶
		if(current != nullptr)
		{
			inStack.push(current);
			current = current->pLeft;
		}
		// 如果currentp为空，表示此时栈顶的已经是最左子节点，故访问之
		else
		{
			current = inStack.top();
			std::cout << current->value << " ";
			inStack.pop();
			current = current->pRight;
		}
	}
}

// 后序遍历（递归）
// 
void afterDisplayRec(binaryTreeNode *root)
{
        if(root)
        {
			afterDisplayRec(root->pLeft);
			afterDisplayRec(root->pRight);
		std::cout << root->value << " ";
        }
}

// 后序遍历（非递归）
/* 
后序遍历的访问顺序是左右根，可以看成”根右左“再翻转一下，
“根右左”可以借鉴前序遍历“根左右”的方法
*/
void afterDisplay(binaryTreeNode *root)
{
	std::stack<binaryTreeNode*> afterStack1; //用于执行“根右左”
	std::stack<binaryTreeNode*> afterStack2; //用于将“根右左”翻转成“左右根”
	afterStack1.push(root);

	while(!afterStack1.empty())
	{
		binaryTreeNode* current = afterStack1.top();
		afterStack1.pop(); 
		// 在前序遍历时，原本是进行访问，这里先进行入栈，最后再访问，正好把顺序颠倒，变成“左右根”
		afterStack2.push(current);

		// 这里和前序遍历部分有所不同，顺序为“根右左”，则需要先将左入栈，再入栈右
		if(current->pLeft)
			afterStack1.push(current->pLeft);
		if(current->pRight)
			afterStack1.push(current->pRight);
	}

	while(!afterStack2.empty())
	{
		std::cout << afterStack2.top()->value << " ";
		afterStack2.pop();
	}

}

int main()
{
	int preOrder[] = {1,2,4,7,3,5,6,8};
	int inOrder[] = {4,7,2,1,5,3,8,6};
	
	std::cout << "前序遍历为：1 2 4 7 3 5 6 8" << std::endl;
	std::cout << "中序遍历为：4 7 2 1 5 3 8 6" << std::endl;
	std::cout << "后序遍历为：7 4 2 5 8 6 3 1" << std::endl;
	binaryTreeNode *root = construct(preOrder,inOrder,8);
	preDisplay(root);
	std::cout << std::endl;
	inDisplay(root);
	std::cout << std::endl;
	afterDisplay(root);
	std::cout << std::endl;
	
	binaryTreeNode *p1 = new binaryTreeNode(1);
	binaryTreeNode *p2 = new binaryTreeNode(2);
	binaryTreeNode *p3 = new binaryTreeNode(3);
	p1->pLeft = p2;
	p1->pRight = p3;
	binaryTreeNode *p4 = new binaryTreeNode(4);
	binaryTreeNode *p5 = new binaryTreeNode(5);
	binaryTreeNode *p6 = new binaryTreeNode(6);
	p2->pLeft = p4;
	p3->pLeft = p5;
	p3->pRight = p6;
	binaryTreeNode *p7 = new binaryTreeNode(7);
	binaryTreeNode *p8 = new binaryTreeNode(8);
	p4->pRight = p7;
	p6->pLeft = p8;
	preDisplay(p1);
	std::cout << std::endl;
	inDisplay(p1);
	std::cout << std::endl;
	afterDisplay(p1);
	std::cout << std::endl;
	return 0;
}
