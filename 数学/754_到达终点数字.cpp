/* 
在一根无限长的数轴上，你站在0的位置。终点在target的位置。
每次你可以选择向左或向右移动。第 n 次移动（从 1 开始），可以走 n 步。
返回到达终点需要的最小移动次数。

示例 1:
输入: target = 3
输出: 2
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 3 。

示例 2:
输入: target = 2
输出: 3
解释:
第一次移动，从 0 到 1 。
第二次移动，从 1 到 -1 。
第三次移动，从 -1 到 2 。

注意:
target是在[-10^9, 10^9]范围中的非零整数。
*/

#include <bits/stdc++.h>

using namespace std;

/* 
第一个trick是到达target和-target的步数相同，因为数轴是对称的，只要将到达target的每步的距离都取反，就能到达-target。
下面来说第二个trick，这个是解题的关键，比如说目标值是4，那么如果我们一直累加步数，直到其正好大于等于target时，有：
0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
第三步加上3，得到了6，超过了目标值4，超过了的距离为2，是偶数，那么实际上我们只要将加上距离为1的时候，不加1，而是加 -1，
那么此时累加和就损失了2，那么正好能到目标值4，如下：
0 - 1 = -1
-1 + 2 = 1
1 + 3 = 4
那么，我们的第二个 trick 就是，当超过目标值的差值d为偶数时，只要将第 d/2 步的距离取反，就能得到目标值，
此时的步数即为到达目标值的步数。那么，如果d为奇数时，且当前为第n步，那么我们看下一步 n+1 的奇偶，
如果 n+1 为奇数，那么加上 n+1 再做差，得到的差值就为偶数了，问题解决，
如果 n+1 为偶数，那么还得加上 n+2 这个奇数，才能让差值为偶数，这样就多加了两步。分析到这里，我们的解题思路也就明晰了吧：
我们先对 target 取绝对值，因为正负不影响最小步数。然后我们求出第n步，使得从1累加到n刚好大于等于 target，
那么利用求和公式就有：
target = n * (n + 1) / 2

变成一元二次方程方程即为：
n^2 + n - 2*target = 0

用初中的一元二次方程的求和公式，就有：
n = (-1 + sqrt(1 + 8*target)) / 2

当然算出来可能不是整数，所以要取整，这里使用 ceil 来取整。如果此时 sum 和 target 正好相等，perfect！直接返回n，
否则就是计算差值，如果差值时偶数，那么也直接返回n，如果是奇数，判断此时n的奇偶，如果n是奇数，则返回 n+2，若n是偶数，返回 n+1
*/
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);
        long sums = n * (n+1) / 2; 
        if(sums == target)
            return n;
        long res = sums - target;
        if((res & 1) == 0)
            return n;
        return n + ((n & 1) ? 2 : 1);
    }
};


/*
我们也可以不用求和公式来快速定位n，而是通过累加来做，res为我们的当前步数，也是最终需要返回的结果，sum是加上每步距离的累加值，
如果 sum 小于 target，或者 sum 减去 target 的差值为奇数，我们进行循环，步数 res 自增1，然后 sum 加上步数 res，
最后跳出循环的条件就是差值为偶数，也符合我们上的分析，参见代码如下：
*/
 

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int res = 0, sum = 0;
        while (sum < target || (sum - target) % 2 == 1) {
            ++res;
            sum += res;
        }
        return res;
    }
};

int main(){
    
    return 0;
}
