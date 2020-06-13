#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Convert a non-negative integer to its english words representation. Given inpu
//t is guaranteed to be less than 231 - 1. 
//
// Example 1: 
//
// 
//Input: 123
//Output: "One Hundred Twenty Three"
// 
//
// Example 2: 
//
// 
//Input: 12345
//Output: "Twelve Thousand Three Hundred Forty Five" 
//
// Example 3: 
//
// 
//Input: 1234567
//Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven
//"
// 
//
// Example 4: 
//
// 
//Input: 1234567891
//Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven 
//Thousand Eight Hundred Ninety One"
// 
// Related Topics Math String


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        auto units = vector<string>{
                "", " Thousand", " Million", " Billion"
        };

        auto str = string();
        for (auto i = 0; num; ++i, num /= 1000) {
            if (auto const n = num % 1000) {
                auto temp = in_thousand(n) + units[i];
                str = temp.append(str);
            }
        }
        return str.substr(1);
    }

    string in_thousand(int num) {
        auto str = string();
        auto const a = (num / 100) % 10;
        auto const b = (num / 10) % 10;
        auto const c = (num / 1) % 10;
        if (a != 0) str.append(in_ten(a)).append(" Hundred");
        if (b == 1) str.append(in_twenty(c));
        else str.append(in_hundred(b)).append(in_ten(c));
        return str;
    }

    string in_ten(int num) {
        switch (num) {
            case 0: return "";
            case 1: return " One";
            case 2: return " Two";
            case 3: return " Three";
            case 4: return " Four";
            case 5: return " Five";
            case 6: return " Six";
            case 7: return " Seven";
            case 8: return " Eight";
            case 9: return " Nine";
            default: break;
        }
        throw runtime_error("");
    }

    string in_twenty(int num) {
        switch (num) {
            case 0: return " Ten";
            case 1: return " Eleven";
            case 2: return " Twelve";
            case 3: return " Thirteen";
            case 4: return " Fourteen";
            case 5: return " Fifteen";
            case 6: return " Sixteen";
            case 7: return " Seventeen";
            case 8: return " Eighteen";
            case 9: return " Nineteen";
            default: break;
        }
        throw runtime_error("");
    }

    string in_hundred(int num) {
        switch (num) {
            case 0: return "";
            case 2: return " Twenty";
            case 3: return " Thirty";
            case 4: return " Forty";
            case 5: return " Fifty";
            case 6: return " Sixty";
            case 7: return " Seventy";
            case 8: return " Eighty";
            case 9: return " Ninety";
            default: break;
        }
        throw runtime_error("");
    }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestIntegerToEnglishWords, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<int, string>>{
            {10, "Ten"},
            {123, "One Hundred Twenty Three"},
            {123123, "One Hundred Twenty Three Thousand One Hundred Twenty Three"},
            {1234567891, "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"}
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.numberToWords(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
