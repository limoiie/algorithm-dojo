#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//You are given two integer arrays nums1 and nums2 sorted in ascending order and
// an integer k. 
//
// Define a pair (u,v) which consists of one element from the first array and on
//e element from the second array. 
//
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums. 
//
// Example 1: 
//
// 
//Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
//Output: [[1,2],[1,4],[1,6]] 
//Explanation: The first 3 pairs are returned from the sequence: 
//             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6] 
//
// Example 2: 
//
// 
//Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
//Output: [1,1],[1,1]
//Explanation: The first 2 pairs are returned from the sequence: 
//             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3] 
//
// Example 3: 
//
// 
//Input: nums1 = [1,2], nums2 = [3], k = 3
//Output: [1,3],[2,3]
//Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
// 
// Related Topics Heap


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    struct compare {
        bool operator()(vector<int> &lhs, vector<int> &rhs) {
            return lhs[0] + lhs[1] > rhs[0] + rhs[1];
        }
    };

public:
    vector<vector<int>>
    kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};

        auto const ll = static_cast<int>(nums1.size());
        auto const rl = static_cast<int>(nums2.size());

        auto que = priority_queue<vector<int>, vector<vector<int>>, compare>();
        for (auto i = 0; i < min(k, ll); ++i)
            que.push({nums1[i], nums2[0], i, 0});

        auto res = vector<vector<int>>();
        while (k-- && !que.empty()) {
            auto item = que.top(); que.pop();

            auto const x = item[0], y = item[1], i = item[2], j = item[3];
            res.push_back({x, y});
            if (j + 1 < rl) {
                que.push({x, nums2[j + 1], i, j + 1});
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestFindKPairsWithSmallestSums, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, vector<int>, int, vector<vector<int>>>>{
            {{1, 1, 2}, {1, 2, 3}, 2, {{1, 1}, {1, 1}}},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.kSmallestPairs(get<0>(c), get<1>(c), get<2>(c));
        auto expect = get<3>(c);
        ASSERT_EQ(result, expect);
    }
}
