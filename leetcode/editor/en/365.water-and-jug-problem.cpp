#pragma clang diagnostic push
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantConditions"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//You are given two jugs with capacities x and y litres. There is an infinite am
//ount of water supply available. You need to determine whether it is possible to 
//measure exactly z litres using these two jugs. 
//
// If z liters of water is measurable, you must have z liters of water contained
// within one or both buckets by the end. 
//
// Operations allowed: 
//
// 
// Fill any of the jugs completely with water. 
// Empty any of the jugs. 
// Pour water from one jug into another till the other jug is completely full or
// the first jug itself is empty. 
// 
//
// Example 1: (From the famous "Die Hard" example) 
//
// 
//Input: x = 3, y = 5, z = 4
//Output: True
// 
//
// Example 2: 
//
// 
//Input: x = 2, y = 6, z = 5
//Output: False
// Related Topics Math


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return (z == 0 || x + y >= z && z % __gcd(x, y) == 0);
    }

private:
#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-reserved-identifier"
    int __gcd(int x, int y) {
        if (x < y) return __gcd(y, x);
        auto g = max(x, y);
        auto l = min(x, y);
        while (l) {
            auto const t = g % l;
            g = l;
            l = t;
        }
        return g;
    }
#pragma clang diagnostic pop

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestWaterAndJugProblem, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, int, int, bool>>{
            {3, 5, 4, true},
            {1, 2, 3, true},
            {104659, 104677, 142424, true},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.canMeasureWater(get<0>(c), get<1>(c), get<2>(c));
        auto expect = get<3>(c);
        ASSERT_EQ(result, expect);
    }
}
