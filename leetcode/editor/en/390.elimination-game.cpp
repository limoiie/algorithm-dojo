#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//There is a list of sorted integers from 1 to n. Starting from left to right, r
//emove the first number and every other number afterward until you reach the end 
//of the list. 
//
// Repeat the previous step again, but this time from right to left, remove the 
//right most number and every other number from the remaining numbers. 
//
// We keep repeating the steps again, alternating left to right and right to lef
//t, until a single number remains. 
//
// Find the last number that remains starting with a list of length n. 
//
// Example:
// 
//Input:
//n = 9,
//1 2 3 4 5 6 7 8 9
//2 4 6 8
//2 6
//6
//
//Output:
//6
// 
// 👍 428 👎 335


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lastRemaining(unsigned n) {
        auto l = 1u, r = n;
        for (auto i = 0u, gap = 1u; l != r; ++i, gap <<= 1u, n >>= 1u) {
            if (n & 1u) {
                l += gap;
                r -= gap;
            } else if (i & 1u) {
                r -= gap;
            } else {
                l += gap;
            }
        }
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestEliminationGame, testcase) {
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
