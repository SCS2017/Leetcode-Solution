#include <iostream>
#include <vector>
using namespace std;

bool checkRepeatedString(string s)
{
    vector<int> vec(256, 0);
    for(int i = 0; i < s.length(); ++i)
    {
        vec[s[i]] += 1;
    }
    for(int i = 0; i < s.length(); ++i)
    {
        if(vec[s[i]] > 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    bool result;
    while(cin >> s)
    {
        result = checkRepeatedString(s);
        cout << boolalpha << result << endl;
    }
    return 0;
}