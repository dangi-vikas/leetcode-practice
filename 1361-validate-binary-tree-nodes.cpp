class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        int rootCount = 0;
        vector<bool> visited(n, false);
        stack<int> topSort;

        for(int i=0; i<n; i++) {
            if(leftChild[i] != -1) 
                inDegree[leftChild[i]]++;
            if(rightChild[i] != -1) 
                inDegree[rightChild[i]]++;
        }

        for(int i=0; i<n; i++) {
            if(inDegree[i] > 1) return false;

            if(inDegree[i] == 0) {
                rootCount++;
                if(rootCount > 1) return false;
            }
        }

        if(rootCount == 0) return false;

        for(int i=0; i<n; i++) 
            if(inDegree[i] == 0)
                topSort.push(i);

        while (!topSort.empty()) {
            int node = topSort.top();
            topSort.pop();

            if (visited[node])
                return false; 
           
            visited[node] = true;

            if (leftChild[node] != -1) 
                topSort.push(leftChild[node]);
            
            if (rightChild[node] != -1) 
                topSort.push(rightChild[node]);
        }

        return count(visited.begin(), visited.end(), true) == n;
    }
};