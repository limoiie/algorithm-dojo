#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an array of integers and an integer k, you need to find the total number
// of continuous subarrays whose sum equals to k. 
//
// Example 1: 
//
// 
//Input:nums = [1,1,1], k = 2
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// The length of the array is in range [1, 20,000]. 
// The range of numbers in the array is [-1000, 1000] and the range of the integ
//er k is [-1e7, 1e7]. 
// 
// Related Topics Array Hash Table


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        nums.insert(nums.begin(), 0);
        partial_sum(nums.begin(), nums.end(), nums.begin());
        auto mem = unordered_map<int, int>();
        auto cnt = 0;
        for (auto const num : nums) {
            if (mem.find(num - k) != mem.end()) {
                cnt += mem[num - k];
            }
            ++mem[num];
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestSubarraySumEqualsK, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int, int>>{
            {{1, 1, 1}, 2, 2},
            {{0,0,0,0,0,0,0,0,0,0}, 0, 55},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.subarraySum(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
