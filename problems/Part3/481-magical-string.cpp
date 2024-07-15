 class Solution {
public:
    int magicalString(int n) {
        string magic = "122";
        int indexCount = 2;
        char lastNum = '2';
        
        while(magic.size() < n){
            int count = magic[indexCount] - '0';
            char num = (lastNum == '1') ? '2' : '1';
            
            magic.insert(magic.end(), count, num);
            
            lastNum = num;
            indexCount++;
        }

        int ans = 0;
        for(int i=0; i<n; i++)
            if(magic[i] == '1') ans++;
        
        return ans;
    }
};