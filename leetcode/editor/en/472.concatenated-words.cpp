#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Given a list of words (without duplicates), please write a program that return
//s all concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of at l
//east two shorter words in the given array. 
//
// Example: 
// 
//Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","
//ratcatdogcat"]
//
//Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//
//Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";  "
//dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat" can b
//e concatenated by "rat", "cat", "dog" and "cat".
// 
// 
//
// Note: 
// 
// The number of elements of the given array will not exceed 10,000 
// The length sum of elements in the given array will not exceed 600,000. 
// All the input string will only include lower case letters. 
// The returned elements order does not matter. 
// 
// Related Topics Dynamic Programming Depth-first Search Trie


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
#define I(c) (c - 'a')
    struct node {
        bool is_end{false};
        node *next[26]{};
    };
    node *root;

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        root = new node();
        sort(words.begin(), words.end(),
             [](string const &lhs, string const &rhs) {
                 if (lhs.size() == rhs.size()) return lhs < rhs;
                 return lhs.size() < rhs.size();
             });

        auto ans = vector<string>();
        for (auto const& word : words) {
            if (match(word))
                ans.push_back(word);
            insert(word);
        }
        return ans;
    }

    bool match(string const& word, int start=0) {
        if (start == word.size()) return start != 0;

        auto curr = root;
        for (auto i = start; i < word.size(); ++i) {
            auto const c = word[i];
            curr = curr->next[I(c)];
            if (curr == nullptr) return false;
            if (curr->is_end) {
                if (match(word, i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    void insert(string const& word) {
        auto curr = root;
        for (auto const c : word) {
            if (curr->next[I(c)] == nullptr)
                curr->next[I(c)] = new node();
            curr = curr->next[I(c)];
        }
        curr->is_end = true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

class ACAutoMachine {
#define I(c) (c - 'a')
    struct node {
        bool is_end{false};
        node *next[26]{};
        node *fail{nullptr};

        explicit node(node *fail = nullptr) : fail(fail) {}
    };
    node *root;

public:
    void insert(vector<string> &words) {
        root = new node();
        auto ans = vector<string>();
        for (auto const &word : words) {
            if (match(word)) {
                ans.push_back(word);
            }
            insert(word);
        }
    }

    void insert(string const &word) {
        auto curr = root;
        auto fail = curr;
        for (auto const c : word) {
            if (curr->next[I(c)] == nullptr) {
                curr->next[I(c)] = new node(match_next(c, fail));
            }
            curr = curr->next[I(c)];
            fail = curr->fail;
        }
        curr->is_end = true;
    }

    bool match(string const &word) {
        auto curr = root;
        for (auto const c : word) {
            curr = match_next(c, curr);
            if (curr->is_end) {
                return true;
            }
        }
        return false;
    }

    node *match_next(char const c, node *curr) {
        while (curr->next[I(c)] == nullptr && curr->fail != nullptr) {
            curr = curr->fail;
        }
        return curr->next[I(c)] == nullptr ? root : curr->next[I(c)];
    }

};

TEST(TestLowestCommonAncestorOfABinarySearchTree, testcase) {
    auto sol = Solution();

    auto cases = vector<tuple<vector<string>, vector<string>>>{
            {{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"}, {"dogcatsdog", "catsdogcats", "ratcatdogcat"}},
            {{"adadac", "adac"}, {}},
    };

    for (auto &c : cases) {
        cout << "testing " << c << "..." << endl;
        auto result = sol.findAllConcatenatedWordsInADict(get<0>(c));
        auto expect = get<1>(c);
        ASSERT_EQ(result, expect);
    }
}
