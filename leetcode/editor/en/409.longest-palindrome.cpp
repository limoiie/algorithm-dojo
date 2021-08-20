#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a string which consists of lowercase or uppercase letters, find the leng
//th of the longest palindromes that can be built with those letters. 
//
// This is case sensitive, for example "Aa" is not considered a palindrome here.
// 
//
// Note: 
//Assume the length of given string will not exceed 1,010.
// 
//
// Example: 
// 
//Input:
//"abccccdd"
//
//Output:
//7
//
//Explanation:
//One longest palindrome that can be built is "dccaccd", whose length is 7.
// 
// Related Topics Hash Table 
// 👍 987 👎 81


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindrome(string const& s) {
        auto vocab = array<unsigned, 58>();
        for (auto c : s) {
            ++vocab[c - 'A'];
        }

        auto res = 0;
        auto has_obb = false;
        for (auto cnt : vocab) {
            if (cnt & 1u) {
                has_obb = true;
                --cnt;
            }
            res += cnt;
        }
        return res + (has_obb ? 1 : 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


 TEST(TestLongestPalindrome, testcase) {
     auto sol = Solution();

     auto cases = vector<tuple<string, int>>{
             {"zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez", 0},
     };

     for (auto & c : cases) {
         cout << "testing " << c << "..." << endl;
         auto result = sol.longestPalindrome(get<0>(c));
         auto expect = get<1>(c);
         ASSERT_EQ(result, expect);
     }
 }
