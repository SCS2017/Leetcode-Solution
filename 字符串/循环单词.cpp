/* 
如果一个单词通过循环右移获得的单词，我们称这些单词都为一种循环单词。 例如：picture 和 turepic 就是属于同一种循环单词。 
现在给出n个单词，需要统计这个n个单词中有多少种循环单词。

输入描述:
输入包括n+1行：

第一行为单词个数n(1 ≤ n ≤ 50)
接下来的n行，每行一个单词word[i]，长度length(1 ≤ length ≤ 50)。由小写字母构成

输出描述:
输出循环单词的种数

示例1
输入
5
picture
turepic
icturep
word
ordw

输出
2
*/

#include <bits/stdc++.h>
using namespace std;


/* 
建立set后边添加边移除，思路是遍历words，对于每一个word先在set中删除所有关于此word的所有翻转字符，然后再添加一个，
这样如果遍历到相同字符得来的翻转字符则总会只添加一个。

其中求word所有的翻转字符，有一个简单的方法：可以先将w变成w+w，然后求新字符串的substr。
这样不需要考虑前后拼接问题，代码更简练。

*/
int main(){
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i = 0; i < n; ++i)
        cin >> strs[i];
    set<string> s;
    for(auto str: strs){
        string tmp = str + str;
        for(int i = 0; i < str.size(); ++i)
            s.erase(tmp.substr(i, str.size()));
        s.insert(str);
    }
    cout << s.size() << endl;
    return 0;
}
