#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;

//加法
string bigIntegerAdd(string s1,string s2){
    int a[maxn],b[maxn];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int len1 = s1.size(),len2 = s2.size();
    int maxL = max(len1,len2);
    for(int i = 0; i < len1; i++)
        a[i] = s1[len1-1-i]-'0';
    for(int i = 0; i < len2; i++)
        b[i] = s2[len2-1-i]-'0';
    for(int i = 0; i < maxL; i++){
        if(a[i]+b[i] >= 10){
            int temp = a[i]+b[i];
            a[i] = temp%10;
            a[i+1] += (temp/10);
        }
        else a[i] += b[i];
    }
    string c = "";
    if(a[maxL] != 0)
        c += a[maxL] + '0';
    for(int i = maxL-1; i >= 0; i--)
        c += a[i] + '0';
    return c;
}

string bigIntegerAdd1(string s1,string s2){
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    vector<int> v(max(s1.size(), s2.size())+1, 0);
    for(int i = 0; i < v.size(); i++){
        int temp = s1[i] - '0' + s2[i] - '0';
        if(temp >= 10){
            v[i] = temp%10;
            v[i+1] += (temp/10);
        }
        else
            v[i] = temp;
    }
    string res;
    int i;
    for(i = v.size() - 1; i > 0 && v[i] == 0; --i)
    ;
    for(; i >= 0; --i){
        res += (char)(v[i] + '0');
    }
    return res;
}

//乘法
string bigIntegerMul(string s1, string s2){
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    vector<int> v(s1.size() + s2.size(), 0);
    for(int i = 0; i < s1.size(); ++i){
        for(int j = 0 ;j < s2.size(); ++j)
            v[i+j] += (s1[i] - '0') * (s2[j] - '0');
    }
    for(int i = 0;i < v.size() - 1; ++i){
        if(v[i] >= 10){
            v[i+1] += v[i] /10;
            v[i] %= 10;
        }
    }
    string res;
    int i;
    for(i = v.size() - 1; i > 0 && v[i] == 0; --i)
    ;
    for(; i >= 0; --i){
        res += (char)(v[i] + '0');
    }
    return res;
}


int main(){
    //freopen("in.txt","r",stdin);
    // int n;
    // string s[255];
    // s[0] = "1",s[1] = "1";  //注意0的时候是1
    // for(int i = 2;i <= 255; i++){
    //     string temp = bigIntegerMul("2",s[i-2]);
    //     s[i] = bigIntegerAdd(s[i-1],temp);
    // }
    // while(~scanf("%d",&n))
    //     cout<<s[n]<<endl;
    string num1, num2;
    while(cin >> num1 >> num2){
        string sums = bigIntegerAdd(num1, num2);
        string sums1 = bigIntegerAdd(num1, num2);
        string muls = bigIntegerMul(num1, num2);
        cout << sums << " " << sums1 << endl;
        cout << muls << endl;
    }
    return 0;
}
