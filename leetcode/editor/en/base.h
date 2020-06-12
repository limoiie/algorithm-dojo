#ifndef ALGORITHM_DOJO_BASE_H
#define ALGORITHM_DOJO_BASE_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <tuple>

#include "pretty_print.h"

using namespace std;

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
};


#endif //ALGORITHM_DOJO_BASE_H
