class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans, curr;
        int numOfLetters = 0;

        for (string word : words) {
            if (word.size() + curr.size() + numOfLetters > maxWidth) {
                for (int i = 0; i < maxWidth - numOfLetters; i++) 
                    curr[i % (curr.size() - 1 ? curr.size() - 1 : 1)] += ' ';

                ans.push_back("");

                for (string s : curr) ans.back() += s;

                curr.clear();
                numOfLetters = 0;
            }

            curr.push_back(word);
            numOfLetters += word.size();
        }

        string lastLine = "";
        
        for(string s : curr) lastLine += s + ' ';

        lastLine = lastLine.substr(0, lastLine.size() - 1); 

        while(lastLine.size() < maxWidth) lastLine += ' ';

        ans.push_back(lastLine);

        return ans;
    }
};s