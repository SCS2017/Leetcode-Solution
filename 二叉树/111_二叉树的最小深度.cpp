/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。

示例:
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct TreeNode {
    int val;   
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
    int val;  
    Node *root; 
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* CreateTree(Node *root)//创建一棵二叉树
{
    Node *p1 = new Node(1);
    Node *p2 = new Node(2);
    Node *p3 = new Node(3);
    Node *p4 = new Node(4);
    Node *p5 = new Node(5);
    Node *p6 = new Node(6);
    Node *p7 = new Node(7);
    Node *p8 = new Node(8);
    Node *p9 = new Node(9);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p5->left = p6;
    p3->left = p7;
    p3->right = p8;
    p8->right = p9;
    root = p1;
    return p1;
}


void CreateTree(TreeNode* &root, int a[], int len, int index)
{
    if(index >= len){
        return;
    }
    root = new TreeNode;
    root->val = a[index];
    root->left = NULL;
    root->right = NULL;
    CreateTree(root->left, a, len, 2 * index + 1);
    CreateTree(root->right, a, len, 2 *index + 2);
}

void CreateBiTree(TreeNode* &T){ 
    //按先序输入二叉树中结点的值（一个字符），空格字符代表空树， 
    //构造二叉树表表示二叉树T。 
    char ch; 
    if((ch = getchar()) == '#') T = NULL;//其中getchar（）为逐个读入标准库函数 
    else{ 
        T = new TreeNode;//产生新的子树 
        T->val = ch;//由getchar（）逐个读入来 
        CreateBiTree(T->left);//递归创建左子树 
        CreateBiTree(T->right);//递归创建右子树 
    } 
}//CreateTree 

void PreOrder(TreeNode *node)
{
    if(node)
    {
        cout << node->val << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
}
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == 0){
            return 0;
        }
        if(root->left){
            if(root->right){
                return min(minDepth(root->left), minDepth(root->right)) + 1;
            }
            else{
                return minDepth(root->left) + 1;
            }
        }
        else if(root->right){
            return minDepth(root->right) + 1;
        }
        else{
            return 1;
        }
    }
};

int main()
{
    TreeNode* root;
    int arr[7] = {3, 9, 20, 30, 2, 15, 7};
    CreateTree(root, arr, 7, 0);
    PreOrder(root);
    cout << endl;
    Solution first;
    int result;
    result = first.minDepth(root);
    cout << result << endl;
    TreeNode* node;
    CreateBiTree(node);
    PreOrder(node);
    cout << endl;
    return 0;
}