#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//Given an unsorted array of integers, find the number of longest increasing sub
//sequence.
// 
//
// Example 1: 
// 
//Input: [1,3,5,4,7]
//Output: 2
//Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3
//, 5, 7].
// 
// 
//
// Example 2: 
// 
//Input: [2,2,2,2,2]
//Output: 5
//Explanation: The length of longest continuous increasing subsequence is 1, and
// there are 5 subsequences' length is 1, so output 5.
// 
// 
//
// Note:
//Length of the given array will be not exceed 2000 and the answer is guaranteed
// to be fit in 32-bit signed int.
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestNumberOfLongestIncreasingSubsequence, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<..>>{
            {},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.foo(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
