/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
你可以假设 nums1 和 nums2 不同时为空。

示例 1:
nums1 = [1, 3]
nums2 = [2]

中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
*/
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

#include <iostream>
#include <vector>

using namespace std;

/*
方法1 归并排序
归并到第k个为止
时间复杂度为O(k)
*/
class Solution {
public:
    int findk(vector<int>& a, vector<int>& b, int k){
        int i = 0, j = 0;
        int lena = a.size(), lenb = b.size();
        while((i < lena) && (j < lenb)){
            --k;
            if(a[i] < b[j]){
                if(k == 0){
                    return a[i];
                }
                ++i;
            }
            else if(k == 0){
                return b[j];
            }
            else{
                ++j;
            }
        }
        return (i >= lena) ? b[j+k-1] : a[i+k-1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        double result;
        result = ((m + n) & 1) ? findk(nums1, nums2, (m+n+1) >> 1):
        ((findk(nums1, nums2, (m+n) >> 1) + findk(nums1, nums2, ((m+n)>>1) + 1)) * 0.5);
        return result;
    }
};
/*二分法
一个小trick，分别找第 (m+n+1) / 2 个，和 (m+n+2) / 2 个，然后求其平均值即可，这对奇偶数均适用。

然后需要定义一个函数来在两个有序数组中找到第K个元素，
首先，我们使用两个变量i和j分别来标记数组nums1和nums2的起始位置。
然后来处理一些corner cases，比如当某一个数组的起始位置大于等于其数组长度时，说明其所有数字均已经被淘汰了，
相当于一个空数组了，那么实际上就变成了在另一个数组中找数字，直接就可以找出来了。

还有就是如果K=1的话，那么我们只要比较nums1和nums2的起始位置i和j上的数字就可以了。
难点就在于一般的情况怎么处理？因为我们需要在两个有序数组中找到第K个元素，为了加快搜索的速度，我们要使用二分法，
那么对谁二分呢，数组么？其实要对K二分，意思是我们需要分别在nums1和nums2中查找第K/2个元素，
注意这里由于两个数组的长度不定，所以有可能某个数组没有第K/2个数字，所以我们需要先check一下，
数组中到底存不存在第K/2个数字，如果存在就取出来，否则就赋值上一个整型最大值。如果某个数组没有第K/2个数字，
那么我们就淘汰另一个数字的前K/2个数字即可。有没有可能两个数组都不存在第K/2个数字呢，这道题里是不可能的，
因为我们的K不是任意给的，而是给的m+n的中间值，所以必定至少会有一个数组是存在第K/2个数字的。
最后就是二分法的核心啦，比较这两个数组的第K/2小的数字midVal1和midVal2的大小，如果第一个数组的第K/2个数字小的话，
那么说明我们要找的数字肯定不在nums1中的前K/2个数字，所以我们可以将其淘汰，将nums1的起始位置向后移动K/2个，
并且此时的K也自减去K/2，调用递归。反之，我们淘汰nums2中的前K/2个数字，并将nums2的起始位置向后移动K/2个，
并且此时的K也自减去K/2，调用递归即可，参见代码如下：
比如 nums1 = {3}，nums2 = {2, 4, 5, 6, 7}，K=4，我们要找两个数组混合中第4个数字，那么我们分别在 
nums1 和 nums2 中找第2个数字，我们发现 nums1 中只有一个数字，不存在第二个数字，
那么 nums2 中的前2个数字可以直接跳过，为啥呢，因为我们要求整个混合数组的第4个数字，
不管 nums1 中的那个数字是大是小，第4个数字绝不会出现在 nums2 的前两个数字中，所以可以直接跳过。
*/
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size()) return nums2[j + k - 1];
        if (j >= nums2.size()) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};
int main()
{
    int m, n;
    cout << "input length of nums1 and nums2:" << endl;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    cout << "input nums1:" << endl;
    for(int i=0; i<nums1.size(); ++i){
        cin >> nums1[i];
    }
    cout << "input nums2:" << endl;
    for(int j=0; j<nums2.size(); ++j){
        cin >> nums2[j];
    }
    Solution first;
    Solution1 second; 
    double result1, result2;
    result1 = first.findMedianSortedArrays(nums1, nums2);
    result2 = second.findMedianSortedArrays(nums1, nums2);
    cout << result1 << " "<< result2 << endl;
    return 0;
}