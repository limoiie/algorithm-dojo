#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an encoded string, return its decoded string. 
//
// The encoding rule is: k[encoded_string], where the encoded_string inside the 
//square brackets is being repeated exactly k times. Note that k is guaranteed to 
//be a positive integer. 
//
// You may assume that the input string is always valid; No extra white spaces, 
//square brackets are well-formed, etc. 
//
// Furthermore, you may assume that the original data does not contain any digit
//s and that digits are only for those repeat numbers, k. For example, there won't
// be input like 3a or 2[4]. 
//
// 
// Example 1: 
// Input: s = "3[a]2[bc]"
//Output: "aaabcbc"
// Example 2: 
// Input: s = "3[a2[c]]"
//Output: "accaccacc"
// Example 3: 
// Input: s = "2[abc]3[cd]ef"
//Output: "abcabccdcdcdef"
// Example 4: 
// Input: s = "abc3[cd]xyz"
//Output: "abccdcdcdxyz"
// Related Topics Stack Depth-first Search 
// 👍 3250 👎 165


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string decodeString(string const& s) {
        auto res = string();
        for (auto i = 0; i < s.size(); ++i) {
            if (isalpha(s[i])) {
                res.push_back(s[i]);
            } else if (isdigit(s[i])) {
                auto cnt = 0;
                while (s[i] != '[') {
                    cnt = cnt * 10 + s[i++] - '0';
                }
                auto l = ++i, k = 1;
                while (true) {
                    if (s[i] == '[') {
                        ++k;
                    } else if (s[i] == ']') {
                        if (0 == --k) break;
                    }
                    ++i;
                }

                auto const sub = decodeString(s.substr(l, i - l));
                while (cnt--) {
                    res.append(sub);
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestDecodeString, testcase) {
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
