#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//A character in UTF8 can be from 1 to 4 bytes long, subjected to the following 
//rules: 
// 
// For 1-byte character, the first bit is a 0, followed by its unicode code. 
// For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, foll
//owed by n-1 bytes with most significant 2 bits being 10. 
// 
// This is how the UTF-8 encoding would work: 
//
//    Char. number range  |        UTF-8 octet sequence
//      (hexadecimal)    |              (binary)
//   --------------------+---------------------------------------------
//   0000 0000-0000 007F | 0xxxxxxx
//   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
//   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
//   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// 
// 
//Given an array of integers representing the data, return whether it is a valid
// utf-8 encoding.
// 
// 
//Note: 
//The input is an array of integers. Only the least significant 8 bits of each i
//nteger is used to store the data. This means each integer represents only 1 byte
// of data.
// 
//
// 
//Example 1:
// 
//data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 0
//0000001.
//
//Return true.
//It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte char
//acter.
// 
// 
//
// 
//Example 2:
// 
//data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 
//00000100.
//
//Return false.
//The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes char
//acter.
//The next byte is a continuation byte which starts with 10 and that's correct.
//But the second continuation byte does not start with 10, so it is invalid.
// 
// Related Topics Bit Manipulation 
// 👍 221 👎 1032


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for (auto i = 0; i < data.size(); ) {
            auto const c = static_cast<u_char>(data[i]);
            if ((c >> 3u) == 0b11110) {
                if (not valid(data, ++i, 3)) return false;
            } else if ((c >> 4u) == 0b1110) {
                if (not valid(data, ++i, 2)) return false;
            } else if ((c >> 5u) == 0b110) {
                if (not valid(data, ++i, 1)) return false;
            } else if ((c >> 7u) == 0b0) {
                if (not valid(data, ++i, 0)) return false;
            } else {
                return false;
            }
        }
        return true;
    }

    bool valid(vector<int> const& data, int &i, int k) {
        while (k--) {
            if (i >= data.size()) return false;
            auto const c  = static_cast<u_char>(data[i++]);
            if ((c >> 6u) != 0b10) {
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestUTF8Validation, testcase) {
//     auto sol = Solution();
// 
//     auto cases = vector<tuple<..>>{
//             {},
//     };
// 
//     for (auto & c : cases) {
//         cout << "testing " << c << "..." << endl;
//         auto result = sol.foo(get<0>(c));
//         auto expect = get<1>(c);
//         ASSERT_EQ(result, expect);
//     }
// }
