#include <iostream>
#include <vector>
using namespace std;

int BinarySearchMax(vector<int>& data, int target){
    int n = data.size();
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(data[mid] == target){
            if(mid < n-1 && data[mid+1] != target || mid == n-1)
                return mid;
            else
                left = mid + 1;
        }
        else if(data[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;       
    }
    return -1;
}

int main(){
   int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4};
   int len = sizeof(arr) / sizeof(int);
   vector<int> nums(arr, arr+len);
   int res = BinarySearchMax(nums, 4);
   cout << res << endl;
   return 0;
}
