#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

//#include <gtest/gtest.h>
#include "base.h"

//Given a string s, find the longest palindromic subsequence's length in s. You 
//may assume that the maximum length of s is 1000. 
//
// Example 1: 
//Input: 
//
// 
//"bbbab"
// 
//Output:
//
// 
//4
// 
//One possible longest palindromic subsequence is "bbbb".
//
// 
//
// Example 2: 
//Input: 
//
// 
//"cbbd"
// 
//Output:
//
// 
//2
// 
//One possible longest palindromic subsequence is "bb".
// 
// Constraints: 
//
// 
// 1 <= s.length <= 1000 
// s consists only of lowercase English letters. 
// 
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindromeSubseq(string const& s) {
        auto dp = vector<int>(s.size(), 0);
        for (auto r = 0; r < s.size(); ++r) {
            for (auto l = 0; l < r; ++l) {
                if (s[l] == s[r]) {
                    dp[l] = max(dp[l], dp[l + 1] + 2);
                }
            }
            dp[r] = 1;
            for (auto l = r - 1; l >= 0; --l) {
                dp[l] = max(dp[l], dp[l+1]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


//TEST(TestLowestCommonAncestorOfABinarySearchTree, testcase) {
//    auto sol = Solution();
//
//    auto cases = vector<tuple<TreeNode*, TreeNode*, TreeNode*, TreeNode*>>{
//            {},
//    };
//
//    for (auto & c : cases) {
//        cout << "testing " << c << "..." << endl;
//        auto result = sol.lowestCommonAncestor(get<0>(c), get<1>(c), get<2>(c));
//        auto expect = get<3>(c);
//        ASSERT_EQ(result, expect);
//    }
//}
