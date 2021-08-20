#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given two non-negative integers num1 and num2 represented as string, return th
//e sum of num1 and num2. 
//
// Note:
// 
// The length of both num1 and num2 is < 5100. 
// Both num1 and num2 contains only digits 0-9. 
// Both num1 and num2 does not contain any leading zero. 
// You must not use any built-in BigInteger library or convert the inputs to int
//eger directly. 
// 
// Related Topics String 
// 👍 1066 👎 281


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string const& num1, string const& num2) {
        auto const n = max(num1.size(), num2.size());
        auto sum = string();

        auto in_bit = 0;
        for (auto i = 0; i < n; ++i) {
            auto const i1 = static_cast<int>(num1.size()) - 1 - i;
            auto const i2 = static_cast<int>(num2.size()) - 1 - i;
            auto const sum_bit = (i1 < 0 ? 0 : num1[i1] - '0') +
                    (i2 < 0 ? 0 : num2[i2] - '0') + in_bit;
            sum.push_back((sum_bit % 10) + '0');
            in_bit =  sum_bit > 9 ? 1 : 0;
        }
        if (in_bit) {
            sum.push_back('1');
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestAddStrings, testcase) {
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
