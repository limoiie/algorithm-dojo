#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//A zero-indexed array A of length N contains all integers from 0 to N-1. Find a
//nd return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], 
//... } subjected to the rule below. 
//
// Suppose the first element in S starts with the selection of element A[i] of i
//ndex = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that 
//analogy, we stop adding right before a duplicate element occurs in S. 
//
// 
//
// Example 1: 
//
// 
//Input: A = [5,4,0,3,1,6,2]
//Output: 4
//Explanation: 
//A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
//
//One of the longest S[K]:
//S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
// 
//
// 
//
// Note: 
//
// 
// N is an integer within the range [1, 20,000]. 
// The elements of A are all distinct. 
// Each element of A is an integer within the range [0, N-1]. 
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        auto ans = 0;
        auto dp = vector<int>(nums.size(), -1);
        for (auto num : nums) {
            auto count = 0;
            while (dp[num] == -1) {
                dp[num] = max(dp[num], ++count);
                num = nums[num];
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestArrayNesting, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{5,4,0,3,1,6,2}, 4},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.arrayNesting(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
