/* 
给定一棵二叉树，找到这棵树最中最后一行中最左边的值。

样例
样例1:
输入:{2,1,3}
输出:1
解释：
  2
 /  \
1   3

样例2:
输人:{1,2,3,4,5,6,#,#,7}
输出:7
解释：
         1
        /  \
      2     3
    /  \    / 
  4     5 6
   \
    7
注意事项
你可以假设树（即给定的根节点）不是NULL。
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 开始是使用层序遍历，记录每层结点的值，其实不需要，只要维护每层的第一个节点的值就好了
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > que;
        que.push(root);
        int res = root->val;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; ++i){
                TreeNode* t = que.front();
                que.pop();
                if(i == 0)
                    res = t->val;
                if(t->left)
                    que.push(t->left);
                if(t->right)
                    que.push(t->right);
            }
        }
        return res;
    }
};

// 从右往左层序遍历，这样返回最后一个结点的值就好了
class Solution1 {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()) {
            root = q.front(); 
            q.pop();
            if(root->right) 
                q.push(root->right);
            if(root->left) 
                q.push(root->left);
        }
        return root->val;
    }
};


int main(){
    
    return 0;
}