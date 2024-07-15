class SegmentTree{
public:
    int start,end,sum;
    SegmentTree* left;
    SegmentTree* right;

    SegmentTree(int start,int end){
        this->start = start;
        this->end = end;
        this->left = NULL;
        this->right = NULL;
        this->sum = 0;
    }
};

class NumArray {
    SegmentTree* root=NULL;

public:
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        updateRec(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRangeRec(root, left, right);
    }

    SegmentTree* buildTree(vector<int> &nums,int s,int e){
        if(s>e) return NULL;
        
        else{
            SegmentTree* ret = new SegmentTree(s,e);
            if(s == e) ret->sum = nums[s];
            
            else{
                int mid = s + ((e-s)>>1);
                
                ret->left = buildTree(nums, s, mid);
                ret->right = buildTree(nums, mid+1, e);
                ret->sum = ret->left->sum + ret->right->sum;
            }
            return ret;
        }
    }
        
    void updateRec(SegmentTree* root,int pos,int val){
        if(root->start == root->end) root->sum = val;
        
        else{
            int mid = root->start + ((root->end - root->start)>>1);
            
            if(pos <= mid)
                updateRec(root->left, pos, val);

            else
                updateRec(root->right, pos,val);
            
            root->sum = root->left->sum + root->right->sum;
        }
    }
    
    int sumRangeRec(SegmentTree* root,int start,int end){
        if(root->end == end && root->start == start)
            return root->sum;
        
        else{
            int mid = root->start + ((root->end - root->start)>>1);
            
            if(end<=mid)
                return sumRangeRec(root->left,start,end);
            
            else if(start>=mid+1)
                return sumRangeRec(root->right,start,end);
            
            else
                return sumRangeRec(root->right,mid+1,end) + sumRangeRec(root->left,start,mid);
            
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */