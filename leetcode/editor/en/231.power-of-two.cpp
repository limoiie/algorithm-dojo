#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an integer, write a function to determine if it is a power of two. 
//
// Example 1: 
//
// 
//Input: 1
//Output: true 
//Explanation: 20 = 1
// 
//
// Example 2: 
//
// 
//Input: 16
//Output: true
//Explanation: 24 = 16 
//
// Example 3: 
//
// 
//Input: 218
//Output: false 
// Related Topics Math Bit Manipulation


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        auto bits = 0;
        while (n) {
            bits += n & 1u;
            n >>= 1u;
        }
        return bits == 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestPowerOfTwo, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, bool>>{
//            {0u, false},
//            {1u, true},
//            {256u, true},
            {-2147483648, false}
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.isPowerOfTwo(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
