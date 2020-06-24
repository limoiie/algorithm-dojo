#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a string, your task is to count how many palindromic substrings in this 
//string. 
//
// The substrings with different start indexes or end indexes are counted as dif
//ferent substrings even they consist of same characters. 
//
// Example 1: 
//
// 
//Input: "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
// 
//
// 
//
// Example 2: 
//
// 
//Input: "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// 
//
// 
//
// Note: 
//
// 
// The input string length won't exceed 1000. 
// 
//
// Related Topics String Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string chrs) {
        auto ans = chrs.size();
        auto dp = vector<int>(chrs.size(), 0);
        for (auto i = 1; i < chrs.size(); ++i) {
            for (auto j = 0; j < i; ++j) {
                dp[j] = 0;
                if (chrs[i] == chrs[j]) {
                    if (dp[j + 1] or j + 1 == i - 1 or j + 1 == i) {
                        dp[j] = 1;
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestPalindromicSubstrings, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, int>>
    {
            {"abc", 3},
            {"aaa", 6},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.countSubstrings(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
