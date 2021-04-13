#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//Find the length of the longest substring T of a given string (consists of lowe
//rcase letters only) such that every character in T appears no less than k times.
//
// 
//
// Example 1:
// 
//Input:
//s = "aaabb", k = 3
//
//Output:
//3
//
//The longest substring is "aaa", as 'a' is repeated 3 times.
// 
// 
//
// Example 2:
// 
//Input:
//s = "ababbc", k = 2
//
//Output:
//5
//
//The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeat
//ed 3 times.
// 
// 👍 1483 👎 116


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestSubstring(string const& s, int k) {
        auto cnt = array<int, 26>();
        for (auto const c : s) {
            ++cnt[c - 'a'];
        }
        auto l = 0, r = static_cast<int>(s.size()) - 1;
        auto i = 0, j = static_cast<int>(s.size()) - 1;
        while (i <= j) {
            if (cnt[s[i] - 'a'] < k) {
                while (l <= i) {
                    --cnt[s[l++] - 'a'];
                }
                ++i, j = r;
            } else if (cnt[s[j] - 'a'] < k) {
                while (r >= j) {
                    --cnt[s[r--] - 'a'];
                }
                --j, i = l;
            } else {
                ++i, --j;
            }
        }
        return r - l + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestLongestSubstringWithAtLeastKRepeatingCharacters, testcase) {
//     auto sol = Solution();
// 
//     auto cases = vector<tuple<..>>{
//             {},
//     };
// 
//     for (auto & c : cases) {
//         cout << "testing " << c << "..." << endl;
//         auto result = sol.foo(get<0>(c));
//         auto expect = get<1>(c);
//         ASSERT_EQ(result, expect);
//     }
// }
