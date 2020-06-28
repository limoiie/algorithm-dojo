cmake_minimum_required(VERSION 3.15)
project(algorithm_dojo)

set(CMAKE_CXX_STANDARD 20)

add_executable(algorithm_dojo
        main.cpp
        pretty_print.h
        base.h
        binary_search.h
        binary_search.cpp
        template_matrix.h
#        2.add-two-numbers.cpp
#        116.populating-next-right-pointers-in-each-node.cpp
#        117.populating-next-right-pointers-in-each-node-ii.cpp
#        119.pascals-triangle-ii.cpp
#        124.binary-tree-maximum-path-sum.cpp
#        125.valid-palindrome.cpp
#        129.sum-root-to-leaf-numbers.cpp
#        132.palindrome-partitioning-ii.cpp
#        138.copy-list-with-random-pointer.cpp
#        146.lru-cache.cpp
#        187.repeated-dna-sequences.cpp
#        224.basic-calculator.cpp
#        226.invert-binary-tree.cpp
#        227.basic-calculator-ii.cpp
#        229.majority-element-ii.cpp
#        230.kth-smallest-element-in-a-bst.cpp
#        231.power-of-two.cpp
#        232.implement-queue-using-stacks.cpp
#        233.number-of-digit-one.cpp
#        234.palindrome-linked-list.cpp
#        235.lowest-common-ancestor-of-a-binary-search-tree.cpp
#        236.lowest-common-ancestor-of-a-binary-tree.cpp
#        237.delete-node-in-a-linked-list.cpp
#        240.search-a-2d-matrix-ii.cpp
#        241.different-ways-to-add-parentheses.cpp
#        242.valid-anagram.cpp
#        273.integer-to-english-words.cpp
#        274.h-index.cpp
#        275.h-index-ii.cpp
#        278.first-bad-version.cpp
#        282.expression-add-operators.cpp
#        284.peeking-iterator.cpp
#        292.nim-game.cpp
#        299.bulls-and-cows.cpp
#        321.create-maximum-number.cpp
#        327.count-of-range-sum.cpp
#        329.longest-increasing-path-in-a-matrix.cpp
#        330.patching-array.cpp
#        352.data-stream-as-disjoint-intervals.cpp
#        354.russian-doll-envelopes.cpp
#        355.design-twitter.cpp
#        357.count-numbers-with-unique-digits.cpp
#        363.max-sum-of-rectangle-no-larger-than-k.cpp
#        365.water-and-jug-problem.cpp
#        367.valid-perfect-square.cpp
#        368.largest-divisible-subset.cpp
#        371.sum-of-two-integers.cpp
#        372.super-pow.cpp
#        373.find-k-pairs-with-smallest-sums.cpp
#        374.guess-number-higher-or-lower.cpp
#        375.guess-number-higher-or-lower-ii.cpp
#        378.kth-smallest-element-in-a-sorted-matrix.cpp
#        380.insert-delete-getrandom-o1.cpp
#        392.is-subsequence.cpp
#        410.split-array-largest-sum.cpp
#        414.third-maximum-number.cpp
#        446.arithmetic-slices-ii-subsequence.cpp
#        467.unique-substrings-in-wraparound-string.cpp
#        472.concatenated-words.cpp
#        485.max-consecutive-ones.cpp
#        495.teemo-attacking.cpp
#        516.longest-palindromic-subsequence.cpp
#        517.super-washing-machines.cpp
#        523.continuous-subarray-sum.cpp
#        532.k-diff-pairs-in-an-array.cpp
#        552.student-attendance-record-ii.cpp
#        560.subarray-sum-equals-k.cpp
#        561.array-partition-i.cpp
#        565.array-nesting.cpp
#        566.reshape-the-matrix.cpp
#        576.out-of-boundary-paths.cpp
#        581.shortest-unsorted-continuous-subarray.cpp
#        600.non-negative-integers-without-consecutive-ones.cpp
        605.can-place-flowers.cpp
#        611.valid-triangle-number.cpp
#        638.shopping-offers.cpp
#        647.palindromic-substrings.cpp
#        673.number-of-longest-increasing-subsequence.cpp
#        688.knight-probability-in-chessboard.cpp
#        689.maximum-sum-of-3-non-overlapping-subarrays.cpp
#        691.stickers-to-spell-word.cpp
#        714.best-time-to-buy-and-sell-stock-with-transaction-fee.cpp
#        718.maximum-length-of-repeated-subarray.cpp
#        730.count-different-palindromic-subsequences.cpp
#        740.delete-and-earn.cpp
#        741.cherry-pickup.cpp
#        746.min-cost-climbing-stairs.cpp
#        1349.maximum-students-taking-exam.cpp
        )

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(algorithm_dojo
        PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

add_test(AllTestsInMain algorithm_dojo)
