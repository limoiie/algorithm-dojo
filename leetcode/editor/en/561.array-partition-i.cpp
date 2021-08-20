#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//Given an array of 2n integers, your task is to group these integers into n pai
//rs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, 
//bi) for all i from 1 to n as large as possible.
// 
//
// Example 1: 
// 
//Input: [1,4,3,2]
//
//Output: 4
//Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4)
//.
// 
// 
//
// Note: 
// 
// n is a positive integer, which is in the range of [1, 10000]. 
// All the integers in the array will be in the range of [-10000, 10000]. 
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto sum = 0;
        for (auto i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestArrayPartitionI, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{1,4,3,2,}, 4},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.arrayPairSum(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
