class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        istringstream s1(version1), s2(version2);
        string token; int i;
        
        //splitting the version strings by '.' and storing in the vectors
        while(getline(s1, token, '.')) v1.push_back(stoi(token));
        while(getline(s2, token, '.')) v2.push_back(stoi(token));
        
        //comparing the version number at each index
        
        for(i=0; i<(min(v1.size(), v2.size())); i++){
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        
        if(v1.size()>v2.size())
            for(; i<v1.size(); i++)
                if(v1[i]) return 1;
        
        if(v1.size()<v2.size())
            for(; i<v2.size(); i++)
                if(v2[i]) return -1;
        
        return 0;
    }
};