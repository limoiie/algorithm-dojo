#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an integer matrix, find the length of the longest increasing path. 
//
// From each cell, you can either move to four directions: left, right, up or do
//wn. You may NOT move diagonally or move outside of the boundary (i.e. wrap-aroun
//d is not allowed). 
//
// Example 1: 
//
// 
//Input: nums = 
//[
//  [9,9,4],
//  [6,6,8],
//  [2,1,1]
//] 
//Output: 4 
//Explanation: The longest increasing path is [1, 2, 6, 9].
// 
//
// Example 2: 
//
// 
//Input: nums = 
//[
//  [3,4,5],
//  [3,2,6],
//  [2,2,1]
//] 
//Output: 4 
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is
// not allowed.
// 
// Related Topics Depth-first Search Topological Sort Memoization


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int m = 0, n = 0;
    vector<vector<int>> dp;
    const vector<pair<int, int>> directions = {
            {1,  0},
            {-1, 0},
            {0,  1},
            {0,  -1}
    };

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix.front().size();

        dp = vector<vector<int>>(m, vector<int>(n, INT_MIN));

        auto longest = 0;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                longest = max(longest, start_cell(matrix, i, j));
            }
        }
        return longest;
    }

    int start_cell(vector<vector<int>> &matrix, int x, int y) {
        if (dp[x][y] != INT_MIN) return dp[x][y];

        auto longest = 1;
        for (const auto &dir : directions) {
            auto i = x + dir.first, j = y + dir.second;
            if (in_bound(i, j) && matrix[x][y] < matrix[i][j]) {
                start_cell(matrix, i, j);
                longest = max(longest, dp[i][j] + 1);
            }
        }
        return dp[x][y] = longest;
    }

    [[nodiscard]] bool in_bound(int const x, int const y) const {
        return 0 <= x && x < m && 0 <= y && y < n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestLongestIncreasingPathInAMatrix, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, int>>{
            {{
                     {9, 9, 4},
                     {6, 6, 8},
                     {2, 1, 1}
             }, 4},
            {{
                     {3, 4, 5},
                     {3, 2, 6},
                     {2, 2, 1}
             }, 4}
    };

    for (auto &c : cases) {
        auto result = sol.longestIncreasingPath(get<0>(c));
        auto expect = get<1>(c);
        cout << get<0>(c) << endl;
        ASSERT_EQ(result, expect);
    }

}
