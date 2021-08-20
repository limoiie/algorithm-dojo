#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size() + 1, 0);
        for (auto i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
        for (auto const& edge : edges) {
            if (_union(edge[0], edge[1]))
                return edge;
        }
        return {};
    }

    [[nodiscard]] int _find(int const x) {
        if (parent[x] != x) {
            return parent[x] = _find(parent[x]);
        }
        return x;
    }

    bool _union(int const x, int const y) {
        auto const px = _find(x);
        auto const py = _find(y);
        if (px == py) return true;
        parent[px] = py;
        return false;
    }

private:
    vector<int> parent {};
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestRedundantConnection, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<vector<int>>, vector<int>>>{
            {
                    {{1,2}, {1,3}, {2,3}},
                    {2,3}
            },
            {
                    {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}},
                    {1,4}
            }
    };

    for (auto & c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findRedundantConnection(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
