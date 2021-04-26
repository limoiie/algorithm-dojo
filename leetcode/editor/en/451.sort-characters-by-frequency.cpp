#include "base.h"
//Given a string, sort it in decreasing order based on the frequency of characte
//rs. 
//
// Example 1:
// 
//Input:
//"tree"
//
//Output:
//"eert"
//
//Explanation:
//'e' appears twice while 'r' and 't' both appear once.
//So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid a
//nswer.
// 
// 
//
// Example 2:
// 
//Input:
//"cccaaa"
//
//Output:
//"cccaaa"
//
//Explanation:
//Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
//Note that "cacaca" is incorrect, as the same characters must be together.
// 
// 
//
// Example 3:
// 
//Input:
//"Aabb"
//
//Output:
//"bbAa"
//
//Explanation:
//"bbaA" is also a valid answer, but "Aabb" is incorrect.
//Note that 'A' and 'a' are treated as two different characters.
// 
// Related Topics Hash Table Heap 
// 👍 2057 👎 141


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string frequencySort(string const& s) {
        auto m = vector<int>(128, 0);
        auto cnt = multimap<int, char, greater<>>();
        for (auto const c : s) {
            ++m[c];
        }

        for (auto i = 0; i < m.size(); ++i) {
            if (m[i] > 0) {
                cnt.insert({m[i], i});
            }
        }

        auto ans = string();
        for (auto const& p : cnt) {
            ans.append(p.first, p.second);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
