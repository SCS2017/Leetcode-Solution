/*
Given a binary tree, find the length of the longest path where each node in the path has 
the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:
Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:
2

Example 2:
Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:
2
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//节点结构体
struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int value):value(value), left(NULL), right(NULL){}
};

class Solution {
public: 
    int longestUnivaluePath(Node *node) {
        if(!node) return 0;
        int res = 0;
        helper(node, node, res);
        return res;
    }
    int helper(Node *node, Node *parent, int& res){
        if(!node) return 0;
        int left = helper(node->left, node, res);
        int right = helper(node->right, node, res);
        left = (node->left && node->value == node->left->value) ? left + 1: 0;
        right = (node->right && node->value == node->right->value) ? right + 1: 0;
        res = max(res, left + right);
        return max(left, right);
    }
};

//直接递归
class Solution {
public:
    int longestUnivaluePath(Node* root) {
        if (!root) return 0;
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(sub, helper(root->left, root->value) + helper(root->right, root->value));
    }
    int helper(Node* node, int parent) {
        if (!node || node->value != parent) return 0;
        return 1 + max(helper(node->left, node->value), helper(node->right, node->value));
    }
};


