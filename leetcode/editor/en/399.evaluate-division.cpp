#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Equations are given in the format A / B = k, where A and B are variables repre
//sented as strings, and k is a real number (floating point number). Given some qu
//eries, return the answers. If the answer does not exist, return -1.0. 
//
// Example: 
//Given a / b = 2.0, b / c = 3.0. 
//queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
//return [6.0, 0.5, -1.0, 1.0, -1.0 ]. 
//
// The input is: vector<pair<string, string>> equations, vector<double>& values,
// vector<pair<string, string>> queries , where equations.size() == values.size(),
// and the values are positive. This represents the equations. Return vector<doubl
//e>. 
//
// According to the example above: 
//
// 
//equations = [ ["a", "b"], ["b", "c"] ],
//values = [2.0, 3.0],
//queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//
// 
//
// The input is always valid. You may assume that evaluating the queries will re
//sult in no division by zero and there is no contradiction. 
// Related Topics Union Find Graph 
// 👍 2305 👎 179


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (auto const& eq : equations) {
            for (auto const& opd : eq) {
                if (not id.count(opd)) {
                    id[opd] = id.size();
                }
            }
        }

        for (auto i = 0; i < id.size(); ++i) {
            dis.emplace_back(id.size(), 1.0);
            f.push_back(i);
        }

        for (auto i = 0; i < equations.size(); ++i) {
            union_of(id[equations[i][0]], id[equations[i][1]], values[i]);
        }

        auto res = vector<double>();
        for (const auto &q : queries) {
            if (not id.count(q[0]) or not id.count(q[1])) {
                res.push_back(-1.0);
            } else {
                auto const a = id[q[0]], b = id[q[1]];
                if (find(a) != find(b)) {
                    res.push_back(-1.0);
                } else {
                    auto const x = find(a);
                    dis[a][b] = dis[a][x] * dis[x][b];
                    res.push_back(dis[a][b]);
                }
            }
        }
        return res;
    }

private:
    int find(int const x) {
        if (x == f[x]) return x;
        auto const y = find(f[x]);
        dis[y][x] = dis[y][f[x]] * dis[f[x]][x];
        dis[x][y] = 1.0 / dis[y][x];
        f[x] = y;
        return y;
    }

    void union_of(int const p, int const q, double const k) {
        auto fp = find(p), fq = find(q);
        if (q == fq) {
            f[q] = p;
        } else if (p == fp) {
            f[p] = q;
        } else {
            f[fq] = q;
            f[q] = p;
        }
        dis[p][q] = k;
        dis[q][p] = 1.0 / k;
    }

    vector<vector<double>> dis;
    map<string, int> id;
    vector<int> f;

};
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestEvaluateDivision, testcase) {
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
