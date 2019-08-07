/*
给定平面上n对不同的点，“回旋镖” 是由点表示的元组(i, j, k)，其中i和j之间的距离和i和k之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

示例:

输入:
[[0,0],[1,0],[2,0]]

输出:
2

解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
遍历所有的点，然后计算每一个点到其他点的距离，并放入查找表中，键值对为距离和数量
然后遍历查找表，计算相应的结果
例如，距离1对应2，则结果为2*1=2，距离2对应3，则结果为3*2=6
*/
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); ++i){
            unordered_map<int, int> record;
            for(int j = 0; j < points.size(); ++j){
                if(j != i){
                    int distance = dis(points[i], points[j]);
                    ++record[distance];
                }
            }
            for(unordered_map<int, int>::iterator it = record.begin(); it != record.end(); ++it){
                // cout << it->first << " " << it->second << endl;
                res += (it->second) * (it->second - 1);
            }
        }
        return res;
    }
    
private:
    int dis(const pair<int, int>& pa, const pair<int, int>& pb){
        return (pa.first - pb.first) * (pa.first - pb.first) + (pa.second - pb.second) * (pa.second - pb.second);
    }
};

int main(){
    int m;
    cin >> m;
    vector<pair<int, int> > nums(m);
    for(int i = 0; i < m; ++i){
        cin >> nums[i].first >> nums[i].second;
    }
    int res = Solution().numberOfBoomerangs(nums);
    cout << res << endl;
    return 0;
}
/*
3
0 0
1 0
2 0

4 1
1 1
1 2
1 1
4 1

2
*/