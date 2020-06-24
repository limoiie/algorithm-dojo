#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//In a N x N grid representing a field of cherries, each cell is one of three po
//ssible integers. 
//
// 
//
// 
// 0 means the cell is empty, so you can pass through; 
// 1 means the cell contains a cherry, that you can pick up and pass through; 
// -1 means the cell contains a thorn that blocks your way. 
// 
//
// 
//
// Your task is to collect maximum number of cherries possible by following the 
//rules below: 
//
// 
//
// 
// Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or do
//wn through valid path cells (cells with value 0 or 1); 
// After reaching (N-1, N-1), returning to (0, 0) by moving left or up through v
//alid path cells; 
// When passing through a path cell containing a cherry, you pick it up and the 
//cell becomes an empty cell (0); 
// If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can
// be collected. 
// 
//
// 
//
// 
//
// Example 1: 
//
// 
//Input: grid =
//[[0, 1, -1],
// [1, 0, -1],
// [1, 1,  1]]
//Output: 5
//Explanation: 
//The player started at (0, 0) and went down, down, right right to reach (2, 2).
//
//4 cherries were picked up during this single trip, and the matrix becomes [[0,
//1,-1],[0,0,-1],[0,0,0]].
//Then, the player went left, up, up, left to return home, picking up one more c
//herry.
//The total number of cherries picked up is 5, and this is the maximum possible.
//
// 
//
// 
//
// Note: 
//
// 
// grid is an N by N 2D array, with 1 <= N <= 50. 
// Each grid[i][j] is an integer in the set {-1, 0, 1}. 
// It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1. 
// 
// 
// 
// 
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        auto const n = static_cast<int>(grid.size());
        auto dp = vector<vector<vector<int>>>(n,
                vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return depth_first(dp, grid, 0, 0, 0, n);
    }

    int depth_first(vector<vector<vector<int>>> &dp, vector<vector<int>>& grid,
                    int x1, int y1, int x2, int n) {
        auto const y2 = x1 + y1 - x2;
        if (x1 == n or y1 == n or x2 == n or y2 == n) return INT_MIN;
        if (grid[x1][y1] == -1 or grid[x2][y2] == -1) return INT_MIN;
        if (dp[x1][y1][x2] != INT_MIN) return dp[x1][y1][x2];
        if (x1 == n - 1 and y1 == n - 1) return grid[x1][y1];
        return dp[x1][y1][x2] = grid[x1][y1] + (x1 == x2 ? 0 : grid[x2][y2]) + max({
                    depth_first(dp, grid, x1 + 1, y1, x2, n),
                    depth_first(dp, grid, x1, y1 + 1, x2, n),
                    depth_first(dp, grid, x1 + 1, y1, x2 + 1, n),
                    depth_first(dp, grid, x1, y1 + 1, x2 + 1, n),
                });
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestCherryPickup, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, int>>{
            {},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.cherryPickup(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
