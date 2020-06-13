#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Write an efficient algorithm that searches for a value in an m x n matrix. Thi
//s matrix has the following properties: 
//
// 
// Integers in each row are sorted in ascending from left to right. 
// Integers in each column are sorted in ascending from top to bottom. 
// 
//
// Example: 
//
// Consider the following matrix: 
//
// 
//[
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
// 
//
// Given target = 5, return true. 
//
// Given target = 20, return false. 
// Related Topics Binary Search Divide and Conquer


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        auto const m = (int) matrix.size();
        auto const n = (int) matrix.front().size();

        auto i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (target > matrix[i][j]) ++i;
            else if (target < matrix[i][j]) --j;
            else return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestSearchA2DMatrixII, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, int, bool>>{
            {{
                     {1, 4, 7, 11, 15},
                     {2, 5, 8, 12, 19},
                     {3, 6, 9, 16, 22},
                     {10, 13, 14, 17, 24},
                     {18, 21, 23, 26, 30}
             }, 5, true},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.searchMatrix(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
