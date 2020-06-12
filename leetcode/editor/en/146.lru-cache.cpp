#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Design and implement a data structure for Least Recently Used (LRU) cache. It 
//should support the following operations: get and put. 
//
// get(key) - Get the value (will always be positive) of the key if the key exis
//ts in the cache, otherwise return -1. 
//put(key, value) - Set or insert the value if the key is not already present. W
//hen the cache reached its capacity, it should invalidate the least recently used
// item before inserting a new item. 
//
// The cache is initialized with a positive capacity. 
//
// Follow up: 
//Could you do both operations in O(1) time complexity? 
//
// Example: 
//
// 
//LRUCache cache = new LRUCache( 2 /* capacity */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4
// 
//
// 
// Related Topics Design


//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
    struct Node {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key, int val, Node *prev, Node *next)
                : key(key), val(val), prev(prev), next(next) {}
    };

    unordered_map<int, Node*> m;
    Node *head;
    Node *tail;
    int capacity;
    int size;

public:
    explicit LRUCache(int capacity)
            : head(new Node(0, 0, nullptr, nullptr))
            , tail(new Node(0, 0, nullptr, nullptr))
            , capacity(capacity)
            , size(0) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.count(key) == 0) {
            return -1;
        }
        to_front(key);
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if (m.count(key) == 0) {
            push_front(key, value);
            if (size++ == capacity) {
                pop_back();
            }
        } else {
            m[key]->val = value;
            to_front(key);
        }
    }

    void to_front(int const key) {
        m[key]->prev->next = m[key]->next;
        m[key]->next->prev = m[key]->prev;
        m[key]->next = head->next;
        m[key]->prev = head;
        head->next->prev = m[key];
        head->next = m[key];
    }

    void push_front(int key, int value) {
        m[key] = new Node(key, value, head, head->next);
        head->next->prev = m[key];
        head->next = m[key];
    }

    void pop_back() {
        auto removed = tail->prev;
        removed->prev->next = tail;
        tail->prev = removed->prev;
        m.erase(removed->key);
        delete removed;
        --size;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestLRUCache, testcase) {
    auto cache = LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    ASSERT_EQ(cache.get(1), 1);
    cache.put(3, 3);    // evicts key 2
    ASSERT_EQ(cache.get(2), -1);
    cache.put(4, 4);    // evicts key 1
    ASSERT_EQ(cache.get(1), -1);
    ASSERT_EQ(cache.get(3), 3);
    ASSERT_EQ(cache.get(4), 4);
}
