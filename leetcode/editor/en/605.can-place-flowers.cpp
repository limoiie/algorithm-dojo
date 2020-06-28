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
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestCanPlaceFlowers, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<..>>{
            {},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.foo(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
