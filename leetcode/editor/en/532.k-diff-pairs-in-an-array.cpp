#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//Given an array of integers and an integer k, you need to find the number of un
//ique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair
// (i, j), where i and j are both numbers in the array and their absolute differen
//ce is k.
// 
//
//
// Example 1: 
// 
//Input: [3, 1, 4, 1, 5], k = 2
//Output: 2
//Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5). Altho
//ugh we have two 1s in the input, we should only return the number of unique pair
//s.
// 
// 
//
// Example 2: 
// 
//Input:[1, 2, 3, 4, 5], k = 1
//Output: 4
//Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) 
//and (4, 5).
// 
// 
//
// Example 3: 
// 
//Input: [1, 3, 1, 5, 4], k = 0
//Output: 1
//Explanation: There is one 0-diff pair in the array, (1, 1).
// 
// 
//
// Note: 
// 
// The pairs (i, j) and (j, i) count as the same pair. 
// The length of the array won't exceed 10,000. 
// All the integers in the given input belong to the range: [-1e7, 1e7]. 
// 
// Related Topics Array Two Pointers


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto count = 0, lower = 0, upper = 0;
        while (upper < nums.size()) {
            if (lower < upper) {
                auto const diff = nums[upper] - nums[lower];
                if (diff > k) {
                    ++lower;
                } else if (diff < k) {
                    ++upper;
                } else {
                    ++count;
                    auto const curr = nums[lower];
                    while (lower < nums.size() and nums[lower] == curr) {
                        ++lower;
                    }
                }
            } else {
                ++upper;
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestKDiffPairsInAnArray, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int, int>>{
            {{1,2,3,4,5}, 1, 4},
            {{3,1,4,1,5}, 2, 2},
            {{1,3,1,5,4}, 0, 1},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findPairs(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
