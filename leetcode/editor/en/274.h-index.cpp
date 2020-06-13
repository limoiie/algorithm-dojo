#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an array of citations (each citation is a non-negative integer) of a res
//earcher, write a function to compute the researcher's h-index. 
//
// According to the definition of h-index on Wikipedia: "A scientist has index h
// if h of his/her N papers have at least h citations each, and the other N − h pa
//pers have no more than h citations each." 
//
// Example: 
//
// 
//Input: citations = [3,0,6,1,5]
//Output: 3 
//Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each o
//f them had 
//             received 3, 0, 6, 1, 5 citations respectively. 
//             Since the researcher has 3 papers with at least 3 citations each 
//and the remaining 
//             two with no more than 3 citations each, her h-index is 3. 
//
// Note: If there are several possible values for h, the maximum one is taken as
// the h-index. 
// Related Topics Hash Table Sort


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        auto const total = citations.size();

        map<int, int> cnt;
        for (auto const cite : citations) {
            ++cnt[cite];
        }

        auto remain = total;
        for (auto i : cnt) {
            if (remain <= i.first) {
                return remain;
            } else if (remain - i.second <= i.first) {
                return i.first;
            }
            remain -= i.second;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestHIndex, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int>>{
            {{3,0,6,1,5}, 3},
            {{100}, 1},
            {{1,1}, 1},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.hIndex(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
