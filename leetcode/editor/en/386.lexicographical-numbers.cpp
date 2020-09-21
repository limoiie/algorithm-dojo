#include "base.h"
//Given an integer n, return 1 - n in lexicographical order. 
//
// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9]. 
//
// Please optimize your algorithm to use less time and space. The input size may
// be as large as 5,000,000. 
// 👍 573 👎 72


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if (n == 0) return {};
        auto res = vector<int>(n, 0);
        for (auto i = 0, c = 1; i < n; ++i) {
            res[i] = c;
            c *= 10;
            while (c > n) {
                c /= 10;
                ++c;
                while (c % 10 == 0)
                    c /= 10;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
