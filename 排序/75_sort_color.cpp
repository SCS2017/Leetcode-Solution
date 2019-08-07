/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，
并按照红色、白色、蓝色顺序排列。
此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:
输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
*/

/*
i=0, j=n, 循环k保证循环不变式
[0, j-1]是0
[i, k-1]是1
[k, j-1]未探测
[j, n-1]是2
初始k=0时0,1,2所有区域是空，归纳证明仍然满足上述条件
循环k=0 to j-1
若a[k]==0，swap(a[i++], a[k])
若a[k]==1，无操作
若a[k]==2，swap(a[--j], a[k--])
时间复杂度为O(n)
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size();
        for(int k = 0; k < j; k++){
            if(nums[k] == 0){
                swap(nums[i++], nums[k]);
            }
            else if(nums[k] == 2){
                swap(nums[--j], nums[k--]);
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<nums.size(); ++i){
        cin >> nums[i];
    }
    Solution first;
    first.sortColors(nums);
    for(vector<int>::iterator it=nums.begin(); it != nums.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}