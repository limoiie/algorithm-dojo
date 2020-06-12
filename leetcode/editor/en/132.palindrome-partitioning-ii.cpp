#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a string s, partition s such that every substring of the partition is a 
//palindrome. 
//
// Return the minimum cuts needed for a palindrome partitioning of s. 
//
// Example: 
//
// 
//Input: "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 
//cut.
// 
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCut(string const& s) {
        auto dp = vector<int>(s.size() + 1, INT_MAX-1);
        dp[0] = dp[1] = 0;

        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (is_palindrome(s, j, i)) {
                    dp[i+1] = min(dp[i+1], dp[j] + (j == 0 ? 0 : 1));
                }
            }
        }
        return dp[s.size()];
    }

    bool is_palindrome(string const& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestPalindromePartitioningII, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, int>>{
            {"aab", 1},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.minCut(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
