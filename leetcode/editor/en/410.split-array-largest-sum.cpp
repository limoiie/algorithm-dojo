#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

//#include <gtest/gtest.h>
#include "base.h"

//Given an array which consists of non-negative integers and an integer m, you c
//an split the array into m non-empty continuous subarrays. Write an algorithm to 
//minimize the largest sum among these m subarrays.
// 
//
// Note: 
//If n is the length of array, assume the following constraints are satisfied:
// 
// 1 ≤ n ≤ 1000 
// 1 ≤ m ≤ min(50, n) 
// 
// 
//
// Examples: 
// 
//Input:
//nums = [7,2,5,10,8]
//m = 2
//
//Output:
//18
//
//Explanation:
//There are four ways to split nums into two subarrays.
//The best way is to split it into [7,2,5] and [10,8],
//where the largest sum among the two subarrays is only 18.
// 
// Related Topics Binary Search Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int splitArray(vector<int> &nums, int k) {
        long long l = *max_element(nums.begin(), nums.end());
        long long r = accumulate(nums.begin(), nums.end(), 0L);
        while (l < r) {
            auto const m = l + (r - l) / 2;
            if (split(nums, m, k) > k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return static_cast<int>(l);
    }

    int split(vector<int> &nums, long long max_sum, int const target_cnt) {
        auto cnt = 1;
        long long acc = 0;
        for (auto num : nums) {
            if (acc + num > max_sum) {
                if (cnt++ == target_cnt) {
                    break;
                }
                acc = 0;
            }
            acc += num;
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
