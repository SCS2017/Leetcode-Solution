/* 
前序：1, 2, 3, 4, 5, 6（根左右）
中序：3, 2, 4, 1, 6, 5（左根右）
后序：3, 4, 2, 6, 5, 1（左右根） 
1、先说根据前序中序求后序，前序总是沿着根往树的左边一直跑，所以前序遍历的前面肯定是根节点 
中序则是按照：左—–根—–右 的顺序排列，其中左，右子树按照同样的结构，所以我们可以从前序遍历的根节点入手，
迅速定位中序序列的结构中左子树和右子树部分，而后序遍历无非就是：左子树，右子树，访问根。 
*/

#include <bits/stdc++.h>
using namespace std;

void postTraversal(vector<int> pre, vector<int> in){
    if(pre.empty() || pre.size() != in.size())
        return;
    int root = pre[0];
    auto pos = find(in.begin(), in.end(), root);
    int leftSize = pos - in.begin();
    postTraversal(vector<int>(pre.begin()+1, pre.begin()+1+leftSize), 
                  vector<int>(in.begin(), pos));
    postTraversal(vector<int>(pre.begin()+1+leftSize, pre.end()), 
                  vector<int>(pos+1, in.end()));
    cout << root << " ";
}

/* 
再说根据后序中序输出前序，中序已经说过了，中序是按照：左—–根—–右 的顺序排列，其中左，右子树按照同样的结构，
后序则是按照：左——右——根的顺序，其中左，右 按照同样的结构，后序遍历的最后肯定是根节点，
所以我们可以从后序序列的根节点入手，把中序给分割出左 右 根的部分，然后就可以得到前序遍历啦！ 
*/

void preTraversal(vector<int> post, vector<int> in){
    if(post.empty() || post.size() != in.size())
        return;
    int root = post.back();
    auto pos = find(in.begin(), in.end(), root);
    int leftSize = pos - in.begin();
    cout << root << " ";
    preTraversal(vector<int>(post.begin(), post.begin()+leftSize), 
                  vector<int>(in.begin(), pos));
    preTraversal(vector<int>(post.begin()+leftSize, post.end()-1), 
                  vector<int>(pos+1, in.end()));
}

int main(){
    vector<int> pre{1, 2, 3, 4, 5, 6};
    vector<int> in{3, 2, 4, 1, 6, 5};
    postTraversal(pre, in);
    cout << endl;
    vector<int> post{3, 4, 2, 6, 5, 1}; 
    vector<int> in1{3, 2, 4, 1, 6, 5};
    preTraversal(post, in1);
    cout << endl;
    return 0;
}
