#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an array of citations sorted in ascending order (each citation is a non-
//negative integer) of a researcher, write a function to compute the researcher's 
//h-index. 
//
// According to the definition of h-index on Wikipedia: "A scientist has index h
// if h of his/her N papers have at least h citations each, and the other N − h pa
//pers have no more than h citations each." 
//
// Example: 
//
// 
//Input: citations = [0,1,3,5,6]
//Output: 3 
//Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each o
//f them had 
//             received 0, 1, 3, 5, 6 citations respectively. 
//             Since the researcher has 3 papers with at least 3 citations each 
//and the remaining 
//             two with no more than 3 citations each, her h-index is 3. 
//
// Note: 
//
// If there are several possible values for h, the maximum one is taken as the h
//-index. 
//
// Follow up: 
//
// 
// This is a follow up problem to H-Index, where citations is now guaranteed to 
//be sorted in ascending order. 
// Could you solve it in logarithmic time complexity? 
// 
// Related Topics Binary Search


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        auto const total = static_cast<int>(citations.size());
        auto l = 0, r = total - 1;
        while (l <= r) {
            auto m = (l + r) / 2;
            if (citations[m] >= total - m && (m == 0 || citations[m-1] <= total - m)) {
                return total - m;
            }
            if (citations[m] <= total - m) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestHIndexII, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{0,1,3,5,6}, 3},
            {{100}, 1},
            {{1,1}, 1},
            {{0}, 0},
            {{0,0,4,4}, 2}
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.hIndex(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
