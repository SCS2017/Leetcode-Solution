/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include <iostream>
#include <vector>

using namespace std;

/*递归：耗时但也能通过
思路：空树和只有根节点时，也为BST。对于一点i，当其为根节点时，左子树的节点的个数为i-1，（为1,...i-1）,
右子树的个数为n-i（为，i+1,...n）。对一个根来说，唯一二叉树的个数为左子树结点的个数乘以右子树的个数。
而根节点可以从1到n中选择
*/
class Solution1 {
public:
    int numTrees(int n) {
        if(n <= 1){
            return 1;
        }
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            sum += numTrees(i - 1) * numTrees(n - i);
        }
        return sum;
    }
};

/*
这是Catalan Number卡特兰数的一个例子。卡特兰数的的递推公式：
C[0] = 1, C[n + 1] = sum(i = 0 ~ n)C[i]C[n - i], n >= 0

*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n + 1);
        res[0] = 1;
        res[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 0; j < i; ++j){
                res[i] += res[j] * res[i - j - 1];
            }
        }
        return res[n];
    }
};

int main()
{
    int n;
    while(cin >> n){
        Solution fir;
        int ans = fir.numTrees(n);
        cout << ans << endl;
    }
    return 0;
}