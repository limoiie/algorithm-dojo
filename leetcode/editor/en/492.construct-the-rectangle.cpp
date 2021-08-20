#include "base.h"
//A web developer needs to know how to design a web page's size. So, given a spe
//cific rectangular web page’s area, your job by now is to design a rectangular we
//b page, whose length L and width W satisfy the following requirements: 
//
// 
// The area of the rectangular web page you designed must equal to the given tar
//get area. 
// The width W should not be larger than the length L, which means L >= W. 
// The difference between length L and width W should be as small as possible. 
// 
//
// Return an array [L, W] where L and W are the length and width of the web page
// you designed in sequence. 
//
// 
// Example 1: 
//
// 
//Input: area = 4
//Output: [2,2]
//Explanation: The target area is 4, and all the possible ways to construct it a
//re [1,4], [2,2], [4,1]. 
//But according to requirement 2, [1,4] is illegal; according to requirement 3, 
// [4,1] is not optimal compared to [2,2]. So the length L is 2, and the width W i
//s 2.
// 
//
// Example 2: 
//
// 
//Input: area = 37
//Output: [37,1]
// 
//
// Example 3: 
//
// 
//Input: area = 122122
//Output: [427,286]
// 
//
// 
// Constraints: 
//
// 
// 1 <= area <= 107 
// 
// Related Topics Math 
// 👍 280 👎 289


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> constructRectangle(int const area) {
        for (auto h = static_cast<int>(sqrt(area)); h > 0; --h) {
            if (area % h) continue;
            return {area / h, h};
        }
        return {area, 1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
