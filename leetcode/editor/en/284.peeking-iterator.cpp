#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given an Iterator class interface with methods: next() and hasNext(), design a
//nd implement a PeekingIterator that support the peek() operation -- it essential
//ly peek() at the element that will be returned by the next call to next(). 
//
// Example: 
//
// 
//Assume that the iterator is initialized to the beginning of the list: [1,2,3].
//
//
//Call next() gets you 1, the first element in the list.
//Now you call peek() and it returns 2, the next element. Calling next() after t
//hat still return 2. 
//You call next() the final time and it returns 3, the last element. 
//Calling hasNext() after that should return false.
// 
//
// Follow up: How would you extend your design to be generic and work with all t
//ypes, not just integer? 
// Related Topics Design

class Iterator {
public:
    struct Data;
    Data *data;

    Iterator(const vector<int> &nums);

    Iterator(const Iterator &iter);

    virtual // Returns the next element in the iteration.
    int next();

    virtual // Returns true if the iteration has more elements.
    bool hasNext() const;
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int peeked;
    int has_peeked;

public:
    PeekingIterator(const vector<int> &nums)
            : Iterator(nums), peeked(0), has_peeked(false) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (has_peeked) return peeked;
        has_peeked = true;
        return peeked = Iterator::next();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() override {
        if (has_peeked) {
            has_peeked = false;
            return peeked;
        }
        return Iterator::next();
    }

    [[nodiscard]] bool hasNext() const override {
        if (has_peeked) return true;
        return Iterator::hasNext();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestPeekingIterator, testcase) {
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
