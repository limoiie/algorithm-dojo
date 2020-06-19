#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

//#include <gtest/gtest.h>
#include "base.h"

//Given a list of non-negative numbers and a target integer k, write a function 
//to check if the array has a continuous subarray of size at least 2 that sums up 
//to a multiple of k, that is, sums up to n*k where n is also an integer. 
//
// 
//
// Example 1: 
//
// 
//Input: [23, 2, 4, 6, 7],  k=6
//Output: True
//Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 
//6.
// 
//
// Example 2: 
//
// 
//Input: [23, 2, 6, 4, 7],  k=6
//Output: True
//Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and 
//sums up to 42.
// 
//
// 
// Constraints: 
//
// 
// The length of the array won't exceed 10,000. 
// You may assume the sum of all the numbers is in the range of a signed 32-bit 
//integer. 
// 
// Related Topics Math Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        auto sum = 0;
        auto dp = unordered_map<int, int>{{0, -1}};
        for (auto i = 0; i != nums.size(); ++i) {
            sum += nums[i];
            sum = k == 0 ? sum : sum % k;
            dp[sum] = dp.find(sum) == dp.end() ? i : dp[sum];
            if (i - dp[sum] > 1) {
                return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

//
//TEST(TestLowestCommonAncestorOfABinarySearchTree, testcase) {
//    auto sol = Solution();
//
//    auto cases = vector<tuple<TreeNode*, TreeNode*, TreeNode*, TreeNode*>>{
//            {},
//    };
//
//    for (auto & c : cases) {
//        cout << "testing " << c << "..." << endl;
//        auto result = sol.lowestCommonAncestor(get<0>(c), get<1>(c), get<2>(c));
//        auto expect = get<3>(c);
//        ASSERT_EQ(result, expect);
//    }
//}
