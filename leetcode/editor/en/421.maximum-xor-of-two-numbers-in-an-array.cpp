#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231. 
//
//
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n. 
//
// Could you do this in O(n) runtime? 
//
// Example: 
//
// 
//Input: [3, 10, 5, 25, 2, 8]
//
//Output: 28
//
//Explanation: The maximum result is 5 ^ 25 = 28.
// 
//
// 
// Related Topics Bit Manipulation Trie 
// 👍 1221 👎 170


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestMaximumXOROfTwoNumbersInAnArray, testcase) {
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
