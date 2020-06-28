#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//In MATLAB, there is a very useful function called 'reshape', which can reshape
// a matrix into a new one with different size but keep its original data.
// 
//
// 
//You're given a matrix represented by a two-dimensional array, and two positive
// integers r and c representing the row number and column number of the wanted re
//shaped matrix, respectively. 
//
// The reshaped matrix need to be filled with all the elements of the original m
//atrix in the same row-traversing order as they were.
// 
//
// 
//If the 'reshape' operation with given parameters is possible and legal, output
// the new reshaped matrix; Otherwise, output the original matrix.
// 
//
// Example 1: 
// 
//Input: 
//nums = 
//[[1,2],
// [3,4]]
//r = 1, c = 4
//Output: 
//[[1,2,3,4]]
//Explanation: The row-traversing of nums is [1,2,3,4]. The new reshaped matrix 
//is a 1 * 4 matrix, fill it row by row by using the previous list.
// 
// 
//
// Example 2: 
// 
//Input: 
//nums = 
//[[1,2],
// [3,4]]
//r = 2, c = 4
//Output: 
//[[1,2],
// [3,4]]
//Explanation: There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So o
//utput the original matrix.
// 
// 
//
// Note: 
// 
// The height and width of the given matrix is in range [1, 100]. 
// The given r and c are all positive. 
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        if (r * c != nums.size() * nums.front().size()) return nums;
        auto reshaped = vector<vector<int>>(r, vector<int>(c, 0));
        auto i = 0, j = 0;
        for (auto const& row : nums) {
            for (auto const& num : row) {
                reshaped[i][j] = num;
                if (++j == c) {
                    ++i, j = 0;
                }
            }
        }
        return reshaped;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestReshapeTheMatrix, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, int, int, vector<vector<int>>>> {
            {{{1,2}, {3,4}}, 1, 4, {{1,2,3,4}}},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.matrixReshape(get<0>(c), get<1>(c), get<2>(c));
        auto expect = get<3>(c);
        ASSERT_EQ(result, expect);
    }
}
