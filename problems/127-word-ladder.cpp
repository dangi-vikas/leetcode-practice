class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
		unordered_set<string> dict; for (string s : wordList) dict.insert(s);
        
		if (!dict.count(endWord)) return 0;
        
		int totalWords = wordList.size();
		int totalChars = wordList[0].size();
		vector<unordered_set<char>> chars(totalChars);

		for (int i = 0; i < totalChars; ++i)
			for (int j = 0; j < totalWords; ++j)
				chars[i].insert(wordList[j][i]);
        
		queue<string> q;
		q.push(beginWord);
		int steps = 1;
        
		while (!q.empty()) {
			++steps;
			int qSize = q.size();
            
			for (int i = 0; i < qSize; ++i) {
				for (int j = 0; j < totalChars; ++j) {
					for (char c : chars[j]) {
						string copyString = q.front();
						copyString[j] = c;
						
                        if (dict.count(copyString) && !visited.count(copyString)) {
							if (copyString == endWord) return steps;
							visited.insert(copyString);
							q.push(copyString);
						}
					}
                }
                
				q.pop();
			}
		}
        
		return 0;
    }
};