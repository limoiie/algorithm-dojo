#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//Given a string S, find the number of different non-empty palindromic subsequen
//ces in S, and return that number modulo 10^9 + 7.
// 
//A subsequence of a string S is obtained by deleting 0 or more characters from 
//S.
// 
//A sequence is palindromic if it is equal to the sequence reversed.
// 
//Two sequences A_1, A_2, ... and B_1, B_2, ... are different if there is some i
// for which A_i != B_i.
// 
//
// Example 1: 
// 
//Input: 
//S = 'bccb'
//Output: 6
//Explanation: 
//The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', '
//bcb', 'bccb'.
//Note that 'bcb' is counted only once, even though it occurs twice.
// 
// 
//
// Example 2: 
// 
//Input: 
//S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
//Output: 104860361
//Explanation: 
//There are 3104860382 different non-empty palindromic subsequences, which is 10
//4860361 modulo 10^9 + 7.
// 
// 
//
// Note:
// The length of S will be in the range [1, 1000]. 
// Each character S[i] will be in the set {'a', 'b', 'c', 'd'}. 
// Related Topics String Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static int constexpr mask = 7 + 1e9;
public:
    int countPalindromicSubsequences(string const &S) {
        auto const n = static_cast<int>(S.size());
        auto dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

        for (auto i = 0; i <= n; ++i) {
            dp[i][i] = 1;
            if (i > 0) dp[i - 1][i] = +2;
            if (i > 1) dp[i][i - 2] = -1;
            if (i > 2) dp[i][i - 3] = -2;
        }

        for (auto len = 3; len <= n; ++len) {
            for (auto i = 0, j = len - 1; i < n - len + 1; ++i, ++j) {
                if (S[i] == S[j]) {
                    auto l = i + 1, r = j - 1;
                    while (l <= r && S[l] != S[i]) ++l;
                    while (l <= r && S[r] != S[j]) --r;
                    dp[i][j] = dp[i + 1][j - 1] * 2 - dp[l + 1][r - 1];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + mask : dp[i][j] % mask;
            }
        }
        return dp[0][n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestCountDifferentPalindromicSubsequences, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, int>>{
            {"bccb", 6},
            {"aaaa", 4},
            {"aa", 2},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.countPalindromicSubsequences(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
