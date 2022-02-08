class Solution {
    unordered_map<string,string> umap;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "";
        shortUrl += (char) (rand() % 100);
        
        while(umap.find(shortUrl) != umap.end())
             shortUrl += (char) (rand() * 100);
        
        umap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return umap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));