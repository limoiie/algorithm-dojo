#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//We are playing the Guess Game. The game is as follows: 
//
// I pick a number from 1 to n. You have to guess which number I picked. 
//
// Every time you guess wrong, I'll tell you whether the number is higher or low
//er. 
//
// You call a pre-defined API guess(int num) which returns 3 possible results (-
//1, 1, or 0): 
//
// 
//-1 : My number is lower
// 1 : My number is higher
// 0 : Congrats! You got it!
// 
//
// Example : 
//
// 
// 
//Input: n = 10, pick = 6
//Output: 6
// 
// 
// Related Topics Binary Search

int guess(int num) {
    if (num > 6) return +1;
    if (num < 6) return -1;
    return 0;
}

//leetcode submit region begin(Prohibit modification and deletion)
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        auto l = 0, r = n;
        while (l <= r) {
            auto const m = (l + r) / 2;
            switch (guess(m)) {
                case -1: r = m - 1; break;
                case +1: l = m + 1; break;
                default: return m;
            }
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestGuessNumberHigherOrLower, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, int>> {
            {10, 6},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.guessNumber(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
