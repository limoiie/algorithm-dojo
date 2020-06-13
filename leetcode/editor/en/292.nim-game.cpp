#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//You are playing the following Nim Game with your friend: There is a heap of st
//ones on the table, each time one of you take turns to remove 1 to 3 stones. The 
//one who removes the last stone will be the winner. You will take the first turn 
//to remove the stones. 
//
// Both of you are very clever and have optimal strategies for the game. Write a
// function to determine whether you can win the game given the number of stones i
//n the heap. 
//
// Example: 
//
// 
//Input: 4
//Output: false 
//Explanation: If there are 4 stones in the heap, then you will never win the ga
//me;
//             No matter 1, 2, or 3 stones you remove, the last stone will alway
//s be 
//             removed by your friend. Related Topics Brainteaser Minimax


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestNimGame, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, bool>>{
            {4, false},
            {10, true},
            {22, true},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.canWinNim(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
