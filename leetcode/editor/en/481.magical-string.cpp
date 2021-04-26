#include "base.h"
//
//A magical string S consists of only '1' and '2' and obeys the following rules:
//
// 
// 
//The string S is magical because concatenating the number of contiguous occurre
//nces of characters '1' and '2' generates the string S itself.
// 
//
// 
//The first few elements of string S is the following:
//S = "1221121221221121122……"
// 
//
// 
//If we group the consecutive '1's and '2's in S, it will be:
// 
// 
//1 22 11 2 1 22 1 22 11 2 11 22 ......
// 
// 
//and the occurrences of '1's or '2's in each group are:
// 
// 
//1 2 2 1 1 2 1 2 2 1 2 2 ......
// 
//
// 
//You can see that the occurrence sequence above is the S itself. 
// 
//
// 
//Given an integer N as input, return the number of '1's in the first N number i
//n the magical string S.
// 
//
// Note:
//N will not exceed 100,000.
// 
//
//
// Example 1: 
// 
//Input: 6
//Output: 3
//Explanation: The first 6 elements of magical string S is "12211" and it contai
//ns three 1's, so return 3.
// 
// 👍 123 👎 736


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;

        auto s = vector<bool>(n, false);
        s[0] = true;
        auto p = false;
        for (auto i = 1, k = 1; i < n; ++k, p = !p) {
            for (auto j = i + (s[k] ? 1 : 2); i < j && i < n; ++i) {
                s[i] = p;
            }
        }

        return count_if(s.begin(), s.end(), [](int const v) { return v; });
    }

};
//leetcode submit region end(Prohibit modification and deletion)

TEST(TEST_CASE, test_solution) { // NOLINT(cert-err58-cpp)
    std::cout << "Testing " <<  __PRETTY_FUNCTION__ << " ..." << std::endl;
}