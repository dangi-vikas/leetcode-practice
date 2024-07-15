class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int distance1 = 0, distance2 = 0;
        
        if(start > destination){
            int temp = start;
            start = destination;
            destination = temp;
        }
        
        for(int i=0; i<distance.size(); i++){
            if(i >= start && i < destination) distance1 += distance[i];
            else distance2 += distance[i];
        }
        
        return distance1 < distance2 ? distance1 : distance2;
    }
};