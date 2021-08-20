#include "base.h"
//We define the usage of capitals in a word to be right when one of the followin
//g cases holds: 
//
// 
// All letters in this word are capitals, like "USA". 
// All letters in this word are not capitals, like "leetcode". 
// Only the first letter in this word is capital, like "Google". 
// 
//
// Given a string word, return true if the usage of capitals in it is right. 
//
// 
// Example 1: 
// Input: word = "USA"
//Output: true
// Example 2: 
// Input: word = "FlaG"
//Output: false
// 
// 
// Constraints: 
//
// 
// 1 <= word.length <= 100 
// word consists of lowercase and uppercase English letters. 
// 
// Related Topics String 
// 👍 819 👎 293


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool detectCapitalUse(string const& word) {
        if (isupper(word.front())) {
            return is_all_lowercase(word.substr(1)) ||
                   is_all_uppercase(word);
        }
        return is_all_lowercase(word);
    }

private:
    static
    bool is_all_lowercase(string const& word) {
        return all_of(word.begin(), word.end(), [](char c) { return islower(c); });
    }

    static
    bool is_all_uppercase(string const& word) {
        return all_of(word.begin(), word.end(), [](char c) { return isupper(c); });
    }
};
//leetcode submit region end(Prohibit modification and deletion)
