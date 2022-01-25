class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w;
        
        for(int i=sqrt(area); i>=1; i--){
            if(area % i == 0){
                w = i;
                break;
            }
        }
               
        return {(area/w), w};
    }
};