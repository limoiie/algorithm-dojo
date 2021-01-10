#include "base.h"
//Given a collection of intervals, find the minimum number of intervals you need
// to remove to make the rest of the intervals non-overlapping.
//
//
//
//
//
//
// Example 1:
//
//
//Input: [[1,2],[2,3],[3,4],[1,3]]
//Output: 1
//Explanation: [1,3] can be removed and the rest of intervals are non-overlappin
//g.
//
//
// Example 2:
//
//
//Input: [[1,2],[1,2],[1,2]]
//Output: 2
//Explanation: You need to remove two [1,2] to make the rest of intervals non-ov
//erlapping.
//
//
// Example 3:
//
//
//Input: [[1,2],[2,3]]
//Output: 0
//Explanation: You don't need to remove any of the intervals since they're alrea
//dy non-overlapping.
//
//
//
//
// Note:
//
//
// You may assume the interval's end point is always bigger than its start point
//.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap
// each other.

// Related Topics Greedy 
// 👍 1556 👎 44


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ranges) {
        auto const n = ranges.size();
        sort(ranges.begin(), ranges.end(), [](vector<int> const& lhv, vector<int> const& rhv) {
            return lhv[1] == rhv [1] ? lhv[0] < rhv[0] : lhv[1] < rhv[1];
        });

        auto dp = vector<int>(n + 1, 0);
        auto ep = vector<int>(n + 1, 0);
        for (auto i = 0; i < n; ++i) {
            auto range = ranges[i];
            auto const itr = lower_bound(ranges.rbegin(), ranges.rend(), vector<int>{0, range[0]},
                                         [](vector<int> const& l, vector<int> const& r) {
                return l[1] > r[1];
            });
            auto const k = itr == ranges.rend() ? 0 : n - (itr - ranges.rbegin());

            ep[i + 1] = max(dp[i], ep[i]);
            dp[i + 1] = max(dp[k], ep[k]) + 1;
        }
        return n - max(dp[n], ep[n]);
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(X, xx) {
    auto v = vector<int>{0,2,4,6,8};
    auto r_k = lower_bound(v.rbegin(), v.rend(), 4, [](int const& l, int const& r) {
        return l > r;
    }) - v.rbegin();
    auto const k = v.size() - r_k - 1;
    cout << k << endl;
}