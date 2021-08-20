#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given N axis-aligned rectangles where N > 0, determine if they all together fo
//rm an exact cover of a rectangular region. 
//
// Each rectangle is represented as a bottom-left point and a top-right point. F
//or example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-lef
//t point is (1, 1) and top-right point is (2, 2)). 
//
// 
//
// Example 1: 
//
// 
//rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [3,2,4,4],
//  [1,3,2,4],
//  [2,3,3,4]
//]
//
//Return true. All 5 rectangles together form an exact cover of a rectangular re
//gion.
// 
//
// 
//
// 
//
// 
//
// Example 2: 
//
// 
//rectangles = [
//  [1,1,2,3],
//  [1,3,2,4],
//  [3,1,4,2],
//  [3,2,4,4]
//]
//
//Return false. Because there is a gap between the two rectangular regions.
// 
//
// 
//
// 
//
// 
//
// Example 3: 
//
// 
//rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [1,3,2,4],
//  [3,2,4,4]
//]
//
//Return false. Because there is a gap in the top center.
// 
//
// 
//
// 
//
// 
//
// Example 4: 
//
// 
//rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [1,3,2,4],
//  [2,2,4,4]
//]
//
//Return false. Because two of the rectangles overlap with each other.
// 
//
// Related Topics Line Sweep 
// 👍 376 👎 73


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isRectangleCover(vector<vector<int>> &rectangles) {
        auto area = 0;
        auto mem = unordered_set<int>();
        auto x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
        for (auto const &r : rectangles) {
            x1 = min(x1, r[0]), y1 = min(y1, r[1]);
            x2 = max(x2, r[2]), y2 = max(y2, r[3]);
            area += (r[3] - r[1]) * (r[2] - r[0]);
            auto const points = vector<int>(
                    {
                            hash(r[0], r[1]),
                            hash(r[0], r[3]),
                            hash(r[2], r[1]),
                            hash(r[2], r[3]),
                    });
            for (auto const &p : points) {
                if (mem.count(p)) mem.erase(p);
                else {
                    mem.insert(p);
                }
            }
        }
        return area == (x2 - x1) * (y2 - y1) and mem.size() == 4 and
               mem.count(hash(x1, y1)) and mem.count(hash(x1, y2)) and
               mem.count(hash(x2, y1)) and mem.count(hash(x2, y2));
    }

    static int hash(int const x, int const y) {
        return x + 1000 * y;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestPerfectRectangle, testcase) {
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
