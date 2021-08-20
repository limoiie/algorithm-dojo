#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//In LeetCode Store, there are some kinds of items to sell. Each item has a pric
//e.
// 
//
// 
//However, there are some special offers, and a special offer consists of one or
// more different kinds of items with a sale price.
// 
//
// 
//You are given the each item's price, a set of special offers, and the number w
//e need to buy for each item.
//The job is to output the lowest price you have to pay for exactly certain item
//s as given, where you could make optimal use of the special offers.
// 
//
// 
//Each special offer is represented in the form of an array, the last number rep
//resents the price you need to pay for this special offer, other numbers represen
//ts how many specific items you could get if you buy this offer.
// 
//
// You could use any of special offers as many times as you want. 
//
// Example 1: 
// 
//Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
//Output: 14
//Explanation: 
//There are two kinds of items, A and B. Their prices are $2 and $5 respectively
//. 
//In special offer 1, you can pay $5 for 3A and 0B
//In special offer 2, you can pay $10 for 1A and 2B. 
//You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2)
//, and $4 for 2A.
// 
// 
//
// Example 2: 
// 
//Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
//Output: 11
//Explanation: 
//The price of A is $2, and $3 for B, $4 for C. 
//You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
//You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer 
//#1), and $3 for 1B, $4 for 1C. 
//You cannot add more items, though only $9 for 2A ,2B and 1C.
// 
// 
//
// Note: 
// 
// There are at most 6 kinds of items, 100 special offers. 
// For each item, you need to buy at most 6 of them. 
// You are not allowed to buy more items than you want, even if that would lower
// the overall price. 
// 
// Related Topics Dynamic Programming Depth-first Search


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    unordered_map<string, int> m;

public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special,
                       vector<int> &needs) {
        auto target = string();
        for (auto const& need : needs)
            target.push_back('0' + need);
        return dfs(price, special, needs, target);
    }

    int dfs(vector<int> const &price, vector<vector<int>> const &special,
             vector<int> const &needs, string const& target) {
        if (m.count(target))
            return m[target];
        auto ans = 0;
        for (auto i = 0; i < target.length(); ++i)
            ans += price[i] * (target[i] - '0');

        for (auto const& offer : special) {
            auto next = target;
            auto i = 0;
            for (; i < target.length() and target[i] - '0' >= offer[i]; ++i) {
                next[i] -= offer[i];
            }
            if (i == target.size())
                ans = min(ans, offer.back() + dfs(price, special, needs, next));
        }
        return m[target] = ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestShoppingOffers, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, vector<vector<int>>, vector<int>, int>>{
            {{2, 5}, {{3, 0, 5}, {1, 2, 10}}, {3, 2}, 14},
            {{2, 3, 4}, {{1, 1, 0, 4}, {2, 2, 1, 9}}, {1, 2, 1}, 11},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.shoppingOffers(get<0>(c), get<1>(c), get<2>(c));
        auto expect = get<3>(c);
        ASSERT_EQ(result, expect);
    }
}