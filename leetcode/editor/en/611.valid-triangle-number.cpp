#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an array consists of non-negative integers, your task is to count the nu
//mber of triplets chosen from the array that can make triangles if we take them a
//s side lengths of a triangle.
//
// Example 1: 
// 
//Input: [2,2,3,4]
//Output: 3
//Explanation:
//Valid combinations are: 
//2,3,4 (using the first 2)
//2,3,4 (using the second 2)
//2,2,3
// 
// 
//
// Note: 
// 
// The length of the given array won't exceed 1000. 
// The integers in the given array are in the range of [0, 1000]. 
// 
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto res = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            auto j = i + 1, k = i + 2;
            while (j < nums.size() and k < nums.size()) {
                if (j == k) {
                    ++k;
                } else if (nums[i] + nums[j] > nums[k]) {
                    res += k - j;
                    ++k;
                } else {
                    ++j;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestValidTriangleNumber, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{3,3,3,3}, 3},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.triangleNumber(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
