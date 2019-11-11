#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> keys;
        for (unsigned int i = 0; i < keyboard.size(); ++i) {
            keys[keyboard[i]] = i;
        }
        int res = 0;
        int pos = 0;
        for (char c : word) {
            int cur = keys[c];
            res += cur > pos ? cur - pos : pos - cur;
            pos = cur;
        }
        return res;
    }
};

int main(){
    string keyboard = "ASDFGH";
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int res = Solution().calculateTime(keyboard, s);
        cout << res << endl;
    }
    return 0;
}
