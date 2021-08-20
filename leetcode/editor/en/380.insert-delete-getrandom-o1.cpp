#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Design a data structure that supports all following operations in average O(1)
// time. 
//
// 
// 
// insert(val): Inserts an item val to the set if not already present. 
// remove(val): Removes an item val from the set if present. 
// getRandom: Returns a random element from current set of elements. Each elemen
//t must have the same probability of being returned. 
// 
// 
//
// Example:
// 
//// Init an empty set.
//RandomizedSet randomSet = new RandomizedSet();
//
//// Inserts 1 to the set. Returns true as 1 was inserted successfully.
//randomSet.insert(1);
//
//// Returns false as 2 does not exist in the set.
//randomSet.remove(2);
//
//// Inserts 2 to the set, returns true. Set now contains [1,2].
//randomSet.insert(2);
//
//// getRandom should return either 1 or 2 randomly.
//randomSet.getRandom();
//
//// Removes 1 from the set, returns true. Set now contains [2].
//randomSet.remove(1);
//
//// 2 was already in the set, so return false.
//randomSet.insert(2);
//
//// Since 2 is the only number in the set, getRandom always return 2.
//randomSet.getRandom();
// 
// Related Topics Array Hash Table Design


//leetcode submit region begin(Prohibit modification and deletion)
class RandomizedSet {
    unordered_map<int, int> mem;
    vector<int> vec;
    int size;

public:
    /** Initialize your data structure here. */
    RandomizedSet() : size(0) {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mem.find(val) != mem.end()) return false;
        if (size == vec.size())
            vec.push_back(0);
        vec[size] = val;
        mem[val] = size++;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto idx = mem.find(val);
        if (idx == mem.end()) return false;
        if (size--) {
            vec[idx->second] = vec[size];
            mem[vec[size]] = idx->second;
        }
        mem.erase(idx);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[random() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestInsertDeleteGetRandomO1, testcase) {
//    auto sol = Solution();
//
//    auto cases = vector<tuple<..>>{
//            {},
//    };
//
//    for (auto & c : cases) {
//        cout << "testing " << c << "..." << endl;
//        auto result = sol.foo(get<0>(c));
//        auto expect = get<1>(c);
//        ASSERT_EQ(result, expect);
//    }
}
