#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a positive integer num, write a function which returns True if num is a 
//perfect square else False. 
//
// Follow up: Do not use any built-in library function such as sqrt. 
//
// 
// Example 1: 
// Input: num = 16
//Output: true
// Example 2: 
// Input: num = 14
//Output: false
// 
// 
// Constraints: 
//
// 
// 1 <= num <= 2^31 - 1 
// 
// Related Topics Math Binary Search


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        auto l = 0, r = num;
        while (l <= r) {
            auto const m = (l + r) / 2;
            auto const m_2 = (long long) m * (long long) m;
            if (m_2 < num) {
                l = m + 1;
            } else if (m_2 > num) {
                r = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestValidPerfectSquare, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, bool>>{
            {1, true},
            {16, true},
            {15, false},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.isPerfectSquare(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
