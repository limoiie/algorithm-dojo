#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an array nums of integers, you can perform operations on the array. 
//
// In each operation, you pick any nums[i] and delete it to earn nums[i] points.
// After, you must delete every element equal to nums[i] - 1 or nums[i] + 1. 
//
// You start with 0 points. Return the maximum number of points you can earn by 
//applying such operations. 
//
// Example 1: 
//
// 
//Input: nums = [3, 4, 2]
//Output: 6
//Explanation: 
//Delete 4 to earn 4 points, consequently 3 is also deleted.
//Then, delete 2 to earn 2 points. 6 total points are earned.
// 
//
// 
//
// Example 2: 
//
// 
//Input: nums = [2, 2, 3, 3, 3, 4]
//Output: 9
//Explanation: 
//Delete 3 to earn 3 points, deleting both 2's and the 4.
//Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
//9 total points are earned.
// 
//
// 
//
// Note: 
//
// 
// The length of nums is at most 20000. 
// Each element nums[i] is an integer in the range [1, 10000]. 
// 
//
// 
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        auto u_nums = vector<pair<int, int>>();
        auto pre = INT_MIN, cnt = 0;
        for (auto const num : nums) {
            if (num == pre) ++cnt;
            else {
                if (cnt > 0) {
                    u_nums.emplace_back(pre, cnt);
                }
                pre = num, cnt = 1;
            }
        }
        u_nums.emplace_back(pre, cnt);

        auto dp = vector<int>(u_nums.size() + 1, 0);
        dp[1] = u_nums.front().first * u_nums.front().second;
        for (auto i = 1; i < u_nums.size(); ++i) {
            auto const earn = u_nums[i].first * u_nums[i].second;
            if (u_nums[i - 1].first + 1 == u_nums[i].first) {
                dp[i + 1] = max(dp[i - 1] + earn, dp[i]);
            } else {
                dp[i + 1] = max(dp[i] + earn, dp[i - 1]);
            }
        }
        return max(dp[u_nums.size()], dp[u_nums.size() - 1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestDeleteAndEarn, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{3, 4, 2},          6},
            {{2, 2, 3, 3, 3, 4}, 9},
            {{2, 2, 2},          6},
            {{},                 0}
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.deleteAndEarn(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
