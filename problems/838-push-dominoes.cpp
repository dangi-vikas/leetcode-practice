class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> left(n), right(n);
        int nearestLeftIndex = -1, nearestRightIndex = -1;
        string ans;
        
        for(int i=n-1; i>=0; i--) {
            if(dominoes[i] == 'L') nearestLeftIndex = i;
            else if(dominoes[i] == 'R') nearestLeftIndex = -1;
            left[i] = nearestLeftIndex;
        }
        
        for(int i=0; i<n; i++) {
            if(dominoes[i] == 'R') nearestRightIndex = i;
            else if(dominoes[i] == 'L') nearestRightIndex = -1;
            right[i] = nearestRightIndex;
        }
        
        for(int i=0; i<n; i++) {
            if(dominoes[i] == '.') {
                int leftDiff = left[i] == -1 ? INT_MAX : abs(left[i] - i);
                int rightDiff = right[i] == -1 ? INT_MAX : abs(right[i] - i);

                if(leftDiff == rightDiff) ans.push_back('.');
                else if(leftDiff > rightDiff) ans.push_back('R');
                else if(leftDiff < rightDiff) ans.push_back('L');
            }
            
            else ans.push_back(dominoes[i]);
        }
        
        return ans;
    }
};