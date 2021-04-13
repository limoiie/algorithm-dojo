#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//A password is considered strong if below conditions are all met: 
//
// 
// It has at least 6 characters and at most 20 characters. 
// It must contain at least one lowercase letter, at least one uppercase letter,
// and at least one digit. 
// It must NOT contain three repeating characters in a row ("...aaa..." is weak,
// but "...aa...a..." is strong, assuming other conditions are met). 
// 
//
// Write a function strongPasswordChecker(s), that takes a string s as input, an
//d return the MINIMUM change required to make s a strong password. If s is alread
//y strong, return 0. 
//
// Insertion, deletion or replace of any one character are all considered as one
// change. 👍 187 👎 619


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int strongPasswordChecker(string s, int const minimum = 6, int const maximum = 20) {
        int replacements = 0, size = s.size();
        vector<int> remainders { 0, 0, 10000 }, counts { 0, 0, 0 };

        for (int i = 1; i < s.size(); ++i)
            if (s[i] != s[i - 1])
                s.insert(i++, 1, ' ');

        stringstream ss(s);
        string repeat;

        while (ss >> repeat)
        {
            auto ch = repeat.front();
            counts[0] += isdigit(ch), counts[1] += isupper(ch), counts[2] += islower(ch);

            replacements += repeat.size() / 3;
            if (repeat.size() >= 3) remainders[repeat.size() % 3]++;
        }

        int deletions = max(0, size - maximum);
        int additions = max((int) count(counts.begin(), counts.end(), 0), minimum - size);

        for (int i = 0, d = deletions; i < remainders.size(); d = max(d - remainders[i] * (i + 1), 0), i++)
            replacements -= min(remainders[i], d / (i + 1));

        return deletions + max(replacements, additions);
    }

};
//leetcode submit region end(Prohibit modification and deletion)


 TEST(TestStrongPasswordChecker, testcase) {
     auto sol = Solution();

     auto cases = vector<tuple<string, int>>{
             {"aaaaaa", 2},
     };

     for (auto & c : cases) {
         cout << "testing " << c << "..." << endl;
         auto result = sol.strongPasswordChecker(get<0>(c));
         auto expect = get<1>(c);
         ASSERT_EQ(result, expect);
     }
 }
