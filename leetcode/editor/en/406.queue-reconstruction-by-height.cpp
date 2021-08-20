#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Suppose you have a random list of people standing in a queue. Each person is d
//escribed by a pair of integers (h, k), where h is the height of the person and k
// is the number of people in front of this person who have a height greater than 
//or equal to h. Write an algorithm to reconstruct the queue. 
//
// Note: 
//The number of people is less than 1,100. 
// 
//
// Example 
//
// 
//Input:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
//Output:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
// 
//
// 
// Related Topics Greedy 
// 👍 3204 👎 361


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), [](vector<int> const &lhv, vector<int> const &rhv) {
            return lhv[1] == rhv[1] ? lhv[0] > rhv[0] : lhv[1] < rhv[1];
        });

        auto res = vector<vector<int>>();
        for (auto const &a : people) {
            auto l = 0, pre_cnt = a[1];
            for (; l < res.size() and pre_cnt != 0; ++l) {
                auto const l_h = res[l][0];
                if (l_h >= a[0]) {
                    --pre_cnt;
                }
            }
            res.insert(res.begin() + l, a);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestQueueReconstructionByHeight, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, vector<vector<int>>>>{
            {
                    {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}},
                    {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}}
            },
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.reconstructQueue(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
