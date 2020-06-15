#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created on 2020/6/14.
//

#include "binary_search.h"

#include <gtest/gtest.h>
#include "base.h"


namespace binary_search {
    int left_be(vector<int> const &num, int target, int l, int r) {
        while (l <= r) {
            auto const m = (l + r) / 2;
            if (num[m] < target) {
                l = m + 1;
            } else {  // num[m] >= target
                r = m - 1;
            }
        }
        return l;
    }

    int left_be(vector<int> const &num, int target) {
        auto l = 0, r = static_cast<int>(num.size()) - 1;
        return left_be(num, target, l, r);
    }

}  // namespace binary_search

using namespace binary_search;

TEST(TestLeftBe, testcase) {
    auto cases = vector<tuple<vector<int>, int, int>>{
            {{1, 2, 3, 3, 4, 5}, 3, 2},
            {{1, 3, 3, 3, 4, 5}, 3, 1},
            {{1, 2, 3, 3, 3, 5}, 3, 2},
            {{3, 3, 3, 3, 3, 5}, 3, 0},
            {{2},                3, 1},
            {{2, 2},             3, 2},
    };

    for (auto const &c : cases) {
        cout << "testing " << c << " ..." << endl;
        ASSERT_EQ(left_be(get<0>(c), get<1>(c)), get<2>(c));
    }
}
