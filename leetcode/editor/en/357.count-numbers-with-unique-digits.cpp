#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a non-negative integer n, count all numbers with unique digits, x, where
// 0 ≤ x < 10n. 
//
// 
// Example: 
//
// 
//Input: 2
//Output: 91 
//Explanation: The answer should be the total numbers in the range of 0 ≤ x < 10
//0, 
//             excluding 11,22,33,44,55,66,77,88,99
// 
// Related Topics Math Dynamic Programming Backtracking


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        auto cnt = 1;
        for (auto i = 0; i < n; ++i) {
            auto a = 9;
            for (auto j = 0; j < i; ++j) {
                a *= 9 - j;
            }
            cnt += a;
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestCountNumbersWithUniqueDigits, testcase) {
    auto sol = Solution();
    auto cases = vector<tuple<int, int>>{
            {2, 91},
            {3, 739},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.countNumbersWithUniqueDigits(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
