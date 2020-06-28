#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a binary array, find the maximum number of consecutive 1s in this array.
// 
//
// Example 1: 
// 
//Input: [1,1,0,1,1,1]
//Output: 3
//Explanation: The first two digits or the last three digits are consecutive 1s.
//
//    The maximum number of consecutive 1s is 3.
// 
// 
//
// Note:
// 
// The input array will only contain 0 and 1. 
// The length of input array is a positive integer and will not exceed 10,000 
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        auto cnt = 0, max_cnt = 0;
        for (auto num : nums) {
            if (num) {
                max_cnt = max(max_cnt, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return max_cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestMaxConsecutiveOnes, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{1, 1, 0, 1, 1, 1}, 3},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findMaxConsecutiveOnes(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
