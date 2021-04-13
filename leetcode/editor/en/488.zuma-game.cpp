#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Think about Zuma Game. You have a row of balls on the table, colored red(R), y
//ellow(Y), blue(B), green(G), and white(W). You also have several balls in your h
//and. 
//
// Each time, you may choose a ball in your hand, and insert it into the row (in
//cluding the leftmost place and rightmost place). Then, if there is a group of 3 
//or more balls in the same color touching, remove these balls. Keep doing this un
//til no more balls can be removed. 
//
// Find the minimal balls you have to insert to remove all the balls on the tabl
//e. If you cannot remove all the balls, output -1. 
//
// 
// Example 1: 
//
// 
//Input: board = "WRRBBW", hand = "RB"
//Output: -1
//Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW
// 
//
// Example 2: 
//
// 
//Input: board = "WWRRBBWW", hand = "WRBRW"
//Output: 2
//Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty
// 
//
// Example 3: 
//
// 
//Input: board = "G", hand = "GGGGG"
//Output: 2
//Explanation: G -> G[G] -> GG[G] -> empty 
// 
//
// Example 4: 
//
// 
//Input: board = "RBYYBBRRB", hand = "YRBGB"
//Output: 3
//Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B
//] -> empty 
// 
//
// 
// Constraints: 
//
// 
// You may assume that the initial row of balls on the table won’t have any 3 or
// more consecutive balls with the same color. 
// 1 <= board.length <= 16 
// 1 <= hand.length <= 5 
// Both input strings will be non-empty and only contain characters 'R','Y','B',
//'G','W'. 
// 
// Related Topics Depth-first Search 
// 👍 278 👎 302


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMinStep(string const& board, string const& hand) {
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestZumaGame, testcase) {
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
