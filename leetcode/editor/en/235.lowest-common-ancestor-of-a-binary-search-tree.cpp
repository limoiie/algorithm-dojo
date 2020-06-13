#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a binary search tree (BST), find the lowest common ancestor (LCA) of two
// given nodes in the BST. 
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor 
//is defined between two nodes p_ and q_ as the lowest node in T that has both p_ and
// q_ as descendants (where we allow a node to be a descendant of itself).”
//
// Given binary search tree: root = [6,2,8,0,4,7,9,null,null,3,5] 
//
// 
//
// Example 1: 
//
// 
//Input: root = [6,2,8,0,4,7,9,null,null,3,5], p_ = 2, q_ = 8
//Output: 6
//Explanation: The LCA of nodes 2 and 8 is 6.
// 
//
// Example 2: 
//
// 
//Input: root = [6,2,8,0,4,7,9,null,null,3,5], p_ = 2, q_ = 4
//Output: 2
//Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant o
//f itself according to the LCA definition.
// 
//
// 
//
// Note: 
//
// 
// All of the nodes' values will be unique. 
// p_ and q_ are different and both values will exist in the BST.
// 
// Related Topics Tree


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* parent;
    TreeNode* p_;
    TreeNode* q_;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p_, TreeNode* q_) {
        parent = nullptr, this->p_ = p_, this->q_ = q_;
        contains_any(root);
        return parent;
    }

    bool contains_any(TreeNode* root) {
        if (root == nullptr) return false;
        if (parent != nullptr) return false;
        auto const m = root == p_ || root == q_;
        auto const l = contains_any(root->left);
        auto const r = contains_any(root->right);
        if (parent == nullptr) {
            if ((l && r) || m && (l || r)) {
                parent = root;
            }
        }
        return m || l || r;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestLowestCommonAncestorOfABinarySearchTree, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<TreeNode*, TreeNode*, TreeNode*, TreeNode*>>{
            {},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.lowestCommonAncestor(get<0>(c), get<1>(c), get<2>(c));
        auto expect = get<3>(c);
        ASSERT_EQ(result, expect);
    }
}
