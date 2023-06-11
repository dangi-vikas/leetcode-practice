class SnapshotArray {
    int snapId;
    vector<vector<pair<int, int>>> history;

public:
    SnapshotArray(int length) {
        snapId = -1;
        history.resize(length);

        for(int i=0; i<length; i++) 
            history[i].push_back({snapId, 0});
    }
    
    void set(int index, int val) {
        history[index].push_back({snapId, val});
    }
    
    int snap() {
        return ++snapId;
    }
    
    int get(int index, int snap_id) {
        int low = 0, high = history[index].size() - 1;
        int ans = 0;

        while(low <= high) {
            int mid = low + ((high-low) >> 1);

            if(history[index][mid].first<snap_id) {
                ans=mid;
                low = mid+1;
            }
            else high = mid - 1;
        }
        return history[index][ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */