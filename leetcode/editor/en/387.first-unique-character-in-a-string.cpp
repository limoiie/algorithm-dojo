#include "base.h"
//Given a string, find the first non-repeating character in it and return its in
//dex. If it doesn't exist, return -1. 
//
// Examples: 
//
// 
//s = "leetcode"
//return 0.
//
//s = "loveleetcode"
//return 2.
// 
//
// 
//
// Note: You may assume the string contains only lowercase English letters. 
// Related Topics Hash Table String 
// 👍 1976 👎 117


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstUniqChar(string const& s) {
        auto shown = vector<int>(26, 0);
        for (auto c : s) {
            ++shown[c - 'a'];
        }
        for (auto i = 0; i < s.size(); ++i) {
            if (shown[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
