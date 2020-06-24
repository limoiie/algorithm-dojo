#ifndef ALGORITHM_DOJO_BASE_H
#define ALGORITHM_DOJO_BASE_H

#include <iostream>
#include <memory.h>
#include <numeric>
#include <string>
#include <algorithm>
#include <memory>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <climits>

#include "pretty_print.h"

using namespace std;

const auto null = INT_MAX;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    bool operator==(const ListNode &rhs) const {
        if (val == rhs.val) {
            if (next == rhs.next) return true;
            if (next && rhs.next && *next == *rhs.next) return true;
        }
        return false;
    }

    bool operator!=(const ListNode &rhs) const {
        return !(rhs == *this);
    }

    static ListNode *create(vector<int> const &l) {
        auto head = new ListNode(0);
        auto curr = head;
        for (auto i : l) {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
        return head->next;
    }
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    bool operator==(const TreeNode &rhs) const {
        if (val != rhs.val) return false;
        if (left == rhs.left && right == rhs.right) return true;
        if (left == nullptr || rhs.left == nullptr) return false;
        if (right == nullptr || rhs.right == nullptr) return false;
        return *left == *rhs.left && *right == *rhs.right;
    }

    bool operator!=(const TreeNode &rhs) const {
        return !(rhs == *this);
    }

    static TreeNode *create(vector<int> const& v) {
        auto n = vector<TreeNode*>();
        for (auto const num : v) {
            n.push_back(num == null ? nullptr : new TreeNode(num));
        }
        for (auto i = 0; i < n.size(); ++i) {
            auto l = i * 2 + 1, r = i * 2 + 2;
            if (l < n.size()) n[i]->left = n[l];
            if (r < n.size()) n[i]->right = n[r];
        }
        return n.front();
    }
};


#endif //ALGORITHM_DOJO_BASE_H
