/* 
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//一个节点的最大直径 = 它左树的高度 +  它右树的高度
//然后其实就是遍历每个节点，找出所有节点中的直径的最大值即可。

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        helper(root);
        return res;
    }
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        res = max(left+right, res);
        return max(left, right)+1;
    }
private:
    int res = 0;
};
