#include <bits/stdc++.h>
using namespace std;

/*
字符串匹配是什么？举例来说，有一个字符串"BBC ABCDAB ABCDABCDABDE"，我想知道，里面是否包含另一个字符串"ABCDABD"？
KMP算法解决字符串匹配问题。
*/

void getNext(string& p, vector<int>& next){
    next[0] = -1;
    for(int i = 0, j = -1; i < p.length(); ){
        if(j == -1 || p[i] == p[j]){
            ++i;
            ++j;
            next[i] = j;
            //next[++i] = ++j;
        }
        else
            j = next[j];
    }
}

int KMP(string& s, string& p){
    int i = 0, j = 0;
    vector<int> next(p.length());
    getNext(p, next);
    for(auto num: next)
        cout << num << " ";
    cout << endl;
    //这里如果改成i < s.length()会报错，很奇怪
    while(i != s.length() && j != p.length()){
        //如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++  
        if(j == -1 || s[i] == p[j]){
            ++i;
            ++j;
        }
        //如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
        //next[j]即为j所对应的next值
        else   
            j = next[j];
    }
    return j == p.length() ? (i - j) : -1;
}

int main(){
    string pattern = "BBC ABCDAB ABCDABCDABDE";
    string str = "ABCDABD";
    int res = KMP(pattern, str);
    cout << res << endl;
    return 0;
}
