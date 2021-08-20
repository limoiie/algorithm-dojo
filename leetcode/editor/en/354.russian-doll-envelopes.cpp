#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//You have a number of envelopes with widths and heights given as a pair of inte
//gers (w, h). One envelope can fit into another if and only if both the width and
// height of one envelope is greater than the width and height of the other envelo
//pe. 
//
// What is the maximum number of envelopes can you Russian doll? (put one inside
// other) 
//
// Note: 
//Rotation is not allowed. 
//
// Example: 
//
// 
// 
//Input: [[5,4],[6,4],[6,7],[2,3]]
//Output: 3 
//Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] 
//=> [5,4] => [6,7]).
// 
// 
// Related Topics Binary Search Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](auto const &lhs, auto const &rhs) {
                 if (lhs[0] == rhs[0]) return lhs[1] > rhs[1];
                 return lhs[0] < rhs[0];
             });

        auto n = 0;
        auto dp = vector<int>(envelopes.size(), 0);
        for (auto const &env : envelopes) {
            auto const i = binary_search(dp, n, env[1]);
            dp[i] = env[1];
            n = max(n, i + 1);
        }
        return n;
    }

    int binary_search(vector<int> const &num, int size, int target) {
        auto l = 0, r = size - 1;
        while (l <= r) {
            auto const m = (l + r) / 2;
            if (target > num[m]) {
                l = m + 1;
            } else if (target == num[m]) {
                return m;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestRussianDollEnvelopes, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, int>>
            {
                    {{{5, 4}, {6, 4}, {6, 7}, {2, 3}}, 3},
            };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.maxEnvelopes(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
