#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Your task is to calculate ab mod 1337 where a is a positive integer and b is a
//n extremely large positive integer given in the form of an array. 
//
// Example 1: 
//
// 
// 
//Input: a = 2, b = [3]
//Output: 8
// 
//
// 
// Example 2: 
//
// 
//Input: a = 2, b = [1,0]
//Output: 1024
// 
// 
// Related Topics Math


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static auto constexpr MASK = 1337;
    static auto constexpr trunk = 6;
    static auto constexpr trunk_pow_idx = 1e6;
public:
    int superPow(int a, vector<int> &b) const {
        auto const n = static_cast<int>(b.size());
        auto base = a, pow = 1;
        for (auto i = n; i > 0; i -= trunk) {
            auto idx = fetch(b, i, min(i, trunk));
            pow = times(pow, fast_pow(base, idx));
            base = fast_pow(base, trunk_pow_idx);
        }
        return pow;
    }

    inline int fetch(vector<int> &b, int i, int l) const {
        auto idx = 0;
        while (l--) idx = idx * 10 + b[i - l - 1];
        return idx;
    }

    [[nodiscard]] int fast_pow(int a, unsigned n) const {
        auto base = a, pow = 1;
        while (n) {
            if (n & 1u) pow = times(pow, base);
            base = times(base, base);
            n >>= 1u;
        }
        return pow;
    }

    [[nodiscard]] inline int times(int lhs, int rhs) const {
        return mask(mask(lhs) * mask(rhs));
    }

    [[nodiscard]] inline int mask(int v) const {
        return v % MASK;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestSuperPow, testcase) {
    auto sol = Solution();
    cout << "pow: " << sol.fast_pow(2, 10) << endl;

    auto cases = vector<tuple<int, vector<int>, int>>{
            {2,   {1, 2, 3, 4},       478},
            {123, {1, 2, 3, 4, 5, 6}, 589},
            {12,  {0},                1},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.superPow(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
