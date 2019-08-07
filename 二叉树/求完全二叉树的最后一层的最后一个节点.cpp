/*
阿里面试题之求完全二叉树的最后一层的最后一个节点
*/

#include <bits/stdc++.h>

using namespace std;

/*
思路：类似于二分查找，首先遍历最左分支，求出二叉树的高度；然后对于每个子树的根节点，先从他的右子树开始，
沿着左分支一直走到最后一层，如果深度等于树的深度且该最后节点右边没有节点，则为所求；
否则，右侧有节点，则遍历右子树，深度小于树的深度，则遍历左子树。时间复杂度是O(logn)
*/

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
 
TreeNode* getLastNode(TreeNode* root)
{
	if(!root || (!root->left && !root->right))return root;
	int depth = 0;
	TreeNode* curNode = root;
	while(curNode)	//计算二叉树的深度
	{
		depth++;
		curNode = curNode->left;
	}
	int level = 0,tmpDepth = 0;
	while(root)
	{
		level++;	//当前遍历到哪一层,根节点是第一层
		if(level == depth)break;	//防止右子树为空
		curNode = root;
		if(curNode->right)
		{
			TreeNode* pCur = curNode;	//当前节点的父节点
			curNode = curNode->right;
			tmpDepth = level + 1;
			while(curNode->left)
			{
				tmpDepth++;
				pCur = curNode;
				curNode = curNode->left;
			}
			if(tmpDepth < depth)root = root -> left;	//二分查找左子树
			else if(!pCur->right || pCur->right == curNode)return curNode;
			else root = root->right;	//二分查找右子树
		}
		else root = root->left;
	}
	return root;
}
/*
如果二叉树的节点个数是已知的为N，则不断除以2，记录奇偶性，然后反过来从根出发，偶则向左，奇则向右，一直到底就找到了。
时间复杂度O(logN)，例如，如果N=9,则奇偶性是[奇、偶、偶]反过来从根节点就是左->左->右
*/

int main(){
    TreeNode* root = new TreeNode(1);
	TreeNode* p1 = new TreeNode(2);
	TreeNode* p2 = new TreeNode(3);
	TreeNode* p3 = new TreeNode(4);
	TreeNode* p4 = new TreeNode(5);
	// TreeNode* p5 = new TreeNode(6);
	// TreeNode* p6 = new TreeNode(7);
	root->left = p1;
	root->right = p2;
	p1->left = p3;
	p1->right = p4;
	// p2->left = p5;
	TreeNode* lastNode = getLastNode(root);
	cout << lastNode->val << endl;
    return 0;
}
