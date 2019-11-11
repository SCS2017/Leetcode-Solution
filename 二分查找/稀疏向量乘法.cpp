#include<bits/stdc++.h>
using namespace std;

int sparseVectorMul(unordered_map<int, int>& a, unordered_map<int, int>& b){
    int res = 0;
    for(auto t: a){
        if(b.count(t.first))
            res += t.second * b[t.first];
    }
    return res;
}

int main(){
    int n, num1, num2;
    cin >> n;
    unordered_map<int, int> a, b; 
    for(int i = 0; i < n; ++i){
        cin >> num1;
        if(num1 != 0)
            a.insert(make_pair(i, num1));
    }
    for(int i = 0; i < n; ++i){
        cin >> num2;
        if(num2 != 0)
            b.insert(make_pair(i, num2));
    }
    int res = sparseVectorMul(a, b);
    cout << res << endl;
    return 0;
}