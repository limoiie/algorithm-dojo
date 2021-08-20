#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//On an NxN chessboard, a knight starts at the r-th row and c-th column and atte
//mpts to make exactly K moves. The rows and columns are 0 indexed, so the top-lef
//t square is (0, 0), and the bottom-right square is (N-1, N-1). 
//
// A chess knight has 8 possible moves it can make, as illustrated below. Each m
//ove is two squares in a cardinal direction, then one square in an orthogonal dir
//ection. 
//
// 
//
// 
//
// 
//
// Each time the knight is to move, it chooses one of eight possible moves unifo
//rmly at random (even if the piece would go off the chessboard) and moves there. 
//
//
// The knight continues moving until it has made exactly K moves or has moved of
//f the chessboard. Return the probability that the knight remains on the board af
//ter it has stopped moving. 
//
// 
//
// Example: 
//
// 
//Input: 3, 2, 0, 0
//Output: 0.0625
//Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight o
//n the board.
//From each of those positions, there are also two moves that will keep the knig
//ht on the board.
//The total probability the knight stays on the board is 0.0625.
// 
//
// 
//
// Note: 
//
// 
// N will be between 1 and 25. 
// K will be between 0 and 100. 
// The knight always initially starts on the board. 
// 
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static constexpr pair<int, int> dirs[] = {
            {+1, +2}, {-1, +2}, {+1, -2}, {-1, -2},
            {+2, +1}, {+2, -1}, {-2, +1}, {-2, -1},
    };
public:
    double knightProbability(int N, int K, int r, int c) {
        auto fn_in_bound = [&](int const x, int const y) {
            return 0 <= x and x < N and 0 <= y and y < N;
        };

        auto m = vector<vector<double>>(N, vector<double>(N, 0));
        auto t = vector<vector<double>>(N, vector<double>(N, 0));

        m[r][c] = 1.0;
        while (K--) {
            for (auto &row : t) fill(row.begin(), row.end(), 0);
            for (auto i = 0; i < N; ++i) {
                for (auto j = 0; j < N; ++j) {
                    for (auto const &dir : dirs) {
                        auto const x = i + dir.first;
                        auto const y = j + dir.second;
                        if (fn_in_bound(x, y)) {
                            t[i][j] += m[x][y];
                        }
                    }
                    t[i][j] /= 8;
                }
            }
            m.swap(t);
        }

        auto sum = 0.0;
        for (auto const &row : m)
            for (auto const &item : row)
                sum += item;
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestKnightProbabilityInChessboard, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, int, int, int, double>>
    {
            {3,2,0,0,0.0625},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.knightProbability(get<0>(c), get<1>(c), get<2>(c), get<3>(c));
        auto expect = get<4>(c);
        ASSERT_EQ(result, expect);
    }
}
