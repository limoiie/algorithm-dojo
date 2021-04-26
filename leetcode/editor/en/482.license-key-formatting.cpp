#include "base.h"
//You are given a license key represented as a string S which consists only alph
//anumeric character and dashes. The string is separated into N+1 groups by N dash
//es. 
//
// Given a number K, we would want to reformat the strings such that each group 
//contains exactly K characters, except for the first group which could be shorter
// than K, but still must contain at least one character. Furthermore, there must 
//be a dash inserted between two groups and all lowercase letters should be conver
//ted to uppercase. 
//
// Given a non-empty string S and a number K, format the string according to the
// rules described above. 
//
// Example 1: 
// 
//Input: S = "5F3Z-2e-9-w", K = 4
//
//Output: "5F3Z-2E9W"
//
//Explanation: The string S has been split into two parts, each part has 4 chara
//cters.
//Note that the two extra dashes are not needed and can be removed.
// 
// 
//
//
// Example 2: 
// 
//Input: S = "2-5g-3-J", K = 2
//
//Output: "2-5G-3J"
//
//Explanation: The string S has been split into three parts, each part has 2 cha
//racters except the first part as it could be shorter as mentioned above.
// 
// 
//
// Note: 
// 
// The length of string S will not exceed 12,000, and K is a positive integer. 
// String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-
//9) and dashes(-). 
// String S is non-empty. 
// 
// 👍 553 👎 851


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string licenseKeyFormatting(string const& S, int const K) {
        auto s = string();
        for (auto const c : S) {
            if (c == '-') continue;
            s.push_back(toupper(c));
        }
        auto const first = s.size() % K;
        auto ans = s.substr(0, first == 0 ? K : first);
        for (auto i = ans.size(); i < s.size(); i += K) {
            ans.push_back('-');
            ans.append(s.substr(i, K));
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
