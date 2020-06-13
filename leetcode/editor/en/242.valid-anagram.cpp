#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given two strings s and t , write a function to determine if t is an anagram o
//f s. 
//
// Example 1: 
//
// 
//Input: s = "anagram", t = "nagaram"
//Output: true
// 
//
// Example 2: 
//
// 
//Input: s = "rat", t = "car"
//Output: false
// 
//
// Note: 
//You may assume the string contains only lowercase alphabets. 
//
// Follow up: 
//What if the inputs contain unicode characters? How would you adapt your soluti
//on to such case? 
// Related Topics Hash Table Sort


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string const& s, string const& t) {
        auto l = hash_mem(s);
        auto r = hash_mem(t);
        for (auto i = 0; i < 26; ++i) {
            if (l[i] != r[i]) return false;
        }
        return true;
    }

    vector<int> hash_mem(string const& s) {
        auto l = vector<int>(26, 0);
        for (auto c : s) {
            ++l[c - 'a'];
        }
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestValidAnagram, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, string, bool>>{
            {"", "", false},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.isAnagram(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
