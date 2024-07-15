class BinaryIndexedTreeNode {
public:
    int N;
    vector<int> Tree;
    
    BinaryIndexedTreeNode(int _N) : N(_N + 1), Tree(N, 0) {}
    
    int query(int i) {
        int ans = 0;
        
        while (i > 0) {
           ans += Tree[i];
           i -= i & -i;
        }
        
        return ans;
    }
    
    void update(int i, int x) {
        i++;
        
        while (i < N) {
           Tree[i] += x;
           i += i & -i;
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = int(nums.size());
        vector<int> ans(N);
        int mx = 1e4; 
        BinaryIndexedTreeNode node(mx * 2);

        for (int i=N-1; i>=0; i--) {
            ans[i] = node.query(nums[i] + mx);
            node.update(nums[i] + mx, 1);
        }

        return ans;
    }
};