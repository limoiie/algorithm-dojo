#include "base.h"
//Given a non-empty string containing an out-of-order English representation of 
//digits 0-9, output the digits in ascending order. 
//
// Note: 
// 
// Input contains only lowercase English letters. 
// Input is guaranteed to be valid and can be transformed to its original digits
//. That means invalid inputs such as "abc" or "zerone" are not permitted. 
// Input length is less than 50,000. 
// 
// 
//
// Example 1: 
// 
//Input: "owoztneoer"
//
//Output: "012"
// 
// 
//
// Example 2: 
// 
//Input: "fviefuro"
//
//Output: "45"
// 
// Related Topics Math 
// 👍 172 👎 567


//leetcode submit region begin(Prohibit modification and deletion)
class Word {
public:
    explicit Word(string const &s) {
        for (auto c : s) {
            ++dict[c - 'a'];
        }
    }

    bool empty() const {
        for (auto c : dict) {
            if (c != 0) return false;
        }
        return true;
    }

    bool has(Word const &other) const {
        for (auto i = 0; i < 26; ++i) {
            if (dict[i] < other.dict[i])
                return false;
        }
        return true;
    }

    void minus(Word const &other) {
//        cout << "after minus: ";
        for (auto i = 0; i < 26; ++i) {
            dict[i] -= other.dict[i];
//            cout << dict[i] << ", ";
        }
//        cout << endl;
    }

    array<int, 26> dict{};
};

class Solution {
public:
    string originalDigits(string const &s) {
        auto res = string();
        auto all = Word(s);
        for (auto i = 0; i < 10; ++i) {
            auto const cnt = all.dict[hints[i] - 'a'];
            auto const dict = Word(words[i]);
            auto const digit = to_string(digits[i]);
            for (auto j = 0; j < cnt; ++j) {
                all.minus(dict);
                res.append(digit);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

private:
    vector<string> words = {
            "zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine",
    };

    vector<char> hints = {
            'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'
    };

    vector<int> digits = {
            0, 2, 4, 6, 8, 1, 3, 5, 7, 9
    };
};
//leetcode submit region end(Prohibit modification and deletion)
