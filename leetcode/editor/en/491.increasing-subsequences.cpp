#include "base.h"
//Given an integer array nums, return all the different possible increasing subs
//equences of the given array with at least two elements. You may return the answe
//r in any order. 
//
// The given array may contain duplicates, and two equal integers should also be
// considered a special case of increasing sequence. 
//
// 
// Example 1: 
//
// 
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// 
//
// Example 2: 
//
// 
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 15 
// -100 <= nums[i] <= 100 
// 
// Related Topics Depth-first Search 
// 👍 978 👎 136


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int> const& nums) {
        auto res = vector<vector<int>>();
        auto mem = unordered_set<int>();
        auto hash = vec_hash();

        auto fn_push_into = [&](vector<int> && v) {
            auto const hash_v = hash(v);
            if (mem.find(hash_v) == mem.end()) {
                mem.insert(hash_v);
                res.push_back(std::move(v));
            }
        };

        for (auto const num : nums) {
            auto new_res = vector<vector<int>>();
            for (auto const & sub : res) {
                if (num >= sub.back()) {
                    auto copied = sub;
                    copied.push_back(num);
                    new_res.push_back(std::move(copied));
                }
            }

            for (auto & sub : new_res) {
                fn_push_into(std::move(sub));
            }
            fn_push_into({num});
        }

        auto real_res = vector<vector<int>>();
        for (auto & sub : res) {
            if (sub.size() > 1) {
                real_res.push_back(std::move(sub));
            }
        }
        return real_res;
    }

private:
    struct vec_hash {
        std::size_t operator()(std::vector<int> const& vec) const {
            std::size_t seed = vec.size();
            for(auto const& i : vec) {
                seed ^= i + 0x9e3779b9 + (seed << 6u) + (seed >> 2u);
            }
            return seed;
        }
    };

};
//leetcode submit region end(Prohibit modification and deletion)
