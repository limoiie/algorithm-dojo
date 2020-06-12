#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a non-negative index k where k ≤ 33, return the kth index row of the Pas
//cal's triangle. 
//
// Note that the row index starts from 0. 
//
// 
//In Pascal's triangle, each number is the sum of the two numbers directly above
// it. 
//
// Example: 
//
// 
//Input: 3
//Output: [1,3,3,1]
// 
//
// Follow up: 
//
// Could you optimize your algorithm to use only O(k) extra space? 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        auto l = vector<int>(rowIndex + 1, 0);
        l[0] = 1;
        for (auto i = 1; i <= rowIndex; ++i) {
            for (auto j = i; j > 0; --j) {
                l[j] += l[j-1];
            }
        }
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestPascalsTriangleII, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, vector<int>>>{
            {3, {1, 3, 3, 1}},
    };

    for (auto & c : cases) {
        auto result = sol.getRow(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}

