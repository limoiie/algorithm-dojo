#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an integer array, you need to find one continuous subarray that if you o
//nly sort this subarray in ascending order, then the whole array will be sorted i
//n ascending order, too. 
//
// You need to find the shortest such subarray and output its length. 
//
// Example 1: 
// 
//Input: [2, 6, 4, 8, 10, 9, 15]
//Output: 5
//Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the 
//whole array sorted in ascending order.
// 
// 
//
// Note: 
// 
// Then length of the input array is in range [1, 10,000]. 
// The input array may contain duplicates, so ascending order here means <=. 
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        auto n = static_cast<int>(nums.size());
        auto min_val = INT_MAX, max_val = INT_MIN;

        auto seen = false;
        for (auto i = 1; i < n; --i) {
            if (!seen && nums[i] < nums[i - 1]) seen = true;
            if (seen) min_val = min(min_val, nums[i]);
        }

        seen = false;
        for (auto i = n - 1; i > 0; --i) {
            if (!seen && nums[i - 1] > nums[i]) seen = true;
            if (seen) max_val = max(max_val, nums[i - 1]);
        }

        auto l = 0, r = n - 1;
        while (l < n) if (nums[l++] > min_val) break;
        while (r >= 0) if (nums[r--] < max_val) break;
        return max(0, r - l + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestShortestUnsortedContinuousSubarray, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{2, 6, 4, 8, 10, 9, 15}, 5},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findUnsortedSubarray(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
