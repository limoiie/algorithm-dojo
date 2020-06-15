#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Calculate the sum of two integers a and b, but you are not allowed to use the 
//operator + and -. 
//
// 
// Example 1: 
//
// 
//Input: a = 1, b = 2
//Output: 3
// 
//
// 
// Example 2: 
//
// 
//Input: a = -2, b = 3
//Output: 1
// 
// 
// 
// Related Topics Bit Manipulation


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getSum(int a, int b) {
        auto x = static_cast<unsigned>(a);
        auto y = static_cast<unsigned>(b);
        while (y) {
            auto new_x = x ^ y;
            auto new_y = (x & y) << 1u;
            x = new_x;
            y = new_y;
        }
        return x;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestSumOfTwoIntegers, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, int, int>>{
            {123, 123, 246},
            {1, 123, 124},
            {123, -123, 0},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.getSum(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
