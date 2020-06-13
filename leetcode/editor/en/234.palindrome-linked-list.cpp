#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a singly linked list, determine if it is a palindrome. 
//
// Example 1: 
//
// 
//Input: 1->2
//Output: false 
//
// Example 2: 
//
// 
//Input: 1->2->2->1
//Output: true 
//
// Follow up: 
//Could you do it in O(n) time and O(1) space? 
// Related Topics Linked List Two Pointers


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
    bool isPalindrome(ListNode* head) {
        auto slower = head, faster = head;
        while (faster) {
            slower = slower->next;
            faster = faster->next ? faster->next->next : nullptr;
        }
        ListNode *half = nullptr, *curr = slower;
        while (curr) {
            auto next = curr->next;
            curr->next = half;
            half = curr;
            curr = next;
        }
        while (half) {
            if (head->val != half->val) return false;
            head = head->next, half = half->next;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestPalindromeLinkedList, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<ListNode*, bool>>{
            {ListNode::create({1,2}), false},
            {ListNode::create({1,2,1}), true},
            {ListNode::create({1,2,2,1}), true},
            {ListNode::create({1,2,3,2,2}), false},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.isPalindrome(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
