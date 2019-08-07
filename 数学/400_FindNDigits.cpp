/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 2^31).

Example 1:
Input:
3
Output:
3

Example 2:
Input:
11
Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/

/*
解题思路：
思路一：分三步走，

第一步确定是在哪几位数之间
第二步确定是哪个数
第三步确定是这个数的哪一位数
举个例子，比如n=23456，在9+90*2+900*3和9+90*2+900*3+9000*4之间，
所以说明，这个数在1000-9999之间，是一个四位数。

一位数时，9*1=9个 
二位数时，90*2=180个， 
三位数时，900*3=2700个， 
。。。。

以此类推，

23456-9-90*2-900*3=20567，

也就是，从1000开始，数20567位，那到底是落在哪个数字上呢？

1000+(20567-1)/4=6141，

所以说，在6141的某一位上，就是第n=23456位数字，那到底是哪一位呢？

(20567-1)%4=2，

这说明，在6141的第3位上，也就是4。

注意的是，这里最后计算是哪个数、哪一位时，要减去1，这是因为整除代表某个数的最后一位，所以需要减1。
*/

#include <iostream>

using namespace std;

class Solution{
    int findNthDigit(int n){
        long long len = 1, cnt = 1, start = 1;
        while(n > len * cnt){
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        start += (n - 1) / len;
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
    }
};