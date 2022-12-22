class Solution {
    vector<int> ans, count;
    vector<unordered_set<int>> tree;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans = vector<int>(n);
        count = vector<int>(n);
        tree = vector<unordered_set<int>>(n);
        
        vector<vector<int>> adjList(n);

        for(int i=0; i<edges.size(); i++) {
            tree[edges[i][0]].insert(edges[i][1]);
            tree[edges[i][1]].insert(edges[i][0]);
        }

        postOrder(0, -1);
        preOrder(0, -1);

        return ans;
    }

    void postOrder(int root, int pre) {
        for(int child : tree[root]) {
            if(child == pre) continue;
            postOrder(child, root);
            count[root] += count[child];
            ans[root] += ans[child] + count[child];
        }

        count[root]++;
    }

    void preOrder(int root, int pre) {
        for(int nbr : tree[root]) {
            if(nbr == pre) continue;
            ans[nbr] = ans[root] - count[nbr] + count.size() - count[nbr];
            preOrder(nbr, root);
        }
    }
};