#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an integer array nums, return the number of range sums that lie in [lowe
//r, upper] inclusive. 
//Range sum S(i, j) is defined as the sum of the elements in nums between indice
//s i and j (i ≤ j), inclusive. 
//
// Note: 
//A naive algorithm of O(n2) is trivial. You MUST do better than that. 
//
// Example: 
//
// 
//Input: nums = [-2,5,-1], lower = -2, upper = 2,
//Output: 3 
//Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective s
//ums are: -2, -1, 2.
// Related Topics Binary Search Divide and Conquer Sort Binary Indexed Tree Segm
//ent Tree


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    typedef long long llong;
    int lower_, upper_;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        lower_ = lower, upper_ = upper;
        auto sums = vector<llong>(nums.size() + 1, 0);
        for (auto i = 0; i < nums.size(); ++i)
            sums[i+1] = sums[i] + nums[i];
        return merge_sort(sums, 0, sums.size());
    }

    int merge_sort(vector<llong>& sums, int begin, int end) {
        if (begin + 1 >= end) return 0;
        auto const mid = (begin + end) / 2;
        auto cnt = merge_sort(sums, begin, mid) +
                   merge_sort(sums, mid, end);
        cnt += count_cross_range(sums, begin, mid, end, upper_) -
               count_cross_range(sums, begin, mid, end, lower_ - 1);
        auto merged = merge(sums, begin, mid, mid, end);
        copy(merged.begin(), merged.end(), sums.begin() + begin);
        return cnt;
    }

    int count_cross_range(vector<llong>& sums, int begin, int mid, int end, int upper) {
        auto const begin_ = sums.begin() + begin;
        auto const end_ = sums.begin() + end;
        auto const mid_ = sums.begin() + mid;
        auto cnt = 0;
        auto r = mid_, l = begin_;
        while (r != end_) {
            l = upper_bound(l, mid_, *r - upper, less_equal<>());
            cnt += mid_ - l;
            ++r;
        }
        return cnt;
    }

    vector<int> merge(vector<llong>& list,
                      int ls, int const le, int rs, int const re) {
        auto merged = vector<int>();
        while (ls < le || rs < re) {
            if (rs == re || (ls < le && list[ls] < list[rs]))
                merged.push_back(list[ls++]);
            else
                merged.push_back(list[rs++]);
        }
        return merged;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestCountOfRangeSum, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int, int, int>>{
//            {{-2, 5, -1}, -2, 2, 3},
            {{0, 2, 1, 3, 4}, 3, 3, 2},
    };

    for (auto & c : cases) {
        auto result = sol.countRangeSum(get<0>(c), get<1>(c), get<2>(c));
        auto expect = get<3>(c);
        ASSERT_EQ(result, expect);
    }
}
