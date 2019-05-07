/*
面试题7：重建二叉树
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
{1,2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
*/


#include<iostream>
#include <exception>

using namespace std;

struct binaryTreeNode
{
	int m_value;
	binaryTreeNode *left;
	binaryTreeNode *right;

	binaryTreeNode(int value)
	{
		m_value = value;
		left = nullptr;
		right = nullptr;
	}
};

//前序遍历中的第一个数就是根节点;
//通过在中序遍历中找到这个数，这个数前面的就是左子树的中序遍历，后面就是右子树的中序遍历
//再通过左子树和右子树的大小，在前序遍历中确定左子树的前序遍历，右子树的前序遍历
//然后递归进行操作，当前序和中序没有节点时，则说明已经是叶子节点了
binaryTreeNode* constructCore(int *preOrder,int *inOrder,int preStart,int preEnd,int inStart,int inEnd)
{
	int root_value = preOrder[preStart];
	binaryTreeNode *root =  new binaryTreeNode(root_value);
	
	int i = inStart;
	while(i <= inEnd && inOrder[i] != root_value)
		++i;
	int lenLeft = i - inStart;
	int lenRight = inEnd - i;
	
	if(lenLeft > 0)
		root->left = constructCore(preOrder,inOrder,preStart+1,preStart+lenLeft,inStart,inStart+lenLeft-1);
	if(lenRight > 0)
		root->right = constructCore(preOrder,inOrder,preStart+lenLeft+1,preEnd,inStart+lenLeft+1,inEnd);

	return root;

}

binaryTreeNode* construct(int *preOrder,int *inOrder,int length)
{
	if(preOrder == nullptr || inOrder == nullptr || length <= 0)
	{
		return nullptr;
	}
	
	return constructCore(preOrder,inOrder,0,length-1,0,length-1);
}

void preDisplay(binaryTreeNode *root)
{
	if(root != nullptr)
	{
		cout << root->m_value << " ";
		if(root->left != nullptr)
			preDisplay(root->left);
		if(root->right != nullptr)
                        preDisplay(root->right);
	}
	return;
}

void inDisplay(binaryTreeNode *root)
{
	if(root->left != nullptr)
		inDisplay(root->left);
	cout << root->m_value << " ";
	if(root->right != nullptr)
                        preDisplay(root->right);
	return;
}

void afterDisplay(binaryTreeNode *root)
{
        if(root->left != nullptr)
                inDisplay(root->left);
        if(root->right != nullptr)
                        preDisplay(root->right);
	cout << root->m_value << " ";
	
        return;
}

int main()
{
	int preOrder[] = {1,2,4,7,3,5,6,8};
	int inOrder[] = {4,7,2,1,5,3,6,8};
	
	binaryTreeNode *root = construct(preOrder,inOrder,8);
	inDisplay(root);
	cout << endl;
	cout << "{4,7,2,1,5,3,6,8}" << endl;
	preDisplay(root);
	cout << endl;
	cout << "{1,2,4,7,3,5,6,8}" << endl;
	return 0;
}
