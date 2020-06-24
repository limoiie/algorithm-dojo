#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//There is an m by n grid with a ball. Given the start coordinate (i,j) of the b
//all, you can move the ball to adjacent cell or cross the grid boundary in four d
//irections (up, down, left, right). However, you can at most move N times. Find o
//ut the number of paths to move the ball out of grid boundary. The answer may be 
//very large, return it after mod 109 + 7. 
//
// 
//
// Example 1: 
//
// 
//Input: m = 2, n = 2, N = 2, i = 0, j = 0
//Output: 6
//Explanation:
//
// 
//
// Example 2: 
//
// 
//Input: m = 1, n = 3, N = 3, i = 0, j = 1
//Output: 12
//Explanation:
//
// 
//
// 
//
// Note: 
//
// 
// Once you move the ball out of boundary, you cannot move it back. 
// The length and height of the grid is in range [1,50]. 
// N is in range [0,50]. 
// 
// Related Topics Dynamic Programming Depth-first Search


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static long long unsigned constexpr mask = 1e9 + 7;
public:
    int findPaths(int m, int n, int N, int x, int y) {
        auto dp1 = vector<vector<int>>(m, vector<int>(n, 0));
        auto dp2 = vector<vector<int>>(m, vector<int>(n, 0));

        while (N--) {
            for (auto i = 0; i < m; ++i) {
                for (auto j = 0; j < n; ++j) {
                    dp2[i][j] = ((i == 0 ? 1 : dp1[i - 1][j]) +
                                 (i == m - 1 ? 1 : dp1[i + 1][j]) +
                                 (j == 0 ? 1 : dp1[i][j - 1]) +
                                 (j == n - 1 ? 1 : dp1[i][j + 1])) % mask;
                }
            }
            dp1.swap(dp2);
        }
        return dp1[x][y];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestOutOfBoundaryPaths, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, int, int, int, int, int>>{
            {2, 2, 2, 0, 0, 6},
            {1, 3, 3, 0, 1, 12},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findPaths(
                get<0>(c), get<1>(c), get<2>(c),
                get<3>(c), get<4>(c)
        );
        auto expect = get<5>(c);
        ASSERT_EQ(result, expect);
    }
}
