#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Find the sum of all left leaves in a given binary tree. 
//
// Example:
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//There are two left leaves in the binary tree, with values 9 and 15 respectivel
//y. Return 24.
// 
// Related Topics Tree 
// 👍 1200 👎 129


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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        auto sum = 0;
        auto stk = stack<TreeNode *>();
        stk.push(root);
        while (not stk.empty()) {
            auto const node = stk.top(); stk.pop();
            if (node == nullptr) continue;
            if (node->left != nullptr) {
                if (node->left->left == nullptr and
                    node->left->right == nullptr) {
                    sum += node->left->val;
                } else {
                    stk.push(node->left);
                }
            }
            stk.push(node->right);
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestSumOfLeftLeaves, testcase) {
//     auto sol = Solution();
// 
//     auto cases = vector<tuple<..>>{
//             {},
//     };
// 
//     for (auto & c : cases) {
//         cout << "testing " << c << "..." << endl;
//         auto result = sol.foo(get<0>(c));
//         auto expect = get<1>(c);
//         ASSERT_EQ(result, expect);
//     }
// }
