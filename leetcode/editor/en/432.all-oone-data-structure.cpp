#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Implement a data structure supporting the following operations: 
//
// 
// 
// Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1
//. Key is guaranteed to be a non-empty string. 
// Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise 
//decrements an existing key by 1. If the key does not exist, this function does n
//othing. Key is guaranteed to be a non-empty string. 
// GetMaxKey() - Returns one of the keys with maximal value. If no element exist
//s, return an empty string "". 
// GetMinKey() - Returns one of the keys with minimal value. If no element exist
//s, return an empty string "". 
// 
// 
//
// 
//Challenge: Perform all these in O(1) time complexity.
// Related Topics Design 
// 👍 652 👎 76


//leetcode submit region begin(Prohibit modification and deletion)
class Node {
public:
    Node(Node *next, Node *prev, unsigned lvl)
            : next(next), prev(prev), lvl(lvl) {
    }

    Node *next;
    Node *prev;
    unordered_set<string> set;
    unsigned lvl;

};

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne()
            : head(new Node(nullptr, nullptr, 0)), tail(new Node(nullptr, nullptr, 0)) {
        head->next = head->prev = tail;
        tail->prev = tail->next = head;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string const &key) {
        auto curr = remove_from_level(key);
        insert_into_level(curr, key, true);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string const &key) {
        auto curr = remove_from_level(key);
        if (curr == head) return;
        insert_into_level(curr, key, false);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (tail->prev == head) return string();
        return *tail->prev->set.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (head->next == tail) return string();
        return *head->next->set.begin();
    }

private:
    Node *remove_from_level(string const &key) {
        auto curr = head;
        auto x = index.find(key);
        if (x != index.end()) {
            curr = x->second;
            curr->set.erase(key);
            // if curr becomes empty, remove it from the linked-list
            if (curr->set.empty()) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
            }
            index.erase(x);
        }
        // return the original node that contains the key; if the original node
        // does not exist, return the head
        return curr;
    }

    void insert_into_level(Node *curr, string const &key, bool const inc) {
        auto const lvl = curr->lvl + (inc ? +1 : -1);
        auto lift = inc ? curr->next : curr->prev;
        if (lift->lvl != lvl) {  // if lift node does not exist, then insert it
            auto removed = curr->next->prev != curr;  // if curr has became a float node
            auto prev = removed ? curr->prev : (inc ? curr : lift);
            auto next = removed ? curr->next : (inc ? lift : curr);
            lift = new Node(next, prev, lvl);
            prev->next = next->prev = lift;
        }

        if (lift != head && lift != tail) {
            lift->set.insert(key);
            index[key] = lift;
        }
    }

    unordered_map<string, Node *> index;
    Node *head;
    Node *tail;

};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
//leetcode submit region end(Prohibit modification and deletion)


// TEST(TestAllO`oneDataStructure, testcase) {
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
