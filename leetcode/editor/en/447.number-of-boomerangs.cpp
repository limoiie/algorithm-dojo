#include "base.h"
//Given n points in the plane that are all pairwise distinct, a "boomerang" is a
// tuple of points (i, j, k) such that the distance between i and j equals the dis
//tance between i and k (the order of the tuple matters). 
//
// Find the number of boomerangs. You may assume that n will be at most 500 and 
//coordinates of points are all in the range [-10000, 10000] (inclusive). 
//
// Example: 
//
// 
//Input:
//[[0,0],[1,0],[2,0]]
//
//Output:
//2
//
//Explanation:
//The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
// 
//
// 
// Related Topics Hash Table 
// 👍 427 👎 723


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        auto pow2 = [](int const x) { return x * x; };
        auto compute = [&pow2](vector<int> const& lhv, vector<int> const& rhv) {
            return pow2(lhv[0] - rhv[0]) + pow2(lhv[1] - rhv[1]);
        };

        auto res = 0;
        for (auto i = 0; i < points.size(); ++i) {
            auto cnt = map<int, int>();
            for (auto j = 0; j < points.size(); ++j) {
                if (j == i) continue;
                ++cnt[compute(points[i], points[j])];
            }

            for (auto const& p : cnt) {
                res += p.second * (p.second - 1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
