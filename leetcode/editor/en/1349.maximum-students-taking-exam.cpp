#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a m * n matrix seats that represent seats distributions in a classroom. 
//If a seat is broken, it is denoted by '#' character otherwise it is denoted by a
// '.' character. 
//
// Students can see the answers of those sitting next to the left, right, upper 
//left and upper right, but he cannot see the answers of the student sitting direc
//tly in front or behind him. Return the maximum number of students that can take 
//the exam together without any cheating being possible.. 
//
// Students must be placed in seats in good condition. 
//
// 
// Example 1: 
//
// 
//Input: seats = [["#",".","#","#",".","#"],
//                [".","#","#","#","#","."],
//                ["#",".","#","#",".","#"]]
//Output: 4
//Explanation: Teacher can place 4 students in available seats so they don't che
//at on the exam. 
// 
//
// Example 2: 
//
// 
//Input: seats = [[".","#"],
//                ["#","#"],
//                ["#","."],
//                ["#","#"],
//                [".","#"]]
//Output: 3
//Explanation: Place all students in available seats. 
//
// 
//
// Example 3: 
//
// 
//Input: seats = [["#",".",".",".","#"],
//                [".","#",".","#","."],
//                [".",".","#",".","."],
//                [".","#",".","#","."],
//                ["#",".",".",".","#"]]
//Output: 10
//Explanation: Place students in available seats in column 1, 3 and 5.
// 
//
// 
// Constraints: 
//
// 
// seats contains only characters '.' and'#'. 
// m == seats.length 
// n == seats[i].length 
// 1 <= m <= 8 
// 1 <= n <= 8 
// 
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static auto constexpr n_bits = []() {
        auto x = array<int, 256>();
        for (auto i = 0; i < 256; ++i) {
            for (unsigned k = i; k; k >>= 1u) {
                x[i] += k & 1u;
            }
        }
        return x;
    }();

    static auto constexpr invalid_layout = []() {
        auto x = array<bool, 256>();
        for (auto i = 0u; i < 256u; ++i) {
            for (auto k = 1u, p = 0b11u; k < 8u and not x[i]; ++k, p <<= 1u) {
                x[i] = (i & p) == p;
            }
        }
        return x;
    }();

public:
    int maxStudents(vector<vector<char>> &seats) {
        auto const w = seats.front().size();
        auto const n = 1u << w;

        auto ans = 0;
        auto dp = vector<int>(n, 0);
        for (auto const &row : seats) {
            auto ep = vector<int>(n, 0);
            auto blocks = to_bits(row);
            for (unsigned cur = 0u; cur < n; ++cur) {
                if (invalid_layout[cur] or (blocks & cur)) continue;
                unsigned const victims = (unsigned) (cur << 1u) | (cur >> 1u);
                for (unsigned pre = 0u; pre < n; ++pre) {
                    if (victims & pre) continue;
                    ep[cur] = max(ep[cur], dp[pre] + n_bits[cur]);
                }
                ans = max(ans, ep[cur]);
            }
            dp.swap(ep);
        }
        return ans;
    }

    [[nodiscard]] unsigned to_bits(vector<char> const &row) const {
        unsigned bits = 0;
        for (auto c : row) {
            bits = (bits << 1u) + (c == '#' ? 1 : 0);
        }
        return bits;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestMaximumStudentsTakingExam, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<char>>, int>>{
            {{
                     {'#', '.', '.', '.', '#'},
                     {'.', '#', '.', '#', '.'},
                     {'.', '.', '#', '.', '.'},
                     {'.', '#', '.', '#', '.'},
                     {'#', '.', '.', '.', '#'}
             }, 10
            },
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.maxStudents(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
