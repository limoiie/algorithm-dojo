#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a non-empty array of integers, return the third maximum number in this a
//rray. If it does not exist, return the maximum number. The time complexity must 
//be in O(n). 
//
// Example 1: 
// 
//Input: [3, 2, 1]
//
//Output: 1
//
//Explanation: The third maximum is 1.
// 
// 
//
// Example 2: 
// 
//Input: [1, 2]
//
//Output: 2
//
//Explanation: The third maximum does not exist, so the maximum (2) is returned 
//instead.
// 
// 
//
// Example 3: 
// 
//Input: [2, 2, 3, 1]
//
//Output: 1
//
//Explanation: Note that the third maximum here means the third maximum distinct
// number.
//Both numbers with value 2 are both considered as second maximum.
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int thirdMax(vector<int> &nums) {
        auto top = vector<int>{nums.front()};
        for (auto const num : nums) {
            auto i = 0;
            for (; i < top.size(); ++i) {
                if (num == top[i]) break;
                if (num > top[i]) {
                    if (top.size() < 3) {
                        top.push_back(0);
                    }
                    for (auto j = top.size() - 1; j > i; --j) {
                        top[j] = top[j - 1];
                    }
                    top[i] = num;
                    break;
                }
            }
            if (i == top.size()) {
                if (top.size() < 3) {
                    top.push_back(num);
                }
            }
        }
        return top.size() < 3 ? top[0] : top[2];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestThirdMaximumNumber, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{3, 2, 1},     1},
            {{1, 2},        2},
            {{2, 2, 3, 1,}, 1},
    };
    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.thirdMax(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
