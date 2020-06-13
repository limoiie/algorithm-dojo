#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a binary search tree, write a function kthSmallest to find the kth small
//est element in it. 
//
// 
//
// Example 1: 
//
// 
//Input: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//Output: 1 
//
// Example 2: 
//
// 
//Input: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//Output: 3
// 
//
// Follow up: 
//What if the BST is modified (insert/delete operations) often and you need to f
//ind the kth smallest frequently? How would you optimize the kthSmallest routine?
// 
//
// 
// Constraints: 
//
// 
// The number of elements of the BST is between 1 to 10^4. 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements. 
// 
// Related Topics Binary Search Tree


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
    int kthSmallest(TreeNode *root, int k) {
        return in_order(root, k);
    }

    int in_order(TreeNode *root, int &k) {
        if (root == nullptr) return 0;
        auto const l = in_order(root->left, k);
        if (k == 0) return l;
        if (--k == 0) return root->val;
        return in_order(root->right, k);;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestKthSmallestElementInABST, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<TreeNode *, int, int>>{
            {TreeNode::create({3, 1, 4, null, 2}), 1, 1},
            {TreeNode::create({3, 1, 4, null, 2}), 3, 3},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.kthSmallest(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
