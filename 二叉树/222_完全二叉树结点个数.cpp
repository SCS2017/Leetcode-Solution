/*
给定完全二叉树，求其结点的个数

Example:
Input: 
    1
   / \
  2   3
 / \  /
4  5 6
Output: 6
*/

#include <iostream>
#include <math.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//开始我是直接递归左子树和右子树，然后将二者的结点数相加再加1，但是这样做会超时
//下面的做法是先求左子树和右子树的高度，如果两者相等，则此完全二叉树为满二叉树，直接求出结点个数pow(2, leftH) - 1
//如果不是满二叉树，再递归。这样做可以通过
class Solution {
public:
    int countNodes(TreeNode* root) {
        int leftH = LeftHeight(root);
        int rightH = RightHeight(root);
        if(leftH == rightH){
            return pow(2, leftH) - 1; 
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
private:
    int LeftHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        return LeftHeight(root->left) + 1;
    }
    int RightHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        return RightHeight(root->right) + 1;
    }
};

int main()
{
    return 0;
}