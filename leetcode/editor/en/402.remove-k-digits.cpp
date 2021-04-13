#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a non-negative integer num represented as a string, remove k digits from
// the number so that the new number is the smallest possible.
// 
//
// Note: 
// 
// The length of num is less than 10002 and will be ≥ k. 
// The given num does not contain any leading zero. 
// 
//
// 
//
// Example 1:
// 
//Input: num = "1432219", k = 3
//Output: "1219"
//Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 w
//hich is the smallest.
// 
// 
//
// Example 2:
// 
//Input: num = "10200", k = 1
//Output: "200"
//Explanation: Remove the leading 1 and the number is 200. Note that the output 
//must not contain leading zeroes.
// 
// 
//
// Example 3:
// 
//Input: num = "10", k = 2
//Output: "0"
//Explanation: Remove all the digits from the number and it is left with nothing
// which is 0.
// 
// Related Topics Stack Greedy 
// 👍 2402 👎 105


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeKdigits(string const &num, int k) {
        auto res = string();
        for (auto i = 0; i < num.size(); ++i) {
            if (k == 0) {
                res.append(num.substr(i));
                break;
            }
            while (k != 0 and not res.empty() and num[i] < res.back()) {
                res.pop_back();
                --k;
            }
            res.push_back(num[i]);
        }
        while (k != 0) {
            res.pop_back();
            --k;
        }
        auto const e = res.find_first_not_of('0');
        if (e == string::npos) return string("0");
        return res.substr(e);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestRemoveKDigits, testcase) {
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
