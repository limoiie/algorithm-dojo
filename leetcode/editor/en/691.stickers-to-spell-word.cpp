#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//
//We are given N different types of stickers. Each sticker has a lowercase Engli
//sh word on it.
// 
//You would like to spell out the given target string by cutting individual lett
//ers from your collection of stickers and rearranging them.
// 
//You can use each sticker more than once if you want, and you have infinite qua
//ntities of each sticker.
// 
//What is the minimum number of stickers that you need to spell out the target? 
//If the task is impossible, return -1.
// 
//
// Example 1: 
// Input: 
//["with", "example", "science"], "thehat"
// 
//
// Output: 
//3
// 
//
// Explanation: 
//We can use 2 "with" stickers, and 1 "example" sticker.
//After cutting and rearrange the letters of those stickers, we can form the tar
//get "thehat".
//Also, this is the minimum number of stickers necessary to form the target stri
//ng.
// 
//
// Example 2: 
// Input: 
//["notice", "possible"], "basicbasic"
// 
//
// Output: 
//-1
// 
//
// Explanation: 
//We can't form the target "basicbasic" from cutting letters from the given stic
//kers.
// 
//
// Note:
// stickers has length in the range [1, 50]. 
// stickers consists of lowercase English words (without apostrophes). 
// target has length in the range [1, 15], and consists of lowercase English let
//ters. 
// In all test cases, all words were chosen randomly from the 1000 most common U
//S English words, and the target was chosen as a concatenation of two random word
//s. 
// The time limit may be more challenging than usual. It is expected that a 50 s
//ticker test case can be solved within 35ms on average. 
// Related Topics Dynamic Programming Backtracking


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
#define I(c) ((c) - 'a')
public:
    int minStickers(vector<string> &stickers, string const &target) {
        auto dp = unordered_map<string, int>{{"", 0}};
        auto hists = vector<vector<int>>();
        for (auto const &sticker : stickers)
            hists.push_back(to_hist(sticker));
        return backtrack(dp, hists, target);
    }

    int backtrack(unordered_map<string, int> &dp,
                  vector<vector<int>> const &stickers, string const &target) {
        if (dp.count(target)) return dp[target];

        auto cnt = INT_MAX;
        auto target_ = to_hist(target);
        for (const auto &sticker : stickers) {
            // the sticker that provide the first byte of target is preferred first
            if (sticker[target[0] - 'a'] == 0) continue;
            auto remain_ = string();
            for (auto i = 0; i < target_.size(); ++i) {
                if (target_[i] - sticker[i] > 0) {
                    remain_.append(target_[i] - sticker[i], i + 'a');
                }
            }
            auto const cnt_ = backtrack(dp, stickers, remain_);
            cnt = min(cnt, cnt_ == -1 ? cnt : cnt_ + 1);
        }
        return dp[target] = (cnt == INT_MAX ? -1 : cnt);
    }

    vector<int> to_hist(string const &sticker) {
        auto hist = vector<int>(26, 0);
        for (auto const c : sticker) ++hist[I(c)];
        return hist;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestStickersToSpellWord, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<string>, string, int>>{
            {{"with",   "example", "science"},                                                       "thehat",      3},
            {{"with",   "example", "science"},                                                       "thehats",     4},
            {{"notice", "possible"},                                                                 "basicbasic",  -1},
            {{"swim",   "love",    "father", "shape", "rich", "multiply", "new", "fill", "history"}, "operateform", 4}
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.minStickers(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
