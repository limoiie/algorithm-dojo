#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an 2D board, count how many battleships are in it. The battleships are r
//epresented with 'X's, empty slots are represented with '.'s. You may assume the 
//following rules:
//
// 
// You receive a valid board, made of only battleships or empty slots. 
// Battleships can only be placed horizontally or vertically. In other words, th
//ey can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column
//), where N can be of any size. 
// At least one horizontal or vertical cell separates between two battleships - 
//there are no adjacent battleships. 
// 
//
// Example: 
// X..X
//...X
//...X
// 
//In the above board there are 2 battleships.
//
// Invalid Example: 
// ...X
//XXXX
//...X
// 
//This is an invalid board that you will not receive - as battleships will alway
//s have a cell separating between them.
// 
// Follow up: Could you do it in one-pass, using only O(1) extra memory and with
//out modifying the value of the board? 👍 751 👎 506


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        auto res = 0;
        auto const n = board.front().size();
        auto above = vector<bool>(n, false);
        for (auto const& row : board) {
            auto prev = false;
            for (auto i = 0; i < n; ++i) {
                if (row[i] == 'X') {
                    if (not prev and not above[i]) {
                        ++res;
                    }
                    prev = above[i] = true;
                } else {
                    prev = above[i] = false;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestBattleshipsInABoard, testcase) {
//     auto sol = Solution();
// 
//     auto cases = vector<tuple<..>>{
//             {},
//     };
// 
//     for (auto & c : cases) {
//         cout << "testing " << c << "..." << endl;
//         auto result = sol.foo(get<0>(c));
//         auto expect = get<1>(c);
//         ASSERT_EQ(result, expect);
//     }
// }
