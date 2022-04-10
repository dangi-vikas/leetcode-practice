class UnionFind {
    vector<int> parent;
    vector<int> rank;
    
public:
    int groupCount;
    
    UnionFind(int n) : groupCount(n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
    }
    
    void init(int x) {
        parent[x] = x;
    }
    
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unify(int x, int y) {
        int xSet = find(x);
        int ySet = find(y);
        
        if(xSet == ySet) return;
        groupCount--;
        
        if(rank[xSet] < rank[ySet]) parent[xSet] = ySet;
        else if (rank[xSet] > rank[ySet]) parent[ySet] = xSet;
        else {
            parent[ySet] = xSet;
            rank[xSet] = rank[ySet] + 1;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int size = accounts.size();
        UnionFind uf(size);
        
        unordered_map<string, int> email2AccountIdx;
        
        for(int i=0; i<size; i++) {
            uf.init(i);
            
            for(int j=1; j<accounts[i].size(); j++) {
                if (email2AccountIdx.find(accounts[i][j]) == email2AccountIdx.end())
                    email2AccountIdx[accounts[i][j]] = i;
                else uf.unify(i, email2AccountIdx.find(accounts[i][j])->second);
            }
        }
        
        int mergedAccountsCount = uf.groupCount;
        vector<vector<string>> mergedAccounts(mergedAccountsCount);
        unordered_map<int, int> groupId2Idx;
        int nextIdx = 0;
        
        for(auto &pair : email2AccountIdx) {
            const string &email = pair.first;
            int groupId = uf.find(pair.second);
            auto iter = groupId2Idx.find(groupId);
            
            if(iter == groupId2Idx.end()) {
                groupId2Idx[groupId] = nextIdx;
                string &name = accounts[groupId][0];
                mergedAccounts[nextIdx].push_back(name);
                mergedAccounts[nextIdx].push_back(email);
                nextIdx++;
            }
            
            else mergedAccounts[iter->second].push_back(email);
        }
        
        for(int i=0; i<mergedAccountsCount; i++) {
            vector<string> &email = mergedAccounts[i];
            sort(email.begin()+1, email.end());
        }
        
        return mergedAccounts;
    }
};