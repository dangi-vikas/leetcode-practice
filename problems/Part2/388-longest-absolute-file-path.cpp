class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> len;
        len.push_back(0);
        int ans = 0;
        
        while(input != "\0"){
            int pos = 1;
            int end = input.find('\n');
            
            if(end == -1) end = input.size();
            
            int start = 0;
            
            while(start<end && input[start]=='\t'){
                start++;
                pos++;
            }
            
            if(input.substr(start,end).find('.')!=-1){
                if(len[pos-1] + end - start + pos-1 > ans)
                    ans = len[pos-1] + end - start + (pos-1);
            }
            
            else{
                if(len.size() > pos) 
                    len[pos] = len[pos-1] + end - start;
                else len.push_back(len[pos-1] + end - start);
            }
            
            if(input.find('\n') != -1)
                input = input.substr(end+1);
            else
                input = "\0";
        }
        
        return ans;
    }
};