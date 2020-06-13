#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an integer n, count the total number of digit 1 appearing in all non-neg
//ative integers less than or equal to n. 
//
// Example: 
//
// 
//Input: 13
//Output: 6 
//Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
// 
// Related Topics Math


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countDigitOne(int n) {
        auto c = 0;
        for (long long int b = 1, div = 10; b <= n; b *= 10, div *= 10) {
            c += n / div * b + min<int>(max<int>((n % div - b + 1), 0), b);
        }
        return c;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestNumberOfDigitOne, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, int>>
            {
                    {0,          0},
                    {123123,     93081},
                    {123,        57},
                    {345,        175},
                    {1410065408, 1737167499}
            };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.countDigitOne(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
