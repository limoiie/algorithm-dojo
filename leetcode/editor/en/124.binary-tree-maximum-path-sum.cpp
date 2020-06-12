#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a non-empty binary tree, find the maximum path sum. 
//
// For this problem, a path is defined as any sequence of nodes from some starti
//ng node to any node in the tree along the parent-child connections. The path mus
//t contain at least one node and does not need to go through the root. 
//
// Example 1: 
//
// 
//Input: [1,2,3]
//
//       1
//      / \
//     2   3
//
//Output: 6
// 
//
// Example 2: 
//
// 
//Input: [-10,9,20,null,null,15,7]
//
//   -10
//   / \
//  9  20
//    /  \
//   15   7
//
//Output: 42
// 
// Related Topics Tree Depth-first Search


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int max_sum = 0;
public:
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        max_line_sum(root);
        return max_sum;
    }

    int max_line_sum(TreeNode *root) {
        if (root == nullptr) return 0;
        auto const left = max_line_sum(root->left);
        auto const right = max_line_sum(root->right);
        max_sum = max(max_sum, left + right + root->val);
        return max(max(max(left, right) + root->val, root->val), 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestBinaryTreeMaximumPathSum, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<TreeNode*, int>>{
            {},
    };

    for (auto & c : cases) {
        auto result = sol.maxPathSum(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
