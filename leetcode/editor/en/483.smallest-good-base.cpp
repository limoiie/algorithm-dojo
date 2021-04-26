#include "base.h"
//For an integer n, we call k>=2 a good base of n, if all digits of n base k are
// 1. 
//
// Now given a string representing n, you should return the smallest good base o
//f n in string format. 
//
// Example 1: 
//
// 
//Input: "13"
//Output: "3"
//Explanation: 13 base 3 is 111.
// 
//
// 
//
// Example 2: 
//
// 
//Input: "4681"
//Output: "8"
//Explanation: 4681 base 8 is 11111.
// 
//
// 
//
// Example 3: 
//
// 
//Input: "1000000000000000000"
//Output: "999999999999999999"
//Explanation: 1000000000000000000 base 999999999999999999 is 11.
// 
//
// 
//
// Note: 
//
// 
// The range of n is [3, 10^18]. 
// The string representing n is always valid and will not have leading zeros. 
// 
//
// 
// Related Topics Math Binary Search 
// 👍 178 👎 353


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string smallestGoodBase(string const& num) {
        auto const n = stoll(num);
        for (auto k = 61; k > 2; --k) {
            long long unsigned l = 2, r = n - 1;
            while (l <= r) {
                auto const x = l + ((r - l) >> 1u);
                long long unsigned sum_of_series = 1;
                auto too_big = false;
                for (long long unsigned j = 1, term = 1; j < k; ++j) {
                    if (term > (n - sum_of_series) / x) {
                        too_big = true;
                        break;
                    }
                    sum_of_series += (term *= x);
                }
                if (too_big || sum_of_series > n) {
                    r = x - 1;
                } else if (sum_of_series < n) {
                    l = x + 1;
                } else {
                    return to_string(x);
                }
            }
        }
        return to_string(n - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

TEST(TEST_CASE, test_solution) { // NOLINT(cert-err58-cpp)
    std::cout << "Testing " <<  __PRETTY_FUNCTION__ << " ..." << std::endl;
    auto sol = Solution();
    cout << sol.smallestGoodBase("2251799813685247") << endl;
}