#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//We are playing the Guess Game. The game is as follows: 
//
// I pick a number from 1 to n. You have to guess which number I picked. 
//
// Every time you guess wrong, I'll tell you whether the number I picked is high
//er or lower. 
//
// However, when you guess a particular number x, and you guess wrong, you pay $
//x. You win the game when you guess the number I picked. 
//
// Example: 
//
// 
//n = 10, I pick 8.
//
//First round:  You guess 5, I tell you that it's higher. You pay $5.
//Second round: You guess 7, I tell you that it's higher. You pay $7.
//Third round:  You guess 9, I tell you that it's lower. You pay $9.
//
//Game over. 8 is the number I picked.
//
//You end up paying $5 + $7 + $9 = $21.
// 
//
// Given a particular n ≥ 1, find out how much money you need to have to guarant
//ee a win. Related Topics Dynamic Programming Minimax


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getMoneyAmount(int n) {
        auto dp = vector<vector<int>>(n+1, vector<int>(n+1, INT_MAX));
        for (auto i = n; i > 0; --i) dp[i][i] = 0;
        for (auto i = n; i > 0; --i) {
            for (auto j = i + 1; j <= n; ++j) {
                for (auto k = i; k <= j; ++k) {
                    auto x = INT_MIN;
                    if (k != i) x = max(x, dp[i][k-1]);
                    if (k != j) x = max(x, dp[k+1][j]);
                    dp[i][j] = min(dp[i][j], k + x);
                }
            }
        }
        return dp[1][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestGuessNumberHigherOrLowerII, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, int>>{
            {10, 16},
            {2, 1},
            {3, 2},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.getMoneyAmount(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
