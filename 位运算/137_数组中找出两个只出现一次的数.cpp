/*
在数组中有两个数只出现一次，其他数均出现两次。问怎样快速找出这两个数。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//先排序后查找
vector<int> FindNumsAppearOnce(vector<int> &nums)
{
    if (nums.size() <= 2){
        return nums;
    }
    sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i){
        if ((i + 1) < nums.size() && nums[i] == nums[i + 1]){
            ++i;
        }
        else{
            res.push_back(nums[i]);
        }
    }
    return res;
}

//哈希表实现
vector<int> FindNumsAppearOnce1(vector<int> nums)
{
    if (nums.size() < 2)
        return nums;

    unordered_map<int, int> have;
    for (int i = 0; i < nums.size(); i++){
        ++have[nums[i]];
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++){
        if (have[nums[i]] == 1)
            res.push_back(nums[i]);

        if (res.size() == 2)
            break;
    }
    return res;
}

//异或
vector<int> FindNumsAppearOnce2(vector<int> &nums)
{
    vector<int> res;
    if (nums.size() < 2)
        return nums;
    int myxor = 0;
    int flag = 1;
    for (int i = 0; i < nums.size(); ++i)
        myxor ^= nums[i];

    //利用异或结果的最低位为1的flag将数组中的数字分为两类，一类是与flag按位与为0，另一类为不为0
    //假如flag=1说明两个数的最低位不同，flag=2次最低位不同，flag=4。。。依次类推
    while ((myxor & flag) == 0)
        flag <<= 1;
    cout << flag << endl;
    int num1 = myxor;
    int num2 = myxor;
    for (int i = 0; i < nums.size(); ++i){
        if ((flag & nums[i]) == 0) //将数字分为两组进行异或操作
            num1 ^= nums[i];
        else
            num2 ^= nums[i];
    }
    res.push_back(num1);
    res.push_back(num2);
    return res;
}

/*
任何一个数字异或它自己都等于0
将原数组分成两个子数组，使得每个数组包含一个只出现一次的数字，而其他数字出现两次，这样对两个子数组分别异或，就能找到这两个数字。
从头到尾异或数组中的每个数字，得到的结果肯定不为0，也就是说，这个数的二进制表示中至少有一位为1；
我们在结果数字中找出这个位置，记为n。现在以第n位是不是1为标准将数组分成两个子数组
举例来说，{2， 4， 3， 6， 3， 2， 5， 5}，异或结果为0010，倒数第二位为1，分成两个子数字为
{2， 3， 6， 3， 2}，以及{4， 5， 5}
这样做的道理在于第n位为1的话，两个出现一次的数在这一位上肯定不同，这样才能将两者分开
*/
class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int> data) {
        vector<int> res;
        if(data.size() < 2){
            return res;
        }
        int resultExclusiveOR = 0;
        for(int i = 0; i < data.size(); ++i){
            resultExclusiveOR ^= data[i];
        }
        unsigned int indexOf1 = FindFirstBitsIs1(resultExclusiveOR);
        int num1 = 0, num2 = 0;
        for(int i = 0; i < data.size(); ++i){
            if(IsBits1(data[i], indexOf1)){
                num1 ^= data[i];
            }
            else{
                num2 ^= data[i];
            }
        }
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }
private:
    // 找到num从右边数起第一个是1的位
    unsigned int FindFirstBitsIs1(int num){
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8 * sizeof(int))){
            num = num >> 1;
            ++indexBit;
        }
        return indexBit;
    }
    // 判断数字num的第indexBit位是不是1
    bool IsBits1(int num, int index){
        num = num >> index;
        return (num & 1);
    }
};

int main()
{
    int arr[] = {1, 1, 2, 3, 3, 4};
    int length = sizeof(arr) / sizeof(int);
    vector<int> num(arr, arr + length);
    vector<int> res = FindNumsAppearOnce(num);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}