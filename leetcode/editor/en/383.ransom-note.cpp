#include "base.h"
//Given an arbitrary ransom note string and another string containing letters fr
//om all the magazines, write a function that will return true if the ransom note 
//can be constructed from the magazines ; otherwise, it will return false. 
//
// Each letter in the magazine string can only be used once in your ransom note.
// 
//
// 
// Example 1: 
// Input: ransomNote = "a", magazine = "b"
//Output: false
// Example 2: 
// Input: ransomNote = "aa", magazine = "ab"
//Output: false
// Example 3: 
// Input: ransomNote = "aa", magazine = "aab"
//Output: true
// 
// 
// Constraints: 
//
// 
// You may assume that both strings contain only lowercase letters. 
// 
// Related Topics String 
// 👍 633 👎 198


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string const& ransomNote, string const& magazine) {
        auto m = std::array<int, 26>();
        for (auto const c : ransomNote) {
            ++m[c - 'a'];
        }
        for (auto const c : magazine) {
            --m[c - 'a'];
        }
        for (auto i = 0; i < 26; ++i) {
            if (m[i] > 0) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
