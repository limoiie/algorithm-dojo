#include "base.h"
//Given a non-empty integer array of size n, find the minimum number of moves re
//quired to make all array elements equal, where a move is incrementing n - 1 elem
//ents by 1. 
//
// Example:
// 
//Input:
//[1,2,3]
//
//Output:
//3
//
//Explanation:
//Only three moves are needed (remember each move increments two elements):
//
//[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
// 
// Related Topics Math 
// 👍 698 👎 1016


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        auto const minimum = *min_element(nums.begin(), nums.end());
        auto sum = 0;
        for (auto const num : nums) {
            sum += num - minimum;
        }
        return sum;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
