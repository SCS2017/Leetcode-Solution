/* 

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;   
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        res = root->val;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);
        res = max(res, root->val+left+right);
        return root->val + max(left, right);
    }
    int res;
};

int main(){
    
    return 0;
}
