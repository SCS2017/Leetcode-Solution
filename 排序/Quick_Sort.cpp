#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Partition(vector<int>& nums, int left, int right){
    int pivot = nums[right];
    int tail = left - 1;
    for(int i = left; i < right; ++i){
        if(nums[i] <= pivot){
            ++tail;
            if(tail != i){
                swap(nums[tail], nums[i]);
            }
        }
    }
    swap(nums[tail + 1], nums[right]);
    return tail + 1;
}

void QuickSort(vector<int>& nums, int left, int right){
    if(left > right){
        return;
    }
    int pivot_index = Partition(nums, left, right);
    QuickSort(nums, left, pivot_index - 1);
    QuickSort(nums, pivot_index + 1, right);
}

void QuickSort1(vector<int>& nums, int left, int right){
    if(left >= right)
        return;
    int pivot = nums[right];
    int i = left, j = right;
    while(i < j){
        while(i < j && nums[i] <= pivot)
            ++i;
        while(i < j && nums[j] >= pivot)
            --j;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[right]);
    //以i的位置为基准,分成两部分，左部分
    QuickSort1(nums, left, i-1);
    QuickSort1(nums, j+1, right);
}

int main()
{
    int A[] = {5, 2, 9, 4, 7, 6, 1, 3, 8}; // 从小到大快速排序
    int n = sizeof(A) / sizeof(int);
    vector<int> nums(A, A + n);
    QuickSort1(nums, 0, n - 1);
    cout << "快速排序结果：";
    for(int i = 0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
    return 0;
}

