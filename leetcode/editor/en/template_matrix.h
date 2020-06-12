//
// Created on 2020/6/12.
//

#ifndef ALGORITHM_DOJO_TEMPLATE_MATRIX_H
#define ALGORITHM_DOJO_TEMPLATE_MATRIX_H

#include "base.h"

class Solution {
    int m = 0, n = 0;
    vector<pair<int, int>> dir4 = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    vector<pair<int, int>> dir8 = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
    };

public:
    void doing(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) return;
        n = matrix.front().size();
    }

    void travel(vector<vector<int>>& matrix) const {
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                auto const x = matrix[i][j];
            }
        }
    }

    void look_up_neighbor(vector<vector<int>>& matrix, int x, int y) {
        for (const auto &dir : dir4) {
            auto const i = x + dir.first;
            auto const j = y + dir.second;
        }
    }

    [[nodiscard]] bool in_bound(int x, int y) const {
        return 0 <= x < m && 0 <= y < n;
    }

};

#endif //ALGORITHM_DOJO_TEMPLATE_MATRIX_H
