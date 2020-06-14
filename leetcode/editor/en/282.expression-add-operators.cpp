#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a string that contains only digits 0-9 and a target value, return all po
//ssibilities to add binary operators (not unary) +, -, or * between the digits so
// they evaluate to the target value. 
//
// Example 1: 
//
// 
//Input: num = "123", target = 6
//Output: ["1+2+3", "1*2*3"] 
// 
//
// Example 2: 
//
// 
//Input: num = "232", target = 8
//Output: ["2*3+2", "2+3*2"] 
//
// Example 3: 
//
// 
//Input: num = "105", target = 5
//Output: ["1*0+5","10-5"] 
//
// Example 4: 
//
// 
//Input: num = "00", target = 0
//Output: ["0+0", "0-0", "0*0"]
// 
//
// Example 5: 
//
// 
//Input: num = "3456237490", target = 9191
//Output: []
// 
//
// 
// Constraints: 
//
// 
// 0 <= num.length <= 10 
// num only contain digits. 
// 
// Related Topics Divide and Conquer


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int target_;
public:
    vector<string> addOperators(string const &num, int target) {
        auto res = vector<string>();
        this->target_ = target;
        dfs(res, num, num.substr(0, 1), 1);
        return res;
    }

    void
    dfs(vector<string> &res, string const &num, string const &exp, int start) {
        if (start == num.size()) {
            if (eval(exp) == this->target_)
                res.push_back(exp);
            return;
        }
        dfs(res, num, exp + "+" + num.substr(start, 1), start + 1);
        dfs(res, num, exp + "-" + num.substr(start, 1), start + 1);
        dfs(res, num, exp + "*" + num.substr(start, 1), start + 1);
        if (start == 0 || num[start - 1] == '0') return;
        dfs(res, num, exp + num.substr(start, 1), start + 1);
    }

    int eval(string const &exp) {
        auto opts = stack<char>();
        auto nums = stack<int>();
        for (auto i = 0; i < exp.size(); ++i) {
            switch (auto const c = exp[i]) {
                case '+': case '-': case '*':
                    pop(opts, nums, c); opts.push(c); break;
                default:
                    size_t len;
                    nums.push(stoi(exp.substr(i), &len));
                    i += len - 1;
            }
        }
        pop(opts, nums, '+');
        return nums.top();
    }

    void pop(stack<char>& opts, stack<int>& nums, char c) {
        static auto priorities = map<char, int>{
                {'+', 1}, {'-', 1}, {'*', 2}
        };
        auto const priority = priorities[c];
        while (!opts.empty() && priorities[opts.top()] >= priority) {
            auto const rhs = nums.top(); nums.pop();
            auto const lhs = nums.top(); nums.pop();
            switch (opts.top()) {
                case '+': nums.push(lhs + rhs); break;
                case '-': nums.push(lhs - rhs); break;
                case '*': nums.push(lhs * rhs); break;
            }
            opts.pop();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestExpressionAddOperators, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, int, vector<string>>>{
            {"105", 5, {"1*0+5","10-5"}},
            {"123", 6, {"1+2+3", "1*2*3"}},
            {"232", 8, {"2+3*2", "2*3+2"}}
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.addOperators(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
