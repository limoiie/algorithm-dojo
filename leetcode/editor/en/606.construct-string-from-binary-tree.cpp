#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//You need to construct a string consists of parenthesis and integers from a bin
//ary tree with the preorder traversing way. 
//
// The null node needs to be represented by empty parenthesis pair "()". And you
// need to omit all the empty parenthesis pairs that don't affect the one-to-one m
//apping relationship between the string and the original binary tree. 
//
// Example 1: 
// 
//Input: Binary tree: [1,2,3,4]
//       1
//     /   \
//    2     3
//   /    
//  4     
//
//Output: "1(2(4))(3)"
// Explanation: Originallay it needs to be "1(2(4)())(3()())", but you need to o
//mit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)".
// 
// 
//
// Example 2: 
// 
//Input: Binary tree: [1,2,3,null,4]
//       1
//     /   \
//    2     3
//     \  
//      4 
//
//Output: "1(2()(4))(3)"
// Explanation: Almost the same as the first example, except we can't omit the f
//irst parenthesis pair to break the one-to-one mapping relationship between the i
//nput and the output.
// 
// Related Topics String Tree 
// 👍 776 👎 1051


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
    string tree2str(TreeNode* t) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestConstructStringFromBinaryTree, testcase) {
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
