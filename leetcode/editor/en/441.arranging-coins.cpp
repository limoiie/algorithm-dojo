#include "base.h"
//You have a total of n coins that you want to form in a staircase shape, where 
//every k-th row must have exactly k coins. 
// 
// Given n, find the total number of full staircase rows that can be formed. 
//
// n is a non-negative integer and fits within the range of a 32-bit signed inte
//ger. 
//
// Example 1:
// 
//n = 5
//
//The coins can form the following rows:
//¤
//¤ ¤
//¤ ¤
//
//Because the 3rd row is incomplete, we return 2.
// 
// 
//
// Example 2:
// 
//n = 8
//
//The coins can form the following rows:
//¤
//¤ ¤
//¤ ¤ ¤
//¤ ¤
//
//Because the 4th row is incomplete, we return 3.
// 
// Related Topics Math Binary Search 
// 👍 719 👎 728


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int arrangeCoins(int n) {
        auto compute = [](long long int const x) {
            return (x + 1) * x / 2;
        };

        auto l = 0, r = n;
        while (l <= r) {
            auto const m = l + (r - l) / 2;
            auto const z = compute(m);
            if (z == n) {
                return m;
            } else if (z < n) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
