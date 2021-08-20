#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rec
//tangle in the matrix such that its sum is no larger than k. 
//
// Example: 
//
// 
//Input: matrix = [[1,0,1],[0,-2,3]], k = 2
//Output: 2 
//Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
//             and 2 is the max number no larger than k (k = 2). 
//
// Note: 
//
// 
// The rectangle inside the matrix must have an area > 0. 
// What if the number of rows is much larger than the number of columns? 
// Related Topics Binary Search Dynamic Programming Queue


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix.front().empty()) return 0;
        auto const rows = matrix.size();
        auto const cols = matrix.front().size();

        auto res = INT_MIN;
        for (auto i = 0; i < cols; ++i) {
            auto sums = vector<int>(rows, 0);
            for (auto c = i; c < cols; ++c) {
                for (auto r = 0; r < rows; ++r)
                    sums[r] += matrix[r][c];

                res = max(res, max_sub_array(sums, k));
            }
        }
        return res;
    }

    int max_sub_array(vector<int> &array, int k) {
        auto max_sum = INT_MIN;
        auto sorted_sums = set<int>({0});

        auto inc_sum = 0;
        for (auto num : array) {
            inc_sum += num;
            auto const pre_sum = sorted_sums.lower_bound(inc_sum - k);
            if (pre_sum != sorted_sums.end()) {
                max_sum = max(max_sum, inc_sum - *pre_sum);
            }
            sorted_sums.insert(inc_sum);
        }
        return max_sum;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestMaxSumOfRectangleNoLargerThanK, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, int, int>>{
            {{{5, -4, -3, 4}, {-3, -4, 4, 5}, {5, 1, 5, -4}}, 3, 2},
            {{{2, 2, -1}}, 2, 2}
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.maxSumSubmatrix(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
