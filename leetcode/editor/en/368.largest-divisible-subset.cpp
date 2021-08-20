#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a set of distinct positive integers, find the largest subset such that e
//very pair (Si, Sj) of elements in this subset satisfies: 
//
// Si % Sj = 0 or Sj % Si = 0. 
//
// If there are multiple solutions, return any subset is fine. 
//
// Example 1: 
//
// 
// 
//Input: [1,2,3]
//Output: [1,2] (of course, [1,3] will also be ok)
// 
//
// 
// Example 2: 
//
// 
//Input: [1,2,4,8]
//Output: [1,2,4,8]
// 
// 
// Related Topics Math Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());
        auto dp = vector<int>(nums.size(), 0);
        auto pre = vector<int>(nums.size(), -1);
        auto k = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if (dp[i] > dp[k]) k = i;
        }

        auto res = vector<int>();
        while (k >= 0) {
            res.push_back(nums[k]);
            k = pre[k];
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestLargestDivisibleSubset, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, vector<int>>>{
            {{1,2,3}, {2,1}},
            {{1,2,4,8}, {8,4,2,1}},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.largestDivisibleSubset(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
