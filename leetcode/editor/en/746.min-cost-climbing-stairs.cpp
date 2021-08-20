#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 i
//ndexed).
// 
//Once you pay the cost, you can either climb one or two steps. You need to find
// minimum cost to reach the top of the floor, and you can either start from the s
//tep with index 0, or the step with index 1.
// 
//
// Example 1: 
// 
//Input: cost = [10, 15, 20]
//Output: 15
//Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
// 
// 
//
// Example 2: 
// 
//Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//Output: 6
//Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[
//3].
// 
// 
//
// Note: 
// 
// cost will have a length in the range [2, 1000]. 
// Every cost[i] will be an integer in the range [0, 999]. 
// 
// Related Topics Array Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        auto pre1 = 0, pre2 = INT_MAX;
        for (auto const c : cost) {
            auto const curr = min(pre1, pre2) + c;
            pre2 = pre1;
            pre1 = curr;
        }
        return min(pre1, pre2);
    }
};

//leetcode submit region end(Prohibit modification and deletion)


TEST(TestMinCostClimbingStairs, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.minCostClimbingStairs(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
