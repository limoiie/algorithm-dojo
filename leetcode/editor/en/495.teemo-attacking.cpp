#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//In LOL world, there is a hero called Teemo and his attacking can make his enem
//y Ashe be in poisoned condition. Now, given the Teemo's attacking ascending time
// series towards Ashe and the poisoning time duration per Teemo's attacking, you 
//need to output the total time that Ashe is in poisoned condition. 
//
// You may assume that Teemo attacks at the very beginning of a specific time po
//int, and makes Ashe be in poisoned condition immediately. 
//
// Example 1: 
//
// 
//Input: [1,4], 2
//Output: 4
//Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be po
//isoned immediately. 
//This poisoned status will last 2 seconds until the end of time point 2. 
//And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poison
//ed status for another 2 seconds. 
//So you finally need to output 4.
// 
//
// 
//
// Example 2: 
//
// 
//Input: [1,2], 2
//Output: 3
//Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be po
//isoned. 
//This poisoned status will last 2 seconds until the end of time point 2. 
//However, at the beginning of time point 2, Teemo attacks Ashe again who is alr
//eady in poisoned status. 
//Since the poisoned status won't add up together, though the second poisoning a
//ttack will still work at time point 2, it will stop at the end of time point 3. 
//
//So you finally need to output 3.
// 
//
// 
//
// Note: 
//
// 
// You may assume the length of given time series array won't exceed 10000. 
// You may assume the numbers in the Teemo's attacking time series and his poiso
//ning time duration per attacking are non-negative integers, which won't exceed 1
//0,000,000. 
// 
//
// 
// Related Topics Array


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration) {
        auto start = -1, last = -1, total = 0;
        for (auto const p : timeSeries) {
            if (p > last) {
                total += last - start;
                start = p;
            }
            last = p + duration;
        }
        return total + last - start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestTeemoAttacking, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<int>, int, int>>{
            {{1, 4}, 2, 4},
            {{1, 2}, 2, 3},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findPoisonedDuration(get<0>(c), get<1>(c));
        auto expect = get<2>(c);
        ASSERT_EQ(result, expect);
    }
}
