#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Suppose you have a long flowerbed in which some of the plots are planted and s
//ome are not. However, flowers cannot be planted in adjacent plots - they would c
//ompete for water and both would die. 
//
// Given a flowerbed (represented as an array containing 0 and 1, where 0 means 
//empty and 1 means not empty), and a number n, return if n new flowers can be pla
//nted in it without violating the no-adjacent-flowers rule. 
//
// Example 1: 
// 
//Input: flowerbed = [1,0,0,0,1], n = 1
//Output: True
// 
// 
//
// Example 2: 
// 
//Input: flowerbed = [1,0,0,0,1], n = 2
//Output: False
// 
// 
//
// Note: 
// 
// The input array won't violate no-adjacent-flowers rule. 
// The input array size is in the range of [1, 20000]. 
// n is a non-negative integer which won't exceed the input array size. 
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto head = 0, i = 0;
        while (i < flowerbed.size() and flowerbed[i] == 0) {
            ++head, ++i;
        }

        if (head == flowerbed.size()) return how_much(head) >= n;

        auto res = head > 0 ? how_much(head - 1) : 0;
        auto blank = 0;
        while (i < flowerbed.size()) {
            if (flowerbed[i]) {
                if (blank > 1)
                    res += how_much(blank - 2);
                blank = -1;
            }
            ++blank, ++i;
        }
        return res + (blank > 0 ? how_much(blank - 1) : 0) >= n;
    }

private:
    inline
    int how_much(int const n) {
        return (int) (static_cast<unsigned>(n + 1) >> 1u);
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestCanPlaceFlowers, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int, bool>>{
            {{1,0,0,0,1}, 3, false},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.canPlaceFlowers(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
