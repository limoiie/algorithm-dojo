#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a string of numbers and operators, return all possible results from comp
//uting all the different possible ways to group numbers and operators. The valid 
//operators are +, - and *. 
//
// Example 1: 
//
// 
//Input: "2-1-1"
//Output: [0, 2]
//Explanation: 
//((2-1)-1) = 0 
//(2-(1-1)) = 2 
//
// Example 2: 
//
// 
//Input: "2*3-4*5"
//Output: [-34, -14, -10, -10, 10]
//Explanation: 
//(2*(3-(4*5))) = -34 
//((2*3)-(4*5)) = -14 
//((2*(3-4))*5) = -10 
//(2*((3-4)*5)) = -10 
//(((2*3)-4)*5) = 10
// Related Topics Divide and Conquer


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> diffWaysToCompute(string const& input) {
        auto res = vector<int>();
        auto contains_operator = false;
        for (auto i = 0; i < input.size(); ++i) {
            switch (input[i]) {
                case '+': case '-': case '*':
                    contains_operator = true;
                    auto const l = diffWaysToCompute(input.substr(0, i));
                    auto const r = diffWaysToCompute(input.substr(i+1, -1));
                    for (auto lv : l) {
                        for (auto rv : r) {
                            res.push_back(compute(lv, rv, input[i]));
                        }
                    }
            }
        }
        if (!contains_operator) {
            res.push_back(stoi(input));
        }
        return res;
    }

    int compute(int lhs, int rhs, char opt) {
        switch (opt) {
            case '-': return lhs - rhs;
            case '+': return lhs + rhs;
            case '*': return lhs * rhs;
            default: return INT_MIN;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestDifferentWaysToAddParentheses, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, vector<int>>>{
            {"2*3-4*5", {-34, -14, -10, -10, 10}},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.diffWaysToCompute(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
