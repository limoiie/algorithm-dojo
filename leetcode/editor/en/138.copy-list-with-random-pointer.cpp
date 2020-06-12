#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//A linked list is given such that each node contains an additional random point
//er which could point to any node in the list or null. 
//
// Return a deep copy of the list. 
//
// The Linked List is represented in the input/output as a list of n nodes. Each
// node is represented as a pair of [val, random_index] where: 
//
// 
// val: an integer representing Node.val 
// random_index: the index of the node (range from 0 to n-1) where random pointe
//r points to, or null if it does not point to any node. 
// 
//
// 
// Example 1: 
//
// 
//Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 
//
// Example 2: 
//
// 
//Input: head = [[1,1],[2,1]]
//Output: [[1,1],[2,1]]
// 
//
// Example 3: 
//
// 
//
// 
//Input: head = [[3,null],[3,0],[3,null]]
//Output: [[3,null],[3,0],[3,null]]
// 
//
// Example 4: 
//
// 
//Input: head = []
//Output: []
//Explanation: Given linked list is empty (null pointer), so return null.
// 
//
// 
// Constraints: 
//
// 
// -10000 <= Node.val <= 10000 
// Node.random is null or pointing to a node in the linked list. 
// Number of Nodes will not exceed 1000. 
// 
// Related Topics Hash Table Linked List

class Node {
public:
    int val;
    Node* next;
    Node* random;

    explicit Node(int _val)
            : val(_val)
            , next(nullptr)
            , random(nullptr) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto m = map<Node*, Node*>();
        m[nullptr] = nullptr;
        auto new_head = copy_list(head, m);
        fix_random(new_head, m);
        return new_head;
    }

    Node* copy_list(Node* node, map<Node*, Node*>& m) {
        if (node == nullptr) return node;
        auto const new_node = new Node(node->val);
        new_node->next = copy_list(node->next, m);
        new_node->random = node->random;
        return m[node] = new_node;
    }

    void fix_random(Node* node, map<Node*, Node*>& m) {
        if (node == nullptr) return;
        node->random = m[node->random];
        fix_random(node->next, m);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestCopyListWithRandomPointer, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<Node*, Node*>>{
            {},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.copyRandomList(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
