#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//利用最大堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //max heap method
        //min heap method
        //order statistics
        make_heap(nums.begin(), nums.end());
        int result;
        for(int i=0; i<k; i++){
            result=nums.front();
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return result;
    }
};

//利用优先队列
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};

//利用快排的思想
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int high = nums.size();
        int low = 0;
        while (low < high) {
            int i = low;
            int j = high-1;
            int pivot = nums[low];
            //将大于pivot的放在前面，小于pivot的放在后面
            while (i <= j) {
                while (i <= j && nums[i] >= pivot)
                    i++;
                while (i <= j && nums[j] < pivot)
                    j--;
                if (i < j)
                    swap(nums[i++],nums[j--]);
            }
            swap(nums[low],nums[j]);

            if (j == k-1)
                return nums[j];
            else if (j < k-1)
                low = j+1;
            else
                high = j;
        }
    }
};

int main()
{
    int arr[] = {1, 2, 4, 6, 5, 3};
    int n = sizeof(arr) / sizeof(int);
    vector<int> nums(arr, arr + n);
    int k = 3;
    int res = Solution2().findKthLargest(nums, k);
    cout << res << endl;
    return 0;
}