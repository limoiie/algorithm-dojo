#include "base.h"
//You are given a binary tree in which each node contains an integer value. 
//
// Find the number of paths that sum to a given value. 
//
// The path does not need to start or end at the root or a leaf, but it must go 
//downwards
//(traveling only from parent nodes to child nodes). 
//
// The tree has no more than 1,000 nodes and the values are in the range -1,000,
//000 to 1,000,000.
//
// Example:
// 
//root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//Return 3. The paths that sum to 8 are:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. -3 -> 11
// 
// Related Topics Tree 
// 👍 4309 👎 309


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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        auto cnt = count_paths_which_start_from(root, sum, 0);
        cnt += pathSum(root->left, sum);
        cnt += pathSum(root->right, sum);
        return cnt;
    }

private:
    int count_paths_which_start_from(TreeNode* node, int const sum, int part_sum) { // NOLINT(readability-convert-member-functions-to-static)
        auto cnt = 0;
        if (node == nullptr) return cnt;
        if (sum == (part_sum += node->val)) {
            ++cnt;
        }
        cnt += count_paths_which_start_from(node->left, sum, part_sum);
        cnt += count_paths_which_start_from(node->right, sum, part_sum);
        return cnt;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
