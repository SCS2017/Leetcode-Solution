#include <stdio.h>
#include <iostream>
#include <string.h>
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

//乘法
string bigIntegerMul(string s1,string s2){
    int a[maxn],b[maxn],c[maxn*2 + 5];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int len1 = s1.size(),len2 = s2.size();
    for(int i = 0; i < len1; i++)
        a[i] = s1[len1-1-i]-'0'; //倒置
    for(int i = 0; i < len2; i++)
        b[i] = s2[len2-1-i]-'0';
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            c[i+j] += a[i]*b[j];
        }
    }
    for(int i = 0; i < maxn*2; i++){
        if(c[i] >= 10){
            c[i+1] += c[i]/10;
            c[i] %= 10;
        }
    }
    string ans = "";
    int i;
    for(i = maxn * 2; i >= 0; i--)
        if(c[i] != 0)
            break;
    for(;i >= 0; i--)
        ans += c[i] + '0';
    return ans;
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
        string muls = bigIntegerMul(num1, num2);
        cout << sums << endl;
        cout << muls << endl;
    }
    return 0;
}
