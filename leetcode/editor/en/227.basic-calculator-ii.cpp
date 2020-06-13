#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Implement a basic calculator to evaluate a simple expression string. 
//
// The expression string contains only non-negative integers, +, -, *, / operato
//rs and empty spaces . The integer division should truncate toward zero. 
//
// Example 1: 
//
// 
//Input: "3+2*2"
//Output: 7
// 
//
// Example 2: 
//
// 
//Input: " 3/2 "
//Output: 1 
//
// Example 3: 
//
// 
//Input: " 3+5 / 2 "
//Output: 5
// 
//
// Note: 
//
// 
// You may assume that the given expression is always valid. 
// Do not use the eval built-in library function. 
// 
// Related Topics String


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    map<char, int> priority;

public:
    Solution() : priority() {
        priority['('] = 0; priority[')'] = 0;
        priority['+'] = 1; priority['-'] = 1;
        priority['*'] = 2; priority['/'] = 2;
    }

    int calculate(string const& s) {
        auto num_stack = stack<int>();
        auto opt_stack = stack<char>();
        for (auto i = 0; i < s.size(); ++i) {
            switch (auto const c = s[i]) {
                case ' ': break;
                case '+': case '-': case '*': case '/':
                    eval(opt_stack, num_stack, c);
                case '(':
                    opt_stack.push(c);
                    break;
                case ')':
                    eval(opt_stack, num_stack, c);
                    opt_stack.pop();
                    break;
                case '0'...'9':
                    num_stack.push(number(s, i));
                    break;
                default:
                    throw runtime_error("Unexpected character!");
            }
        }
        eval(opt_stack, num_stack, '(');
        return num_stack.top();
    }

    int number(string const& s, int& curr) {
        auto const begin = curr;
        while (curr+1 < s.size() && isdigit(s[curr+1])) { ++curr; }
        return stoi(s.substr(begin, curr-begin+1));
    }

    void eval(stack<char>& opt_stack, stack<int>& num_stack, char const until) {
        while (!opt_stack.empty()) {
            if (priority[opt_stack.top()] < priority[until]) break;
            auto const opt = opt_stack.top(); opt_stack.pop();
            auto const second = num_stack.top(); num_stack.pop();
            auto const first = num_stack.top(); num_stack.pop();
            switch (opt) {
                case '+': num_stack.push(first + second); break;
                case '-': num_stack.push(first - second); break;
                case '*': num_stack.push(first * second); break;
                case '/': num_stack.push(first / second); break;
                default: throw std::runtime_error("Unsupported operator!!");
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestBasicCalculatorII, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, int>>{
            {"1 + 1", 2},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.calculate(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
