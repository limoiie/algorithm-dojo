#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//You are playing the following Bulls and Cows game with your friend: You write 
//down a number and ask your friend to guess what the number is. Each time your fr
//iend makes a guess, you provide a hint that indicates how many digits in said gu
//ess match your secret number exactly in both digit and position (called "bulls")
// and how many digits match the secret number but locate in the wrong position (c
//alled "cows"). Your friend will use successive guesses and hints to eventually d
//erive the secret number. 
//
// Write a function to return a hint according to the secret number and friend's
// guess, use A to indicate the bulls and B to indicate the cows. 
//
// Please note that both secret number and friend's guess may contain duplicate 
//digits. 
//
// Example 1: 
//
// 
//Input: secret = "1807", guess = "7810"
//
//Output: "1A3B"
//
//Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7. 
//
// Example 2: 
//
// 
//Input: secret = "1123", guess = "0111"
//
//Output: "1A1B"
//
//Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
// 
//
// Note: You may assume that the secret number and your friend's guess only cont
//ain digits, and their lengths are always equal. Related Topics Hash Table


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string getHint(string const &secret, string const &guess) {
        auto const n = secret.size();
        auto s_m = vector<int>(10, 0);
        auto g_m = vector<int>(10, 0);

        auto bulls = 0;
        for (auto i = 0; i < n; ++i) {
            auto const l = secret[i] - '0';
            auto const r = guess[i] - '0';
            if (l == r) {
                ++bulls;
            } else {
                ++s_m[l];
                ++g_m[r];
            }
        }

        auto cows = 0;
        for (auto i = 0; i < 10; ++i) {
            cows += min(s_m[i], g_m[i]);
        }

        return to_string(bulls).append("A")
                .append(to_string(cows)).append("B");
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestBullsAndCows, testcase) {
    auto sol = Solution();

    auto cases = vector<vector<string>>{
            {"1807", "7810", "1A3B"},
            {"1123", "0111", "1A1B"},
    };

    for (auto const& c : cases) {
        auto result = sol.getHint(c[0], c[1]);
        auto expect = c[2];
        ASSERT_EQ(result, expect);
    }
}
