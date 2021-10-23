class Solution {
public:

    //initialising a dp
    unordered_map<string, bool> dp;
    
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        
        return isInterleaveRec(s1, s2, s3, l1, l2, l3, 0, 0, 0);
    }
    
    bool isInterleaveRec(string s1, string s2, string s3, int l1, int l2, int l3, int p1, int p2, int p3) {
        
        //if all the 3 strings are traversed
        if(p3==l3) return (p1==l1 && p2==l2) ? true : false;
        
        string key = to_string(p1) + "*" + to_string(p2) + "*" + to_string(p3);
        
        if(dp.find(key)!=dp.end()) return dp[key];
        
        //in case if the second string is left to traverse
        if(p1==l1) 
            return dp[key] = s2[p2]==s3[p3]?isInterleaveRec(s1, s2, s3, l1, l2, l3, p1, p2+1, p3+1):false;
        
        //in case if the first string is left to traverse
        if(p2==l2) 
            return dp[key] = s1[p1]==s3[p3]?isInterleaveRec(s1, s2, s3, l1, l2, l3, p1+1, p2, p3+1):false;
        

        //in case if the both the strings are left to traverse
        bool one=false, two=false;
        if(s1[p1] == s3[p3]) 
            one = isInterleaveRec(s1, s2, s3, l1, l2, l3, p1+1, p2, p3+1);
        if(s2[p2] == s3[p3])  
            two = isInterleaveRec(s1, s2, s3, l1, l2, l3, p1, p2+1, p3+1);
        
        //if the s3 is found valid by checking of atleast one string fully
        return dp[key] = one || two;
    }
};