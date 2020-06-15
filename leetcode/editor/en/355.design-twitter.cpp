#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <gtest/gtest.h>
#include "base.h"

//Design a simplified version of Twitter where users can post post_tweets, follow/unf
//ollow another user and is able to see the 10 most recent post_tweets in the user's ne
//ws feed. Your design should support the following methods: 
//
// 
// 
// postTweet(userId, tweetId): Compose a new tweet. 
// getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news
// feed. Each item in the news feed must be posted by users who the user followed 
//or by the user herself. Tweets must be ordered from most recent to least recent.
// 
// follow(followerId, followeeId): Follower follows a followee. 
// unfollow(followerId, followeeId): Follower unfollows a followee. 
// 
// 
//
// Example:
// 
//Twitter twitter = new Twitter();
//
//// User 1 posts a new tweet (id = 5).
//twitter.postTweet(1, 5);
//
//// User 1's news feed should return a list with 1 tweet id -> [5].
//twitter.getNewsFeed(1);
//
//// User 1 follows user 2.
//twitter.follow(1, 2);
//
//// User 2 posts a new tweet (id = 6).
//twitter.postTweet(2, 6);
//
//// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
//// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
//
//twitter.getNewsFeed(1);
//
//// User 1 unfollows user 2.
//twitter.unfollow(1, 2);
//
//// User 1's news feed should return a list with 1 tweet id -> [5],
//// since user 1 is no longer following user 2.
//twitter.getNewsFeed(1);
// 
// Related Topics Hash Table Heap Design


//leetcode submit region begin(Prohibit modification and deletion)
class Twitter {
    map<int, vector<int>> post_tweets;
    vector<pair<int, int>> feed_tweets;
    map<int, set<int>> follows;

public:
    /** Initialize your data structure here. */
    Twitter() = default;
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        prepare(userId);

        post_tweets[userId].push_back(tweetId);
        feed_tweets.emplace_back(userId, tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        prepare(userId);

        auto news = vector<int>();
        for (auto i = feed_tweets.rbegin(); i != feed_tweets.rend() && news.size() < 10; ++i) {
            auto authorId = i->first, tweetId = i->second;
            if (authorId == userId or is_following(userId, authorId)) {
                news.push_back(tweetId);
            }
        }
        return news;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        prepare(followerId);
        prepare(followeeId);

        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        prepare(followerId);
        prepare(followeeId);

        if (follows.count(followerId)) {
            follows[followerId].erase(followeeId);
        }
    }

private:
    void prepare(int userId) {
        if (post_tweets.count(userId) == 0) post_tweets[userId] = {};
        if (follows.count(userId) == 0) follows[userId] = {};
    }

    bool is_following(int followerId, int followeeId) {
        return follows[followerId].count(followeeId);
    }

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
//leetcode submit region end(Prohibit modification and deletion)


TEST(TestDesignTwitter, testcase) {
    auto twitter = Twitter();
    twitter.postTweet(1, 1);
    ASSERT_EQ(twitter.getNewsFeed(1), vector<int> {1});
    twitter.follow(2, 1);
    ASSERT_EQ(twitter.getNewsFeed(2), vector<int> {1});
    twitter.unfollow(2, 1);
    ASSERT_EQ(twitter.getNewsFeed(2), vector<int> {});
}
