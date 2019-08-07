/*

*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> permute(string S) {
        vector<vector<char> > str;
        for(int i = 0; i < S.size(); ){
            if(S[i] == '{'){
                str.push_back({});
                while(S[i] >= 'a' && S[i] <= 'z'){
                    str.back().push_back(S[i]);
                    ++i;
                }
            }
            if(S[i] == '}')
                continue;
            str.push_back({});
            if(S[i] >= 'a' && S[i] <= 'z'){
                str.back().push_back(S[i]);
                ++i;
            }
        }
        for(int i = 0; i < str.size(); ++i){
            for(int j = 0; j < str[i].size(); ++j){
                cout << str[i][j] << " ";
            }
            cout << endl;
        }
        vector<string> res;
        return res;
    }
};

int main()
{
    string str;
    getline(cin, str);
    vector<string> res = Solution().permute(str);
    return 0;
}