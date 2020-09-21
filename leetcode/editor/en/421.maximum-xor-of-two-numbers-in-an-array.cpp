#include "base.h"
//Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231. 
//
//
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n. 
//
// Could you do this in O(n) runtime? 
//
// Example: 
//
// 
//Input: [3, 10, 5, 25, 2, 8]
//
//Output: 28
//
//Explanation: The maximum result is 5 ^ 25 = 28.
// 
//
// 
// Related Topics Bit Manipulation Trie 
// 👍 1221 👎 170


//leetcode submit region begin(Prohibit modification and deletion)
struct Trie {
    Trie *left;
    Trie *right;
};

class Solution {
public:
    void insert(Trie *root, unsigned val) const {
        for (auto i = 32u; i > 0; --i) {
            if ((val >> (i - 1)) & 1u) {
                if (root->right == nullptr) {
                    root->right = new Trie();
                }
                root = root->right;
            } else {
                if (root->left == nullptr) {
                    root->left = new Trie();
                }
                root = root->left;
            }
        }
    }

    int find(Trie *root, unsigned val) const {
        auto ans = 0u;
        for (auto i = 32u; i > 0; --i) {
            if ((val >> (i - 1)) & 1u) {
                if (root->left) {
                    root = root->left;
                    ans |= 1u << (i - 1);
                } else {
                    root = root->right;
                }
            } else {
                if (root->right) {
                    root = root->right;
                    ans |= 1u << (i - 1);
                } else {
                    root = root->left;
                }
            }
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        auto root = new Trie();
        for (auto const num : nums) {
            insert(root, num);
        }

        auto res = INT_MIN;
        for (auto const num : nums) {
            res = max(res, find(root, num));
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
