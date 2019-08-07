/*
定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]

说明：
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(nlogn) , n是数组的大小。
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

//最简单的思路：扫描一遍统计频率；排序找到前k个出现频率最高的元素。O(nlogn)
/*思路2，如果k远远小于n
维护一个含有k个元素的优先队列。如果遍历到的元素比队列中最小频率元素的频率高，则取出队列中最小频率的元素，
将新元素入队。这样，最后，队列剩下的元素就是前k个出现频率最高的元素
O(nlogk)
*/

/*思路2，如果k和n接近
维护一个含有n - k个元素的优先队列
O(nlog(n-k))
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计每个元素出现的频率
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); ++i){
            ++freq[nums[i]];
        }
        //扫描freq，维护一个含有k个元素的优先队列
        //在优先队列中，按照频率排序，所以数据对是(频率， 元素)的形式
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        for(unordered_map<int, int>::iterator iter = freq.begin(); iter!= freq.end(); ++iter){
            if(pq.size() == k){
                if(iter->second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            }
            else{
                pq.push(make_pair(iter->second, iter->first));
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};