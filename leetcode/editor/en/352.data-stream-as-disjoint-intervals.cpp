#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a data stream input of non-negative integers a1, a2, ..., an, ..., summa
//rize the numbers seen so far as a list of disjoint intervals. 
//
// For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ...
//, then the summary will be: 
//
// 
//[1, 1]
//[1, 1], [3, 3]
//[1, 1], [3, 3], [7, 7]
//[1, 3], [7, 7]
//[1, 3], [6, 7]
// 
//
// 
//
// Follow up: 
//
// What if there are lots of merges and the number of disjoint intervals are sma
//ll compared to the data stream's size? 
// Related Topics Binary Search Ordered Map


//leetcode submit region begin(Prohibit modification and deletion)
class SummaryRanges {
    vector<vector<int>> range;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        auto l = 0, r = static_cast<int>(range.size()) - 1;
        while (l <= r) {
            auto const m = (l + r) / 2;
            if (range[m][0] <= val && val <= range[m][1]) {
                return;
            } else if (range[m][0] - 1 == val) {
                range[m][0] = val;
                if (m - 1 >= 0 && range[m - 1][1] + 1 >= val) {
                    range[m - 1][1] = range[m][1];
                    range.erase(range.begin() + m);
                }
                return;
            } else if (range[m][1] + 1 == val) {
                range[m][1] = val;
                if (m + 1 < range.size() && range[m + 1][0] - 1 <= val) {
                    range[m + 1][0] = range[m][0];
                    range.erase(range.begin() + m);
                }
                return;
            } else if (val > range[m][1]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        range.insert(range.begin() + l, {val, val});
    }

    vector<vector<int>> getIntervals() {
        return range;
    }

};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestDataStreamAsDisjointIntervals, testcase) {
    auto cases = vector<tuple<vector<int>, vector<vector<int>>>>{
            {{1, 3, 7, 2, 6},                {{1, 3}, {6, 7}}},
            {{6, 6, 0, 4, 8, 7, 6, 4, 7, 5}, {{0, 0}, {4, 8}}}
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;

        auto range = SummaryRanges();
        for (auto num : get<0>(c)) {
            cout << "add: " << num << endl;
            range.addNum(num);
            cout << "range: " << range.getIntervals() << endl;
        }
        auto result = range.getIntervals();
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
