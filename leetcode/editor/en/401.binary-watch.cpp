#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//A binary watch has 4 LEDs on the top which represent the hours (0-11), and the
// 6 LEDs on the bottom represent the minutes (0-59). 
// Each LED represents a zero or one, with the least significant bit on the righ
//t. 
//
// For example, the above binary watch reads "3:25". 
//
// Given a non-negative integer n which represents the number of LEDs that are c
//urrently on, return all possible times the watch could represent. 
//
// Example:
// Input: n = 1 Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
// "0:08", "0:16", "0:32"] 
// 
//
// Note: 
// 
// The order of output does not matter. 
// The hour must not contain a leading zero, for example "01:00" is not valid, i
//t should be "1:00". 
// The minute must be consist of two digits and may contain a leading zero, for 
//example "10:2" is not valid, it should be "10:02". 
// 
// Related Topics Backtracking Bit Manipulation 
// 👍 578 👎 987


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        auto binaries = vector<unsigned>();
        enumerate(binaries, 0, num, 0);

        auto res = vector<string>();
        for (auto const x : binaries) {
            res.push_back(bits_to_string(x));
        }
        return res;
    }

    void enumerate(vector<unsigned> &s, unsigned pre, int const num, unsigned i) {
        if (not valid(pre)) return;
        if (num == 0) {
            s.push_back(pre);
        } else {
            while (i + num <= 10) {
                enumerate(s, pre | (1u << i), num - 1, i + 1);
                ++i;
            }
        }
    }

    string bits_to_string(unsigned const x) {
        auto const hour = x >> 6u;
        auto const minute = x & 0b111111u;
        return to_string(hour) + ":" + remain_two_bits(minute);
    }

    string remain_two_bits(unsigned const x) {
        return x < 10 ? ("0" + to_string(x)) : to_string(x);
    }

    bool valid(unsigned const x) const {
        return (x >> 6u) < 12 and (x & 0b111111u) < 60;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestBinaryWatch, testcase) {
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
