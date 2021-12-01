/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int nextElement;
    
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    nextElement = -1;
        if (Iterator :: hasNext()) {
            nextElement = Iterator::next();
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextElement;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int prevNextElement = nextElement;
        nextElement = -1;
        
        if (Iterator::hasNext()) {
            nextElement = Iterator::next();
        }
        
        return prevNextElement;
	}
	
	bool hasNext() const {
	    return (nextElement != -1);
	}
};