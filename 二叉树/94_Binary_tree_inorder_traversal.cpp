/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

#include <iostream>
#include <stack>
#include <queue>
#include <stdlib.h>
using namespace std;

//节点结构体
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value):value(value), left(NULL), right(NULL){}
};

//递归
class Solution1 {
public:
    void help(TreeNode* root, vector<int>& res){
        if(root){
            if(root->left){
                help(root->left, res);
            }
            res.push_back(root->value);
            if(root->right){
                help(root->right, res);
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        help(root, res);
        return res;
    }
};

//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > nstack;
        TreeNode* temp = root;
        while(temp || !nstack.empty()){
            if(temp){
                nstack.push(temp);
                temp = temp->left;
            }
            else{
                temp = nstack.top();
                res.push_back(temp->value);
                nstack.pop();
                temp = temp->right;
            }
        }
        return res;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* p1 = new TreeNode(2);
    TreeNode* p2 = new TreeNode(3);
    root->right = p1;
    p1->left = p2;
    Solution fir;
    vector<int> ans;
    ans = fir.inorderTraversal(root);
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}