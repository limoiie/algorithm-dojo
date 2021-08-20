#pragma clang diagnostic push
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-interfaces-global-init"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//In a given array nums of positive integers, find three non-overlapping subarra
//ys with maximum sum. 
//
// Each subarray will be of size k, and we want to maximize the sum of all 3*k e
//ntries. 
//
// Return the result as a list of indices representing the starting position of 
//each interval (0-indexed). If there are multiple answers, return the lexicograph
//ically smallest one. 
//
// Example: 
//
// 
//Input: [1,2,1,2,6,7,5,1], 2
//Output: [0, 3, 5]
//Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indic
//es [0, 3, 5].
//We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicogra
//phically larger.
// 
//
// 
//
// Note: 
//
// 
// nums.length will be between 1 and 20000. 
// nums[i] will be between 1 and 65535. 
// k will be between 1 and floor(nums.length / 3). 
// 
//
// 
// Related Topics Array Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        auto part = accumulate(nums.begin(), nums.begin() + k, 0);
        auto parts = vector<int>{part};
        for (auto i = k, j = 0; i < nums.size(); ++i, ++j) {
            parts.push_back(part -= nums[j] - nums[i]);
        }

        auto dp_ = vector<int>(parts.size());
        auto dp_res_ = vector<vector<int>>(parts.size());
        for (auto l = 0; l < 3; ++l) {
            auto dp = vector<int>(parts.size(), 0);
            auto dp_res = vector<vector<int>>(parts.size());

            auto pre_idx = vector<int>{};
            auto pre_sum = INT_MIN;
            for (auto i = k * l; i < parts.size(); ++i) {
                auto const sum = parts[i] + (l == 0 ? 0 : dp_[i - k]);
                if (sum > pre_sum) {
                    pre_idx = l == 0 ? vector<int>{} : dp_res_[i - k];
                    pre_idx.push_back(i);
                    pre_sum = sum;
                }
                dp[i] = pre_sum;
                dp_res[i] = pre_idx;
            }
            dp_.swap(dp);
            dp_res_.swap(dp_res);
        }

        return dp_res_.back();
    }

    vector<int> maxSumOfThreeSubarrays2(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, max_idx_r[n - 2 * k];
        while (++i < n) nums[i] += nums[i - 1];
        while (--i >= k) nums[i] -= nums[i - k];
        i = n - 2 * k;
        int prev = n - 1;
        while (--i >= 0) {
            max_idx_r[i] = prev = (nums[i + 2 * k] >= nums[prev]) ? (i + 2 * k) : prev;
        }
        int max_l = k - 1, max_idx_l = k - 1, max_m = 2 * k - 1, max_sum = 0;
        for (i = max_m; i < n - k; ++i) {
            max_idx_l = (nums[i - k] > nums[max_idx_l]) ? (i - k) : max_idx_l;
            int cur_sum = nums[max_idx_l] + nums[i] + nums[max_idx_r[i - k]];
            if (cur_sum > max_sum) {
                max_sum = cur_sum;
                max_m = i;
                max_l = max_idx_l;
            }
        }
        return { max_l - k + 1, max_m - k + 1, max_idx_r[max_m - k] - k + 1 };
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestMaximumSumOf3NonOverlappingSubarrays, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int, vector<int>>>{
            {{1, 2, 1, 2, 6, 7, 5, 1}, 2, {0, 3, 5}},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.maxSumOfThreeSubarrays(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
#pragma clang diagnostic pop
