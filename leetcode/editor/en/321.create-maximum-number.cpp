#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given two arrays of length m and n with digits 0-9 representing two numbers. C
//reate the maximum number of length k <= m + n from digits of the two. The relati
//ve order of the digits from the same array must be preserved. Return an array of
// the k digits. 
//
// Note: You should try to optimize your time and space complexity. 
//
// Example 1: 
//
// 
//Input:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//Output:
//[9, 8, 6, 5, 3] 
//
// Example 2: 
//
// 
//Input:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//Output:
//[6, 7, 6, 0, 4] 
//
// Example 3: 
//
// 
//Input:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//Output:
//[9, 8, 9]
// Related Topics Dynamic Programming Greedy


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestCreateMaximumNumber, testcase) {
    auto sol = Solution();
    auto x = make_tuple(0, 0);
    auto cases = vector<tuple<vector<int>, vector<int>, int, vector<int>>>{
            {
                    {},
                    {},
                    0,
                    {}
            },
    };

    for (auto &c : cases) {
        auto result = sol.maxNumber(
                get<0>(c), get<1>(c), get<2>(c));
        auto expect = get<3>(c);
        ASSERT_EQ(result, expect);
    }
}
