#include <iostream>
#include <cmath>
using namespace std;

bool judgeSquareSum(int c){
    for (int i = sqrt(c); i >= 0; i--){
        if (i * i == c){
            return true;
        }
        int d = c - i * i;
        int t = sqrt(d);
        if (t * t == d){
            return true;
        }
    }
    return false;
}

int main()
{
    bool result;
    int c;
    cout << "Input an integer: ";
    cin >> c;
    result = judgeSquareSum(c);
    if(result){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    return 0;
}
