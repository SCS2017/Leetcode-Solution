/* 
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true

示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false

示例 3:
输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false

示例 4:
输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/* 
建立一个hashmap，模式串中每个字符与每个单词的映射，并且这个映射必须是一对一的。
不能'a'和'b'同时对应'dog'，也不能'a'同时对应到'dog'和'cat'，
所以我们在碰到一个新字符时，首先检查其是否在HashMap中出现，若出现，其映射的单词若不是此时对应的单词，则返回 false。
如果没有在 HashMap 中出现，我们还要遍历一遍 HashMap，看新遇到的单词是否已经是其中的映射，
若已经有其他映射，直接返回 false，如果没有，再跟新遇到的字符建立映射。
最后循环退出后，要检查此时的 i 是否和 n 相同，这是检查一对一映射的最后一步，
因为当str中的单词处理完了之后，pattern中就不能有多余的字符了
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for(string word; in >> word; ++i){
            if(i >= n)
                continue;
            if(m.count(pattern[i])){
                if(m[pattern[i]] != word)
                    return false;
            }
            else{
                for(auto t: m){
                    if(t.second == word)
                        return false;
                }
                m[pattern[i]] = word;
            }
        }
        return (i == n);
    }
};

/* 
当然这道题也可以用两个 HashMap 来完成，分别将字符和单词都映射到当前的位置加1，注意这里需要加1就是为了避免默认映射值0，
因为 C++ 中的 HashMap 的机制是若访问一个不存在的 key 值，会默认建立一个映射值为0的映射。
那么我们在遇到新字符和单词时，首先看i是否已经是n了，若相等了，说明此时pattern中的字符已经用完了，而str中还有多余的单词，
这样是无法建立一对一映射的，直接返回 false。
还有当两个 HashMap 的映射值不相同时也返回 false，否则我们同时建立单词和 pattern 字符和当前位置加1之间的映射，
循环推出后还是要检测 i 是否和 n 相等
*/
class Solution1 {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for(string word; in >> word; ++i){
            if(i == n || m1[pattern[i]] != m2[word])
                return false;
            m1[pattern[i]] = m2[word] = i+1;
        }
        return (i == n);
    }
};


int main(){
    
    return 0;
}
