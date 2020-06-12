#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
//for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
// repeated sequences within the DNA. 
//
// Write a function to find all the 10-letter-long sequences (substrings) that o
//ccur more than once in a DNA molecule. 
//
// Example: 
//
// 
//Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//
//Output: ["AAAAACCCCC", "CCCCCAAAAA"]
// 
// Related Topics Hash Table Bit Manipulation


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    map<char, unsigned> c2i;
    map<unsigned, char> i2c;

public:
    vector<string> findRepeatedDnaSequences(string const& s) {
        if (s.size() < 10) return {};

        init();
        auto res = vector<string>{};
        auto m = unordered_map<unsigned, int>();
        auto bits = to_bits(s.substr(0, 9));
        for (auto c : s.substr(9)) {
            bits = (bits >> 2u) | (c2i[c] << 18u);
            if (++m[bits] == 2) {
                res.push_back(to_str(bits));
            }
        }
        return res;
    }

    unsigned to_bits(string const& str) {
        auto bits = 0u, offset = 0u;
        for (auto c: str) {
            bits |= c2i[c] << offset;
            offset += 2u;
        }
        return bits << 2u;
    }

    string to_str(unsigned bits) {
        auto str = string();
        for (auto i = 0; i < 10; ++i) {
            str.push_back(i2c[bits & 0b11u]);
            bits >>= 2u;
        }
        return str;
    }

    void init() {
        i2c = map<unsigned, char>();
        c2i = map<char, unsigned>();
        i2c[0u] = 'A', i2c[1u] = 'C', i2c[2u] = 'T', i2c[3u] = 'G';
        for (auto const& p : i2c) {
            c2i[p.second] = p.first;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestRepeatedDNASequences, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<string, vector<string>>>{
            {"AAAAAAAAAAA", {"AAAAAAAAAA"}},
            {"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", {"AAAAACCCCC", "CCCCCAAAAA"}}
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findRepeatedDnaSequences(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
