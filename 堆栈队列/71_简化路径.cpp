/*
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。

在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；
两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径

请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。
最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。

示例 1:
输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。

示例 2:
输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。

示例 3:
输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。

示例 4：
输入："/a/./b/../../c/"
输出："/c"
*/

#include <bits/stdc++.h>
using namespace std;

/*
中间是"."的情况直接去掉，是".."时删掉它上面挨着的一个路径，而下面的边界条件给的一些情况中可以得知，
如果是空的话返回"/"，如果有多个"/"只保留一个。
那么我们可以把路径看做是由一个或多个"/"分割开的众多子字符串，把它们分别提取出来一一处理即可
*/
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        int i = 0;
        while(i < path.size()){
            while(path[i] == '/' && i < path.size()) 
                ++i;
            if(i == path.size())
                break;
            int start = i;
            while(path[i] != '/' && i < path.size()) 
                ++i;
            int end = i - 1;
            string tmp = path.substr(start, end - start + 1);
            if(tmp == ".."){
                if(!vec.empty())
                    vec.pop_back();
            }
            else if(tmp != ".")
                vec.push_back(tmp);
        }
        string res;
        if(vec.empty())
            return "/";
        for(int i = 0; i < vec.size(); ++i)
            res += "/" + vec[i];
        return res;        
    }
};

//使用stringstream分割字符串，将结果存到栈中，如果当前字符串为"."或者空，
//不进行任何操作，如果当前字符串为".."则栈中弹出一个元素，否则进栈。
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string> st;
        string tmp;
        while (getline(ss, tmp, '/')) {
            if (tmp == "." || tmp == "") 
                continue;
            else if (tmp == "..") {
                if (!st.empty())
                    st.pop();
            } 
            else 
                st.push(tmp);
        }
        string res = "";
        if (st.empty()) 
            return "/";
        while (!st.empty()) {
            res = st.top() + res;
            res = "/" + res;
            st.pop();
        }
        return res;
    }
};