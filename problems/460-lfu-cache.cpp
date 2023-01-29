class LFUCache {
    unordered_map<int, pair<int, int>> avlKeys;
    unordered_map<int, list<int>> freqBucket;
    unordered_map<int, list<int>::iterator> keyPos;

    int currSize = 0, totalCap = 0, minFreq = 0;

public:
    LFUCache(int capacity) {
        currSize = 0;
        totalCap = capacity;
    }
    
    int get(int key) {
        if (avlKeys.find(key) == avlKeys.end()) 
            return -1;

        int currFreq = avlKeys[key].second;

        freqBucket[currFreq].erase(keyPos[key]);

        avlKeys[key].second++;

        int newFreq = avlKeys[key].second;

        freqBucket[newFreq].push_back(key);

        keyPos[key] = --freqBucket[newFreq].end();

        if (freqBucket[minFreq].empty())
            minFreq++;

        return avlKeys[key].first;
    }
    
    void put(int key, int value) {
        if (totalCap == 0) return;

        int prevValue = get(key);

        if (prevValue != -1) {
            avlKeys[key].first = value;
            return;
        }

        if (currSize >= totalCap) {
            int lrKey = freqBucket[minFreq].front();  

            avlKeys.erase(lrKey);
            keyPos.erase(lrKey);
            freqBucket[minFreq].pop_front();
            currSize--;
        }

        avlKeys[key] = {value, 1};
        minFreq = 1;
        freqBucket[minFreq].push_back(key);
        keyPos[key] = --freqBucket[minFreq].end();
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */