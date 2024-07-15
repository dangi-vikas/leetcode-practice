
class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int c) {
        priority_queue<pair<int,int>>pq;
        map<int,int>m;

        for(int i=0;i<c;i++){
            m[i]++;
            pq.push({-cost[i],1});
        }

        int i=cost.size()-1;

        for(int j=0;j<c;j++){
            if(m[i]==0){
                m[i]++;
                pq.push({-cost[i],0});
                i--;
            }
            else break;
        }

        int l = c;
        int r = cost.size()-1-c;
        long long ans=0;

        for(int j=0;j<k;j++){
            ans += abs(pq.top().first);
            int h = pq.top().second;
            pq.pop();
            if(h){
                if(m[l]==0 && l<cost.size()){
                    m[l]++;
                    pq.push({-cost[l],1});
                    l++;
                }
            } 

            else{
                 if(m[r]==0 && r>=0){
                    m[r]++;
                    pq.push({-cost[r],0});
                    r--;
                }
            }
        }

        return ans;
    }
};
