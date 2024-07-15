class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        return maxApproved(n, requests, 0, 0);
    }

    int maxApproved(int n, vector<vector<int>>& requests, int ind, int approvedReq) {
        if(ind == requests.size()) {
            vector<int> building(n, 0);
            int ans = 0;

            for(int i=0; i<requests.size(); i++) {
                if(approvedReq & (1<<i)) {
                    building[requests[i][0]]--;
                    building[requests[i][1]]++;
                    ans++;
                }
            }

            for(int i=0; i<building.size(); i++) 
                if(building[i] != 0) return 0;

            return ans;
        }

        int approve = 0, notApprove = 0, prev = approvedReq;

        approvedReq |= (1 << ind);
        approve = maxApproved(n, requests, ind+1, approvedReq);
        approvedReq = prev;
        notApprove = maxApproved(n, requests, ind+1, approvedReq);

        return max(approve, notApprove);
    }
};