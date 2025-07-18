// Last updated: 17/07/2025, 20:52:07
class Twitter {
public:
    map<int, set<int>> followMap;
    map<int, vector<vector<int>>> tweetMap;
    int count;
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto cmp = [](const vector<int> &a , const vector<int>& b){
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);
        followMap[userId].insert(userId);
        for(auto followeeId: followMap[userId]){
            if(tweetMap.count(followeeId)){
                const vector<vector<int>> & tweets = tweetMap[followeeId];
                int index = tweets.size() -1 ;
                maxHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }
        while(!maxHeap.empty() && res.size() < 10){
            vector<int> curr = maxHeap.top();
            maxHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if(index > 0 ){
                const vector<int>& tweet = tweetMap[curr[2]][index - 1];
                maxHeap.push({tweet[0], tweet[1], curr[2], index -1 });
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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