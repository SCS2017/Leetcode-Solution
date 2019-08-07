#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 10;

string add(string s1, string s2){
    int len1 = s1.size(), len2 = s2.size();
    vector<int> a(maxn, 0), b(maxn, 0);
    int maxlen = max(len1, len2);
    for(int i = 0; i < len1; ++i)
        a[i] = s1[len1-1-i] - '0';
    for(int i = 0; i < len2; ++i)
        b[i] = s2[len2-1-i] - '0';
    for(int i = 0; i < maxlen; ++i){
        if(a[i] + b[i] >= 10){
            int temp = a[i] + b[i];
            a[i] += temp % 10;
            a[i+1] += (temp / 10);
        }
        else
            a[i] += b[i];
    }
    string res = "";
    if(a[maxlen] != 0)
        res += a[maxlen] + '0';
    for(int i = maxlen-1; i >= 0; --i)
        res += a[i] + '0';
    return res;
}

int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    string res = add(s1, s2);
    cout << res << endl;
    return 0;
}