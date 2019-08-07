/*
给定正整数 N ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。
如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。

示例 1：
输入：1
输出：true

示例 2：
输入：10
输出：false

示例 3：
输入：16
输出：true

示例 4：
输入：24
输出：false

示例 5：
输入：46
输出：true
 
提示：
1 <= N <= 10^9
*/

#include <bits/stdc++.h>

using namespace std;

/* 
让对N的十进制数的各位上的数字进行重排序，比如 N=46，那么换个位置，变成 64，就是2的指数了。搞清了题意后，就可以开始解题了，
由于N给定了范围，在 [1, 1e9] 之间，所以其调换位数能组成的二进制数也是有范围的，为 [2^0, 2^30] 之间，这样的话，
一个比较直接的解法就是，现将整数N转为字符串，然后对字符串进行排序。然后遍历所有可能的2的指数，
将每个2的指数也转为字符串并排序，这样只要某个排序后的字符串跟之前由N生成的字符串相等的话，则表明整数N是符合题意的
*/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string str = to_string(N);
        sort(str.begin(), str.end());
        for (int i = 0; i < 31; ++i) {
            string t = to_string(1 << i);
            sort(t.begin(), t.end());
            if (t == str) return true;
        }
        return false;
    }
};

/* 
下面这种方法没有将数字转为字符串并排序，而是使用了另一种比较巧妙的方法来实现类似的功能，是通过对N的每位上的数字都变为10的倍数，
并相加，这样相当于将N的各位的上的数字都加码到了10的指数空间，而对于所有的2的指数，进行相同的操作，
只要某个加码后的数字跟之前整数N的处理后的数字相同，则说明N是符合题意的。
需要注意的是，为了防止整型移除，加码后的数字用长整型来表示即可，
*/
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        long sum = helper(N);
        for (int i = 0; i < 31; i++) {
            if (helper(1 << i) == sum) return true;
        }
        return false;
    }
    long helper(int N) {
        long res = 0;
        for (; N; N /= 10) res += pow(10, N % 10);
        return res;
    }
};


int main(){
    
    return 0;
}
