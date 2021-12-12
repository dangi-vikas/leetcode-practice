class Twitter {
    map<int, set<int>> adjList;
    
    struct Tweet{
    public:
        int uID, tweetID;
        
        Tweet(int _uID, int _tweetID){
            uID = _uID, 
            tweetID = _tweetID; 
        }
    };
    
    vector<Tweet> tweet;
    
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet.push_back(Tweet(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        adjList[userId].insert(userId);
        set<int> flw = adjList[userId];
        vector<int> ret;

        for(int i = tweet.size()-1; i>=0; i--){
            if(flw.find(tweet[i].uID) != flw.end()) ret.push_back(tweet[i].tweetID);
            if(ret.size() == 10) break;
        }
        
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        adjList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        adjList[followerId].erase(followeeId);
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