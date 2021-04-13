#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an array of integers with possible duplicates, randomly output the index
// of a given target number. You can assume that the given target number must exis
//t in the array. 
//
// Note: 
//The array size can be very large. Solution that uses too much extra space will
// not pass the judge. 
//
// Example: 
//
// 
//int[] nums = new int[] {1,2,3,3,3};
//Solution solution = new Solution(nums);
//
//// pick(3) should return either index 2, 3, or 4 randomly. Each index should h
//ave equal probability of returning.
//solution.pick(3);
//
//// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
//solution.pick(1);
// 
// Related Topics Reservoir Sampling 
// 👍 491 👎 682


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    explicit Solution(vector<int>& nums) : n(nums) {
    }
    
    int pick(int const target) {
        int res;
        do {
            res = rand() % n.size();
        } while (n[res] != target);
        return res;
    }

private:
    vector<int> const& n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestRandomPickIndex, testcase) {
//     auto sol = Solution();
// 
//     auto cases = vector<tuple<..>>{
//             {},
//     };
// 
//     for (auto & c : cases) {
//         cout << "testing " << c << "..." << endl;
//         auto result = sol.foo(get<0>(c));
//         auto expect = get<1>(c);
//         ASSERT_EQ(result, expect);
//     }
// }
