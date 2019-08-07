/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;   
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL){
            return res;
        }
        if(root->left == NULL && root->right == NULL){
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> leftRes = binaryTreePaths(root->left);
        for(int i = 0; i < leftRes.size(); ++i){
            res.push_back(to_string(root->val) + "->" + leftRes[i]);
        }
        vector<string> rightRes = binaryTreePaths(root->right);
        for(int i = 0; i < rightRes.size(); ++i){
            res.push_back(to_string(root->val) + "->" + rightRes[i]);
        }
        return res;
    }
};