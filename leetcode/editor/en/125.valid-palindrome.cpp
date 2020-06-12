#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a string, determine if it is a palindrome, considering only alphanumeric
// characters and ignoring cases. 
//
// Note: For the purpose of this problem, we define empty string as valid palind
//rome. 
//
// Example 1: 
//
// 
//Input: "A man, a plan, a canal: Panama"
//Output: true
// 
//
// Example 2: 
//
// 
//Input: "race a car"
//Output: false
// 
// Related Topics Two Pointers String


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string const& s) {
        auto str = string();
        for (auto const c : s) {
            if (isalnum(c)) {
                str.push_back(tolower(c));
            }
        }

        auto l = 0, r = static_cast<int>(str.size()) - 1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            ++l, --r;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestValidPalindrome, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, bool>>{
            {"race a car", false},
            {"A man, a plan, a canal: Panama", true},
            {"0p", false},
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.isPalindrome(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
