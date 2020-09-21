#include "base.h"
//Shuffle a set of numbers without duplicates.
// 
//
// Example:
// 
//// Init an array with set 1, 2, and 3.
//int[] nums = {1,2,3};
//Solution solution = new Solution(nums);
//
//// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3]
// must equally likely to be returned.
//solution.shuffle();
//
//// Resets the array back to its original configuration [1,2,3].
//solution.reset();
//
//// Returns the random shuffling of array [1,2,3].
//solution.shuffle();
// 
// 👍 532 👎 1066


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    explicit Solution(vector<int>& nums) : nums(nums), flag(nums.size(), false) {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto const n = nums.size();
        fill(flag.begin(), flag.end(), false);

        auto res = vector<int>(n);
        for (auto i = 0; i < n; ++i) {
            auto k = static_cast<int>(e() % (n - i)) + 1;
            auto j = 0;
            for (; j < n; ++j) {
                if (flag[j]) continue;
                if (--k == 0) {
                    break;
                }
            }
            res[i] = nums[j];
            flag[j] = true;
        }
        return res;
    }

private:
    default_random_engine e;

    vector<int> const& nums;
    vector<bool> flag;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
//leetcode submit region end(Prohibit modification and deletion)
