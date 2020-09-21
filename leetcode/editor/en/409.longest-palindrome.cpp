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
// 👍 988 👎 81


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindrome(string const& s) {
        auto vocab = array<unsigned, 52>();
        for (auto const c : s) {
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
