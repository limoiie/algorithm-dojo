#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9,
// 10, 11, ... 
//
// Note: 
//n is positive and will fit within the range of a 32-bit signed integer (n < 23
//1).
// 
//
// Example 1:
// 
//Input:
//3
//
//Output:
//3
// 
// 
//
// Example 2:
// 
//Input:
//11
//
//Output:
//0
//
//Explanation:
//The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, 
//which is part of the number 10.
// 
// Related Topics Math 
// 👍 367 👎 1053


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNthDigit(long long n) {
        long long int w = 1, b = 0, r = 9;
        while (n > r * w) {
            n -= r * w;
            b += r;
            r *= 10;
            ++w;
        }

        auto const x = n / w;
        auto const y = n % w;
        auto const z = b + x + (y ? 1 : 0);
        return to_string(z)[(y - 1 + w) % w] - '0';
    }
};
//leetcode submit region end(Prohibit modification and deletion)


 TEST(TestNthDigit, testcase) {
     auto sol = Solution();

     auto cases = vector<tuple<int, int>>{
//             {3,3},
//             {11,0},
             {2000,0},
     };

     for (auto & c : cases) {
         cout << "testing " << c << "..." << endl;
         auto result = sol.findNthDigit(get<0>(c));
         auto expect = get<1>(c);
         ASSERT_EQ(result, expect);
     }
 }
