/*
给定一组字符，使用原地算法将其压缩。
压缩后的长度必须始终小于或等于原数组长度。
数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
在完成原地修改输入数组后，返回数组的新长度。

进阶：
你能否仅使用O(1) 空间解决问题？

示例 1：
输入：
["a","a","b","b","c","c","c"]
输出：
返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
说明：
"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。

示例 2：
输入：
["a"]
输出：
返回1，输入数组的前1个字符应该是：["a"]
说明：
没有任何字符串被替代。

示例 3：
输入：
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
输出：
返回4，输入数组的前4个字符应该是：["a","b","1","2"]。
说明：
由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
注意每个数字在数组中都有它自己的位置。
*/

/*
使用双指针i和j，开始循环后，我们用j来找重复的字符串的个数，用一个while循环，最终j指向的是第一个和i指向字符不同的地方，
此时我们需要先将i位置的字符写进chars中，然后我们判断j是否比i正好大一个，因为只有一个字符的话，
后面是不用加个数的，所以直接跳过。
否则我们将重复个数转为字符串，然后提取出来修改chars数组即可，注意每次需要将i赋值为j，从而开始下一个字符的统计。
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int compress(vector<char>& chars)
    {
        int n = chars.size();
        int cnt = 0;
        for(int i = 0, j = 0; i < n; i = j){
            while(j < n && chars[j] == chars[i]){
                ++j;
            }
            //cnt用来记录新数组的长度
            chars[cnt++] = chars[i]; 
            //相当于chars[cnt] = chars[i]; cnt++;
            if(j - i == 1){
                continue;
            }
            //to_string()将值转化成字符串类型
            for(char c: to_string(j - i)){
                chars[cnt++] = c;
                //chars[cnt] = c; cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    char a[7] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    //用数组初始化vector
    vector<char> chars(a, a + 7);
    Solution first;
    int cnt = first.compress(chars);
    cout << cnt << endl;
    return 0;
}