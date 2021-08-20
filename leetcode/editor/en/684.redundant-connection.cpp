#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        auto cache = std::map<int, std::shared_ptr<std::set<int>>>();
        for (auto const& edge : edges) {
            auto const i = edge[0], j = edge[1];
            auto pi = cache.find(i);
            auto pj = cache.find(j);
            if (pi == cache.end() && pj == cache.end()) {
                auto set = std::make_shared<std::set<int>>();
                set->insert(i);
                set->insert(j);
                cache[i] = cache[j] = set;
            } else if (pi != cache.end()) {
                pi->second->insert(j);
                cache[j] = pi->second;
            } else if (pj != cache.end()) {
                pj->second->insert(i);
                cache[i] = pj->second;
            } else {
            //    todo
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestRedundantConnection, testcase) {
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
