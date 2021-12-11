/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    NestedIterator* currIter;
    vector<NestedInteger> v;
    int idx;
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        currIter = NULL;
        v = nestedList;
        idx = 0;
    }
    
    int next() {
        if(!hasNext()) return -1;
        
        if(currIter) return currIter->next();
        
        return v[idx++].getInteger();
    }
    
    bool hasNext() {
         while(true){
            if(currIter && currIter->hasNext()) return true;
             
            else if(!currIter){
                if(idx >= v.size()) return false;
                if(v[idx].isInteger()) return true;
                currIter = new NestedIterator(v[idx++].getList());
            }
             
            else currIter = NULL;
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */