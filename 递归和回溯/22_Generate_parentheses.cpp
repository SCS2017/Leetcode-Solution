/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include <iostream>
#include <vector>

using namespace std;

/*
分析：关键：当前位置左括号不少于右括号
图是什么？
  节点：目前位置左括号和右括号数(x, y)(x >= y)
  边：从(x, y)到(x + 1, y)和(x, y + 1)
  x == y时没有(x, y + 1)这条边
解是什么？
  从(0, 0)出发到(n, n)的全部路径
*/
/*
DFS 记录什么
左右括号的个数
当前的"部分解"
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        help(n, 0, 0, "", answer);
        return answer;
    }
    void help(int n, int x, int y, string now, vector<string>& answer){
        if(y == n){
            answer.push_back(now);
        }
        if(x < n){
            help(n, x + 1, y, now + "(", answer);
        }
        if(y < x){
            help(n, x, y + 1, now + ")", answer);
        }
    }
};


/*
定义两个变量left和right分别表示剩余左右括号的个数，如果在某次递归时，左括号的个数大于右括号的个数，
说明此时生成的字符串中右括号的个数大于左括号的个数，即会出现')('这样的非法串，所以这种情况直接返回，不继续处理。
如果left和right都为0，则说明此时生成的字符串已有3个左括号和3个右括号，且字符串合法，则存入结果中后返回。
如果以上两种情况都不满足，若此时left大于0，则调用递归函数，注意参数的更新，若right大于0，则调用递归函数，同样要更新参数。
*/
class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        dfs(n, n, "", answer);
        return answer;
    }
    void dfs(int left, int right, string out, vector<string>& ans){
        if(left > right)
            return;
        if(left == 0 && right == 0)
            ans.push_back(out);
        else{
            if(left > 0)
                dfs(left-1, right, out+"(", ans);
            if(right > 0)
                dfs(left, right-1, out+")", ans);
        }
    }
};

int main()
{
    int n;
    while(cin >> n){
        Solution fir;
        vector<string> res = fir.generateParenthesis(n);
        for(int i = 0; i < res.size(); ++i){
            cout << res[i] << endl;
        }
        cout << res.size() << endl;
    }
    return 0;
}