// 统计在输入中每个值连续出现了多少次
#include <iostream>
using namespace std;
int main()
{
    //currVal是正在统计的数，val是读入的新值
    int currVal = 0, val = 0;
    //读取第一个数，并确保确实有数据可以处理
    if (cin >> currVal)
    {
        int cnt = 1;
        while(cin >> val){
            if (val == currVal)
                ++ cnt;
            else {
                cout << currVal << " occurs " << cnt << " times" <<endl;
                currVal = val;
                cnt = 1;
            }
        }
        cout << currVal << " occurs " << cnt << " times" << endl;
    }
    return 0;

}
