#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given two integer arrays A and B, return the maximum length of an subarray tha
//t appears in both arrays. 
//
// Example 1: 
//
// 
//Input:
//A: [1,2,3,2,1]
//B: [3,2,1,4,7]
//Output: 3
//Explanation: 
//The repeated subarray with maximum length is [3, 2, 1].
// 
//
// 
//
// Note: 
//
// 
// 1 <= len(A), len(B) <= 1000 
// 0 <= A[i], B[i] < 100 
// 
//
// 
// Related Topics Array Hash Table Binary Search Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLength(vector<int> &A, vector<int> &B) {
        auto ans = 0;
        auto const m = static_cast<int>(A.size());
        auto const n = static_cast<int>(B.size());
        auto dp = vector<int>(n + 1, 0);
        for (auto i = 0; i < m; ++i) {
            for (auto j = n; j > 0; --j) {
                dp[j] = 0;
                if (A[i] == B[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                }
                ans = max(ans, dp[j]);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestMaximumLengthOfRepeatedSubarray, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, vector<int>, int>>{
            {{1,2,3,2,1}, {3,2,1,4,7}, 3},
            {{0,1,1,1,1}, {1,0,1,0,1}, 2},
            {{1,0,0,0,1}, {1,0,0,1,1}, 3},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findLength(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
