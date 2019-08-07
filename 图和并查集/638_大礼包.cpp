/*
在LeetCode商店中， 有许多在售的物品。
然而，也有一些大礼包，每个大礼包以优惠的价格捆绑销售一组物品。
现给定每个物品的价格，每个大礼包包含物品的清单，以及待购物品清单。请输出确切完成待购清单的最低花费。
每个大礼包的由一个数组中的一组数据描述，最后一个数字代表大礼包的价格，其他数字分别表示内含的其他种类物品的数量。
任意大礼包可无限次购买。

示例 1:
输入: [2,5], [[3,0,5],[1,2,10]], [3,2]
输出: 14
解释: 
有A和B两种物品，价格分别为¥2和¥5。
大礼包1，你可以以¥5的价格购买3A和0B。
大礼包2， 你可以以¥10的价格购买1A和2B。
你需要购买3个A和2个B， 所以你付了¥10购买了1A和2B（大礼包2），以及¥4购买2A。

示例 2:
输入: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
输出: 11
解释: 
A，B，C的价格分别为¥2，¥3，¥4.
你可以用¥4购买1A和2B，也可以用¥9购买2A，2B和1C。
你需要买1A，2B和1C，所以你付了¥4买了1A和1B（大礼包1），以及¥3购买1B， ¥4购买1C。
你不可以购买超出待购清单的物品，尽管购买大礼包2更加便宜。

说明:
最多6种物品， 100种大礼包。
每种物品，你最多只需要购买6个。
你不可以购买超出待购清单的物品，即使更便宜。
*/
#include <bits/stdc++.h>

using namespace std;

/*
我们可以先求出不使用任何商品需要花的钱数作为结果res的初始值，然后我们遍历每一个coupon，
定义一个变量isValid表示当前coupon可以使用，然后遍历每一个商品，如果某个商品需要的个数小于coupon中提供的个数，
说明当前coupon不可用，isValid标记为false。如果遍历完了发现isValid还为true的话，表明该coupon可用，
我们可以更新结果res，对剩余的needs调用递归并且加上使用该coupon需要付的钱数。最后别忘了恢复needs的状态，
*/
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = 0, n = price.size();
        for (int i = 0; i < n; ++i) {
            res += price[i] * needs[i];
        }
        for (auto offer : special) {
            bool isValid = true;
            for (int j = 0; j < n; ++j) {
                if (needs[j] - offer[j] < 0) isValid = false;
                needs[j] -= offer[j];
            }
            if (isValid) {
                res = min(res, shoppingOffers(price, special, needs) + offer.back());
            }
            for (int j = 0; j < n; ++j) {
                needs[j] += offer[j];
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = inner_product(price.begin(), price.end(), needs.begin(), 0);
        for (auto offer : special) {
            vector<int> r = helper(offer, needs);
            if (r.empty()) continue;
            res = min(res, shoppingOffers(price, special, r) + offer.back());
        }
        return res;
    }
    vector<int> helper(vector<int>& offer, vector<int>& needs) {
        vector<int> r(needs.size(), 0);
        for (int i = 0; i < needs.size(); ++i) {
            if (offer[i] > needs[i]) return {};
            r[i] = needs[i] - offer[i];
        }
        return r;
    }
};

int main(){
    
    return 0;
}
