class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> wordsInt(n, 0);
        vector<int> wordsLen(n, 0);
        
        for(int i=0; i<n; i++){
            string w = words[i];
            wordsLen[i] = w.length();
            int wInt = 0;
            
            for(int j=0; j<w.length(); j++)
                wInt |= 1 << (w[j] - 'a');
            
            wordsInt[i] = wInt;
        }
        
        int maxProduct = 0;
        
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if((wordsInt[i] & wordsInt[j]) == 0)
                    maxProduct = max(maxProduct, (wordsLen[i] * wordsLen[j]));
        
        return maxProduct;
    }
};