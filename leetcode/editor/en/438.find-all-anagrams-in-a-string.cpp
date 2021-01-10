#include "base.h"
//Given a string s and a non-empty string p, find all the start indices of p's a
//nagrams in s. 
//
// Strings consists of lowercase English letters only and the length of both str
//ings s and p will not be larger than 20,100. 
//
// The order of output does not matter. 
//
// Example 1:
// 
//Input:
//s: "cbaebabacd" p: "abc"
//
//Output:
//[0, 6]
//
//Explanation:
//The substring with start index = 0 is "cba", which is an anagram of "abc".
//The substring with start index = 6 is "bac", which is an anagram of "abc".
// 
// 
//
// Example 2:
// 
//Input:
//s: "abab" p: "ab"
//
//Output:
//[0, 1, 2]
//
//Explanation:
//The substring with start index = 0 is "ab", which is an anagram of "ab".
//The substring with start index = 1 is "ba", which is an anagram of "ab".
//The substring with start index = 2 is "ab", which is an anagram of "ab".
// 
// Related Topics Hash Table 
// 👍 3511 👎 183


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string const& s, string const& p) {
        auto res = vector<int>();
        if (s.size() < p.size()) return res;

        auto dict = map<char, int>();
        auto non_zero_cnt = 0;
        for (auto const c : p) {
            if (dict[c]++ == 0) {
                ++non_zero_cnt;
            }
        }

        auto const m = p.size();
        for (auto i = 0; i < s.size(); ++i) {
            if (dict[s[i]] == 0) ++non_zero_cnt;
            if (--dict[s[i]] == 0) --non_zero_cnt;

            if (i >= m) {
                auto const j = i - m;
                if (dict[s[j]] == 0) ++non_zero_cnt;
                if (++dict[s[j]] == 0) --non_zero_cnt;
            }

            if (i + 1 >= m && non_zero_cnt == 0) {
                res.push_back(i - m + 1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
