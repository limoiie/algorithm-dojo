#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an integer array of size n, find all elements that appear more than ⌊ n/
//3 ⌋ times. 
//
// Note: The algorithm should run in linear time and in O(1) space. 
//
// Example 1: 
//
// 
//Input: [3,2,3]
//Output: [3] 
//
// Example 2: 
//
// 
//Input: [1,1,1,3,3,2,2,2]
//Output: [1,2] 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        auto can1 = 0, cnt1 = 0, can2 = 1, cnt2 = 0;
        for (auto num : nums) {
            if (can1 == num) ++cnt1;
            else if (can2 == num) ++cnt2;
            else if (cnt1 == 0) can1 = num, cnt1 = 1;
            else if (cnt2 == 0) can2 = num, cnt2 = 1;
            else --cnt1, --cnt2;
        }

        cnt1 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (num == can1) ++cnt1;
            if (num == can2) ++cnt2;
        }

        auto res = vector<int>();
        if (cnt1 > nums.size() / 3) res.push_back(can1);
        if (cnt2 > nums.size() / 3) res.push_back(can2);
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestMajorityElementII, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, vector<int>>>{
            {{0,0,0}, {0}},
            {{0,3,4,0}, {0}},
            {{3,2,3}, {3}},
            {{3,3,3,2,2,1,1,1}, {3,1}},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.majorityElement(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
