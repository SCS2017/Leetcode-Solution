/*
给定一个数字 N，当它满足以下条件的时候返回 true：
把原数字旋转180°以后得到新的数字。
如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。
2, 3, 4, 5, 7 旋转 180° 后,得到的不是数字。
易混淆数字 (confusing number) 就是一个数字旋转180°以后，得到和原来不同的数字，且新数字的每一位都是有效的。

示例 1：

输入：6
输出：true
解释： 
把 6 旋转 180° 以后得到 9，9 是有效数字且 9!=6 。
1
2
3
4
示例 2：

输入：89
输出：true
解释: 
把 89 旋转 180° 以后得到 68，86 是有效数字且 86!=89 。
1
2
3
4
示例 3：

输入：11
输出：false
解释：
把 11 旋转 180° 以后得到 11，11 是有效数字但是值保持不变，所以 11 不是易混淆数字。 
1
2
3
4
示例 4：

输入：25
输出：false
解释：
把 25 旋转 180° 以后得到的不是数字。
1
2
3
4
提示：

0 <= N <= 10^9
可以忽略掉旋转后得到的前导零，例如，如果我们旋转后得到 0008 那么该数字就是 8 。
*/
/*
解题思路：
首先注意题目意思，是将整个数字串旋转180°得到新数字，不是将单个数字旋转180°得到后得到新数字

将数字分为两部分：

旋转180°后还是有效数字的数字：1，6，8，9，0
旋转180°后不是有效数字的数字：2，3，4，5，7
若数字串中出现第二种数字，则说明该数字不是易混淆数字。
若数字中都由第一种数字组成，则还需要判断转换后和原先大小是否相等，若相等，则说明不是易混淆数字
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool confusingNumber(int N) {
        map< char,char > a;//建立哈希表存放转换结果
        a.insert(map<char,char>::value_type('1','1'));
        a.insert(map<char,char>::value_type('6','9'));
        a.insert(map<char,char>::value_type('9','6'));
        a.insert(map<char,char>::value_type('0','0'));
        a.insert(map<char,char>::value_type('8','8'));
        string s = to_string(N);  //转成字符串进行操作
        int res = 0;//存放转换结果
        for(int i = s.length()-1; i >= 0; i--){
            if(a.count(s[i]) == 0)
                return false;
            else 
                res = res * 10 + (a[s[i]] - '0');
        }
        if(res == N)
            return false;
        return true;
    }
};

/*
python解法
class Solution(object):
    def confusingNumber(self, N):
        """
        :type N: int
        :rtype: bool
        """
        #如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。
        #2, 3, 4, 5, 7 旋转 180° 后,得到的不是数字。
 
        mapping = {0:0, 1:1, 6:9, 8:8, 9:6}
        invalid = [2,3,4,5,7]
        
        n = N
        tmp = 0
        res = list()
        while(n):
            n, tmp = divmod(n, 10)
            if tmp in invalid:
                return False
            res.append(mapping[tmp])
        
        res = res[::-1]
        r = 0
        for i, x in enumerate(res):
            r += 10 ** i * x
        return r != N
*/