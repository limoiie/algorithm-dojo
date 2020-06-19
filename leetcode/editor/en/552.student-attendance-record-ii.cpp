#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

//#include <gtest/gtest.h>
#include "base.h"

//Given a positive integer n, return the number of all possible attendance recor
//ds with length n, which will be regarded as rewardable. The answer may be very l
//arge, return it after mod 109 + 7. 
//
// A student attendance record is a string that only contains the following thre
//e characters: 
//
// 
// 
// 'A' : Absent. 
// 'L' : Late. 
// 'P' : Present. 
// 
// 
//
// 
//A record is regarded as rewardable if it doesn't contain more than one 'A' (ab
//sent) or more than two continuous 'L' (late). 
//
// Example 1: 
// 
//Input: n = 2
//Output: 8 
//Explanation:
//There are 8 records with length 2 will be regarded as rewardable:
//"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
//Only "AA" won't be regarded as rewardable owing to more than one absent times.
// 
// 
// 
//
// Note:
//The value of n won't exceed 100,000.
// 
//
//
// Related Topics Dynamic Programming


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    static long long unsigned constexpr mask = 1e9 + 7;
public:
    int checkRecord(int n) {
        // dp[i] + dp[k] + dp[n-k-1] for each k in range(i);
        auto two_late = vector<int>(n + 1, 0);
        auto one_late = vector<int>(n + 1, 0);
        auto non_late = vector<int>(n + 1, 1);
        auto fn_get = [&](int const i) {
            return mask_add(
                    mask_add(non_late[i], one_late[i]), two_late[i]);
        };
        for (auto i = 1; i <= n; ++i) {
            non_late[i] = fn_get(i - 1);
            one_late[i] = non_late[i - 1];
            two_late[i] = one_late[i - 1];
        }
        auto ans = fn_get(n);
        for (auto i = 0, j = n - 1; i < n; ++i, --j) {
            ans = mask_add(ans,
                    mask_times(fn_get(i), fn_get(j)));
        }
        return ans;
    }

    [[nodiscard]] inline
    int mask_add(long long unsigned const lhs, long long unsigned const rhs) const {
        return static_cast<int>((lhs + rhs) % mask);
    }

    [[nodiscard]] inline
    int mask_times(long long unsigned const lhs, long long unsigned const rhs) const {
        return static_cast<int>((lhs * rhs) % mask);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


//TEST(TestLowestCommonAncestorOfABinarySearchTree, testcase) {
//    auto sol = Solution();
//
//    auto cases = vector<tuple<TreeNode*, TreeNode*, TreeNode*, TreeNode*>>{
//            {},
//    };
//
//    for (auto & c : cases) {
//        cout << "testing " << c << "..." << endl;
//        auto result = sol.lowestCommonAncestor(get<0>(c), get<1>(c), get<2>(c));
//        auto expect = get<3>(c);
//        ASSERT_EQ(result, expect);
//    }
//}
