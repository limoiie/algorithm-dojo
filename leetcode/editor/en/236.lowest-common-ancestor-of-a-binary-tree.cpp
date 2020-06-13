#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes 
//in the tree. 
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor 
//is defined between two nodes p_ and q_ as the lowest node in T that has both p_ and
// q_ as descendants (where we allow a node to be a descendant of itself).”
//
// Given the following binary tree: root = [3,5,1,6,2,0,8,null,null,7,4] 
//
// 
//
// Example 1: 
//
// 
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], p_ = 5, q_ = 1
//Output: 3
//Explanation: The LCA of nodes 5 and 1 is 3.
// 
//
// Example 2: 
//
// 
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], p_ = 5, q_ = 4
//Output: 5
//Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant o
//f itself according to the LCA definition.
// 
//
// 
//
// Note: 
//
// 
// All of the nodes' values will be unique. 
// p_ and q_ are different and both values will exist in the binary tree.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent = nullptr, this->p_ = p, this->q_ = q;
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


TEST(TestLowestCommonAncestorOfABinaryTree, testcase) {
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
