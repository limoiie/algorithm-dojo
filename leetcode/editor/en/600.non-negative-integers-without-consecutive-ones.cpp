#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a positive integer n, find the number of non-negative integers less than
// or equal to n, whose binary representations do NOT contain consecutive ones. 
//
// Example 1: 
// 
//Input: 5
//Output: 5
//Explanation: 
//Here are the non-negative integers <= 5 with their corresponding binary repres
//entations:
//0 : 0
//1 : 1
//2 : 10
//3 : 11
//4 : 100
//5 : 101
//Among them, only integer 3 disobeys the rule (two consecutive ones) and the ot
//her 5 satisfy the rule. 
// 
// 
//
// Note:
//1 <= n <= 109
// 
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static constexpr auto MAX_BITS = sizeof(int) * CHAR_BIT;
    // answer for (2^i)-1, where i \in [0, MAX_BITS]
    static constexpr auto dp = []() {
        auto x = array<int, MAX_BITS + 1>();
        x[0] = 1, x[1] = 2;
        for (auto i = 2; i <= MAX_BITS; ++i) {
            x[i] = x[i - 1] + x[i - 2];
        }
        return x;
    }();

public:
    int findIntegers(unsigned num) {
        auto ans = 0, prev_bit = 0;
        for (auto i = MAX_BITS - 1; i < MAX_BITS; --i) {
            auto const curr_bit = num & (1u << i);
            if (curr_bit) {
                ans += dp[i];
                if (prev_bit) return ans;
            }
            prev_bit = curr_bit;
        }
        return ans + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestNonNegativeIntegersWithoutConsecutiveOnes, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<unsigned, int>> {
            {5, 5},
            {6, 5},
            {7, 5},
            {14, 8},
            {62, 21},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findIntegers(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
