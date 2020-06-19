#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

//#include <gtest/gtest.h>
#include "base.h"

//Consider the string s to be the infinite wraparound string of "abcdefghijklmno
//pqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghi
//jklmnopqrstuvwxyzabcd....". 
//
// Now we have another string p. Your job is to find out how many unique non-emp
//ty substrings of p are present in s. In particular, your input is the string p a
//nd you need to output the number of different non-empty substrings of p in the s
//tring s. 
//
// Note: p consists of only lowercase English letters and the size of p might be
// over 10000. 
//
// Example 1: 
// 
//Input: "a"
//Output: 1
//
//Explanation: Only the substring "a" of string "a" is in the string s.
// 
// 
//
// Example 2: 
// 
//Input: "cac"
//Output: 2
//Explanation: There are two substrings "a", "c" of string "cac" in the string s
//.
// 
// 
//
// Example 3: 
// 
//Input: "zab"
//Output: 6
//Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of stri
//ng "zab" in the string s.
// 
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        // the count of substrings that ends at 'a-z'
        auto dp = vector<int>(26, 0);
        auto len = 0;
        auto prev = p.front();
        for (auto const c : p) {
            auto const i = c - 'a';
            if (not is_continue(prev, c)) {
                len = 0;
            }
            dp[i] = max(dp[i], ++len);
            prev = c;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }

    inline
    bool is_continue(char const prev, char const next) {
        return next - prev == 1 or (prev == 'z' and next == 'a');
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
