#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a string s that consists of only uppercase English letters, you can perf
//orm at most k operations on that string. 
//
// In one operation, you can choose any character of the string and change it to
// any other uppercase English character. 
//
// Find the length of the longest sub-string containing all repeating letters yo
//u can get after performing the above operations. 
//
// Note: 
//Both the string's length and k will not exceed 104. 
//
// Example 1: 
//
// 
//Input:
//s = "ABAB", k = 2
//
//Output:
//4
//
//Explanation:
//Replace the two 'A's with two 'B's or vice versa.
// 
//
// 
//
// Example 2: 
//
// 
//Input:
//s = "AABABBA", k = 1
//
//Output:
//4
//
//Explanation:
//Replace the one 'A' in the middle with 'B' and form "AABBBBA".
//The substring "BBBB" has the longest repeating letters, which is 4.
// 
//
// 
// Related Topics Two Pointers Sliding Window 
// 👍 1557 👎 87


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int characterReplacement(string const& s, int k) {
        auto cnt = vector(26, 0);
        auto max_len = 0, start = 0, most = 0;
        for (auto i = 0; i < s.size(); ++i) {
            most = max(most, ++cnt[s[i] - 'A']);
            if (i - start + 1 > most + k) {
                --cnt[s[start] - 'A'];
                ++start;
            }
            max_len = max(max_len, i - start + 1);
        }
        return max_len;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


 TEST(TestLongestRepeatingCharacterReplacement, testcase) {
     auto sol = Solution();

     auto cases = vector<tuple<string, int, int>>{
             {"AABA", 0, 2},
     };

     for (auto & c : cases) {
         cout << "testing " << c << "..." << endl;
         auto result = sol.characterReplacement(get<0>(c), get<1>(c));
         auto expect = get<2>(c);
         ASSERT_EQ(result, expect);
     }
 }
