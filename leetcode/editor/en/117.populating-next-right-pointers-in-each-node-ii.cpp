#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a binary tree 
//
// 
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
// 
//
// Populate each next pointer to point to its next right node. If there is no ne
//xt right node, the next pointer should be set to NULL. 
//
// Initially, all next pointers are set to NULL. 
//
// 
//
// Follow up: 
//
// 
// You may only use constant extra space. 
// Recursive approach is fine, you may assume implicit stack space does not coun
//t as extra space for this problem. 
// 
//
// 
// Example 1: 
//
// 
//
// 
//Input: root = [1,2,3,4,5,null,7]
//Output: [1,#,2,3,#,4,5,7,#]
//Explanation: Given the above binary tree (Figure A), your function should popu
//late each next pointer to point to its next right node, just like in Figure B. T
//he serialized output is in level order as connected by the next pointers, with '
//#' signifying the end of each level.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the given tree is less than 6000. 
// -100 <= node.val <= 100 
// 
// Related Topics Tree Depth-first Search


//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    Node* pre;

public:
    /**
     * Idea: for each level, from right to left
     */
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        auto const h = height(root);
        for (auto i = 0; i < h; ++i) {
            pre = nullptr;
            connect(root, i);
        }
        return root;
    }

    void connect(Node* root, int const level) {
        if (root) {
            if (level == 0) {
                root->next = pre;
                pre = root;
            } else {
                connect(root->right, level - 1);
                connect(root->left, level - 1);
            }
        }
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestPopulatingNextRightPointersInEachNodeII, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<Node*, Node*>>{
            {},
    };

    for (auto & c : cases) {
        auto result = sol.connect(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);

    }
}
