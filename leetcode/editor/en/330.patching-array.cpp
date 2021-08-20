#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a sorted positive integer array nums and an integer n, add/patch element
//s to the array such that any number in range [1, n] inclusive can be formed by t
//he sum of some elements in the array. Return the minimum number of patches requi
//red. 
//
// Example 1: 
//
// 
//Input: nums = [1,3], n = 6
//Output: 1 
//Explanation:
//Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4
//.
//Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,
//3], [1,2,3].
//Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
//So we only need 1 patch. 
//
// Example 2: 
//
// 
//Input: nums = [1,5,10], n = 20
//Output: 2
//Explanation: The two patches can be [2, 4].
// 
//
// Example 3: 
//
// 
//Input: nums = [1,2,2], n = 5
//Output: 0
// Related Topics Greedy


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        auto cnt = 0, i = 0;
        for (long long missing = 1, sum = 0; missing <= n; missing = sum + 1) {
            if (i < nums.size() && nums[i] <= missing) {
                sum += nums[i++];
            } else {
                sum += missing;
                cnt++;
            }
        }
        return cnt;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestPatchingArray, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int, int>>{
            {{1, 3},     6,  1},
            {{1, 5, 10}, 20, 2},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.minPatches(get<0>(c), get<1>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
