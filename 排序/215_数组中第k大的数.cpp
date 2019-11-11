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

class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(true){
            int pos = Partition(nums, left, right);
            if(pos == k-1)
                return nums[pos];
            else if(pos < k-1)
                left = pos + 1;
            else
                right = pos - 1;
        }
    }
private:
    int Partition(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int low = left + 1, high = right;
        while(low <= high){
            if(nums[low] < pivot && nums[high] > pivot)
                swap(nums[low++], nums[high--]);
            if(nums[low] >= pivot)
                ++low;
            if(nums[high] <= pivot)
                --high;
        }
        swap(nums[left], nums[high]);
        return high;
    }
    int partition1(vector<int>& nums, int left, int right){
        int pivot = nums[left];
        int low = left+1, high = right;
        while(low <= high){
            while(low <= high && nums[low] >= pivot)
                ++low;
            while(low <= high && nums[high] <= pivot)
                --high;
            if(low < high)
                swap(nums[low], nums[high]);
        }
        swap(nums[left], nums[high]);
        return high;
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