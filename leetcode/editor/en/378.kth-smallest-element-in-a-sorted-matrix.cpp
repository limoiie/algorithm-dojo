#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a n x n matrix where each of the rows and columns are sorted in ascendin
//g order, find the kth smallest element in the matrix. 
//
// 
//Note that it is the kth smallest element in the sorted order, not the kth dist
//inct element.
// 
//
// Example:
// 
//matrix = [
//   [ 1,  5,  9],
//   [10, 11, 13],
//   [12, 13, 15]
//],
//k = 8,
//
//return 13.
// 
// 
//
// Note: 
//You may assume k is always valid, 1 ≤ k ≤ n2. Related Topics Binary Search Hea
//p


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct compare {
        bool operator()(vector<int> const& lhs, vector<int> const& rhs) {
            return lhs[0] > rhs[0];
        }
    };

    int kthSmallest(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix.front().empty()) return 0;
        auto const m = static_cast<int>(matrix.size());
        auto const n = static_cast<int>(matrix.front().size());

        auto que = priority_queue<vector<int>, vector<vector<int>>, compare>();
        for (auto i = 0; i < m; ++i) {
            que.push({matrix[i][0], i, 0});
        }

        while (--k) {
            auto top = que.top(); que.pop();
            auto i = top[1], j = top[2];
            if (++j < n) {
                que.push({matrix[i][j], i, j});
            }
        }

        return que.top()[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestKthSmallestElementInASortedMatrix, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, int, int>>{
            {{{1,5,9},{10,11,13},{12,13,15}}, 8, 13},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.kthSmallest(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
