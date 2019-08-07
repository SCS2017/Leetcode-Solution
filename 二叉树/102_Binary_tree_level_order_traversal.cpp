/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* 非递归解法
建立一个queue，然后先把根节点放进去，这时候找根节点的左右两个子节点，这时候去掉根节点，
此时queue里的元素就是下一层的所有节点，用一个for循环遍历它们，然后存到一个一维向量里，
遍历完之后再把这个一维向量存到二维向量里，以此类推，可以完成层序遍历。
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if(!root){
            return res;
        }
        q.push(root); 
        while(!q.empty()){
            vector<int> tmp;
            int size = q.size();
            for(int i = 0; i < size; ++i){
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);             
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

/*递归解法
核心就在于我们需要一个二维数组，和一个变量level，当level递归到上一层的个数，我们新建一个空层，继续往里面加数字，
*/
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        return res;
    }
    void levelorder(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root){
            return;
        }
        if(res.size() == level){
            res.push_back({});
        }
        res[level].push_back(root->val);
        if(root->left){
            levelorder(root->left, level + 1, res);
        }
        if(root->right){
            levelorder(root->right, level + 1, res);
        }
    }
};

int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* p1 = new TreeNode(9);
    TreeNode* p2 = new TreeNode(20);
    TreeNode* p3 = new TreeNode(15);
    TreeNode* p4 = new TreeNode(7);
    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;
    Solution1 fir;
    vector<vector<int>> res;
    res = fir.levelOrder(root);
    for(vector<vector<int>>::iterator it = res.begin(); it != res.end(); ++it){
        vector<int> tmp = *it;
        for(vector<int>::iterator itt = tmp.begin(); itt != tmp.end(); ++itt){
            cout << *itt << " ";
        }
        cout << endl;
    }
    return 0;
}