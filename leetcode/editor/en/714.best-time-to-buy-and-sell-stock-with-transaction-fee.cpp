#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Your are given an array of integers prices, for which the i-th element is the 
//price of a given stock on day i; and a non-negative integer fee representing a t
//ransaction fee. 
// You may complete as many transactions as you like, but you need to pay the tr
//ansaction fee for each transaction. You may not buy more than 1 share of a stock
// at a time (ie. you must sell the stock share before you buy again.) 
// Return the maximum profit you can make. 
//
// Example 1: 
// 
//Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
//Output: 8
//Explanation: The maximum profit can be achieved by:
// Buying at prices[0] = 1 Selling at prices[3] = 8 Buying at prices[4] = 4 Sell
//ing at prices[5] = 9 The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// 
// 
//
// Note:
// 0 < prices.length <= 50000. 
// 0 < prices[i] < 50000. 
// 0 <= fee < 50000. 
// Related Topics Array Dynamic Programming Greedy


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        auto profit_after_sell = 0, profit_after_buy = INT_MIN + fee;
        for (auto price : prices) {
            profit_after_sell = max(profit_after_sell, profit_after_buy + price - fee);
            profit_after_buy = max(profit_after_buy, profit_after_sell - price);
        }
        return profit_after_sell;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestBestTimeToBuyAndSellStockWithTransactionFee, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int, int>>{
            {{1, 3, 2, 8, 4, 9}, 2, 8},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.maxProfit(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}

