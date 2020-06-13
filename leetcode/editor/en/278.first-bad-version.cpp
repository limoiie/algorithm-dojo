#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//You are a product manager and currently leading a team to develop a new produc
//t. Unfortunately, the latest version of your product fails the quality check. Si
//nce each version is developed based on the previous version, all the versions af
//ter a bad version are also bad. 
//
// Suppose you have n versions [1, 2, ..., n] and you want to find out the first
// bad one, which causes all the following ones to be bad. 
//
// You are given an API bool isBadVersion(version) which will return whether ver
//sion is bad. Implement a function to find the first bad version. You should mini
//mize the number of calls to the API. 
//
// Example: 
//
// 
//Given n = 5, and version = 4 is the first bad version.
//
//call isBadVersion(3) -> false
//call isBadVersion(5) -> true
//call isBadVersion(4) -> true
//
//Then 4 is the first bad version. 
// 
// Related Topics Binary Search

bool isBadVersion(int version) {
    return false;
}

//leetcode submit region begin(Prohibit modification and deletion)
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        auto l = 0, r = n;
        while (l < r) {
            auto const m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestFirstBadVersion, testcase) {
//    auto sol = Solution();
//
//    auto cases = vector<tuple<..>>{
//            {},
//    };
//
//    for (auto & c : cases) {
//        cout << "testing " << c << "..." << endl;
//        auto result = sol.foo(get<0>(c));
//        auto expect = get<1>(c);
//        ASSERT_EQ(result, expect);
//    }
}
