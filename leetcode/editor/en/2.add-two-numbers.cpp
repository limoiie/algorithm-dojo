#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#pragma ide diagnostic ignored "cert-err58-cpp"

#include <gtest/gtest.h>
#include "base.h"

//You are given two non-empty linked lists representing two non-negative integer
//s. The digits are stored in reverse order and each of their nodes contain a sing
//le digit. Add the two numbers and return it as a linked list. 
//
// You may assume the two numbers do not contain any leading zero, except the nu
//mber 0 itself. 
//
// Example: 
//
// 
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
// 
// Related Topics Linked List Math


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto head = new ListNode(0);

        auto flag = false;
        auto tail = head;
        while (l1 != nullptr || l2 != nullptr) {
            auto lhs = 0;
            if (l1 != nullptr) {
                lhs = l1->val;
                l1 = l1->next;
            }
            auto rhs = 0;
            if (l2 != nullptr) {
                rhs = l2->val;
                l2 = l2->next;
            }
            auto const sum = lhs + rhs + (flag ? 1 : 0);
            flag = sum > 9;
            tail->next = new ListNode(flag ? sum - 10 : sum);
            tail = tail->next;
        }
        if (flag) {
            tail->next = new ListNode(1);
        }

        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestAddTwoNumbers, testcase) {
    auto sol = Solution();

    auto const cases = vector<vector<ListNode *>>{
            {
                    ListNode::create({2, 4, 3}),
                    ListNode::create({5, 6, 4}),
                    ListNode::create({7, 0, 8})
            },
    };

    for (auto & c : cases) {
        auto const result = *sol.addTwoNumbers(c[0], c[1]);
        auto const expect = *c[2];
        ASSERT_EQ(result, expect);
    }

}
