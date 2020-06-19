#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a list of words (without duplicates), please write a program that return
//s all concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of at l
//east two shorter words in the given array. 
//
// Example: 
// 
//Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","
//ratcatdogcat"]
//
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//
//Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";  "
//dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat" can b
//e concatenated by "rat", "cat", "dog" and "cat".
// 
// 
//
// Note: 
// 
// The number of elements of the given array will not exceed 10,000 
// The length sum of elements in the given array will not exceed 600,000. 
// All the input string will only include lower case letters. 
// The returned elements order does not matter. 
// 
// Related Topics Dynamic Programming Depth-first Search Trie


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
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
