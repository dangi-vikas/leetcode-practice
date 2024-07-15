class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if(poured == 0) return 0;
        
        vector<double> list;
        list.push_back(poured * 1.0);
        
        while(query_row--) {
            vector<double> temp;
            temp.push_back(max((list[0] - 1) / 2, 0.0));
            
            for(int i=1; i<list.size(); i++) 
                temp.push_back(max((list[i-1] - 1) / 2, 0.0) + max((list[i] - 1) / 2, 0.0));
            
            temp.push_back(temp[0]);
            list = temp;
        }
                               
        return min(1.0, list[query_glass]);
    }
};
