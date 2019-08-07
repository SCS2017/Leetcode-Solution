/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
(2, "abc"));(3, "def"));(4, "ghi"));(5, "jkl"));
(6, "mno"));(7, "pqrs"));(8, "tuv"));(9, "wxyz"));

示例:
输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
/*
主要的思路是将输入的数字字符串从后向前遍历，每个字符进行单字符的映射，并将所有单字符映射与目标集合中的所有字符串拼接，
形成新的字符串集合。拼接的过程，就是递归实现的部分。 

具体的实现思路如下：
建立字典映射表；
从后向前遍历当前数字字符串；
若当前数字字符串长度超过 1，则从当前字符串的第 2 位到末尾作为子字符串，将该子串作为输入参数，重新输入该函数，这里即为递归的实现。
字典中查找当前字符串的首位数字对应的所有字符，并对目标集合进行双重遍历，实现首位数字对应字符与目标集合中所有字符串的拼接；


*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res, dst;
        unordered_map<int, string> dict;
        // 初始化字典映射
        dict.insert(make_pair<int, string>(2, "abc"));
        dict.insert(make_pair<int, string>(3, "def"));
        dict.insert(make_pair<int, string>(4, "ghi"));
        dict.insert(make_pair<int, string>(5, "jkl"));
        dict.insert(make_pair<int, string>(6, "mno"));
        dict.insert(make_pair<int, string>(7, "pqrs"));
        dict.insert(make_pair<int, string>(8, "tuv"));
        dict.insert(make_pair<int, string>(9, "wxyz"));
        // 检查输入字符是否在 2 - 9 范围内
        for(int i = 0; i < digits.size(); ++i){
            if(digits[i] < '2' || digits[i] > '9'){
                vector<string> nullstrs;
                return nullstrs;
            }
        }
        // 递归思路
        if(digits.size() > 1){
            string sub_digits = digits.substr(1, digits.size() - 1);
            res = letterCombinations(sub_digits);
        }
        // 查找字符串首字母对应的所有字符
        string keystr = dict[digits[0] - '0'];
        if(digits.size() == 1){
            for(int m = 0; m < keystr.size(); ++m){
                string tmp = "";
                tmp += keystr[m];
                dst.push_back(tmp);
            }
        }
        // 双重循环，将vector<string> 与 char 组合，形成一个新的 vector<string>
        for(int m = 0; m < keystr.size(); ++m){
            for(int n = 0; n < res.size(); ++n){
                string tmpstr = keystr[m] + res[n];
                dst.push_back(tmpstr);
            }
        }
        return dst;
    }
}; 

//树形问题
//回溯法是暴力解法的一个主要实现手段
//递归调用的一个重要特征，要返回，这就叫回溯
//时间复杂度为3^n = O(2^n)
class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return res;
        }
        findCombination(digits, 0, "");
        return res;
    }

private:
    const string letterMap[10] = {
        " ",      //0
        "",       //1
        "abc",    //2
        "def",    //3
        "ghi",    //4
        "jkl",    //5
        "mno",    //6
        "pqrs",   //7
        "tuv",    //8
        "wxyz"    //9
    };
    vector<string> res;
    //s中保存了此时从digits[0...index-1]翻译的得到的一个字母字符串
    //寻找和digits[index]匹配的字母，获得digits[0...index]翻译得到的解
    void findCombination(const string& digits, int index, const string& s){
        cout << index << " : " << s << endl;
        if(index == digits.size()){
            //保存s到最后的结果中
            res.push_back(s);
            cout << "get " << s << " , return " << endl;
            return;
        }
        char c = digits[index];
        string letters = letterMap[c - '0'];
        for(int i = 0; i < letters.size(); ++i){
            cout << "digits[" << index << "] = " << c << " , use " << letters[i] << endl;
            findCombination(digits, index + 1, s + letters[i]);
        }
        cout << "digits[" << index << "] = " << c << " complete, return " << endl;
        return;
    }
};


int main()
{
    vector<string> res = Solution1().letterCombinations("23");
    for(vector<string>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}