#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include "base.h"
//Given a nested list of integers represented as a string, implement a parser to
// deserialize it. 
//
// Each element is either an integer, or a list -- whose elements may also be in
//tegers or other lists. 
//
// Note: You may assume that the string is well-formed: 
//
// 
// String is non-empty. 
// String does not contain white spaces. 
// String contains only digits 0-9, [, - ,, ]. 
// 
//
// 
//
// Example 1: 
//
// 
//Given s = "324",
//
//You should return a NestedInteger object which contains a single integer 324.
// 
//
// 
//
// Example 2: 
//
// 
//Given s = "[123,[456,[789]]]",
//
//Return a NestedInteger object containing a nested list with 2 elements:
//
//1. An integer containing value 123.
//2. A nested list containing two elements:
//    i.  An integer containing value 456.
//    ii. A nested list with one element:
//         a. An integer containing value 789.
// 
//
// 
// Related Topics String Stack 
// 👍 244 👎 828

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string const &s) {
        if (s[0] != '[') {
            return NestedInteger(atoi(s.c_str()));
        }

        auto root = NestedInteger();
        auto stk = stack<NestedInteger *>();
        stk.push(&root);

        auto sign = true;
        auto numbering = false;
        auto number = 0;
        for (auto c : s) {
            switch (c) {
                case '[': {
                    stk.top()->add(NestedInteger());
                    stk.push(const_cast<NestedInteger *>(&stk.top()->getList().back()));
                }
                    sign = true;
                    numbering = false;
                    number = 0;
                    break;
                case ']':
                case ',':
                    if (numbering) {
                        stk.top()->add(NestedInteger(sign ? number : - number));
                    }
                    if (c == ']') stk.pop();
                    sign = true;
                    numbering = false;
                    number = 0;
                    break;
                case ' ': continue;
                case '-': sign = false; break;
                default:
                    numbering = true;
                    number = number * 10 + (c - '0');
            }
        }
        return root.getList().front();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

#pragma clang diagnostic pop