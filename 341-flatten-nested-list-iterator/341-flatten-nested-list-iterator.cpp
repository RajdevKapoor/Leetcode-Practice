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
private:
    vector<NestedInteger>::iterator beg, end;
    NestedIterator* iter;
public:
     
    NestedIterator(vector<NestedInteger> &nestedList) {
        beg = nestedList.begin();
        end = nestedList.end();
        iter = nullptr;
    }
    
    // O(1), O(1)
    int next() {
        if (beg->isInteger()) {
            int res = beg->getInteger();
            ++beg;
            return res;
        } else {
            return iter->next();
        }
    }
        
    // O(N), O(1)
    bool hasNext() {
        if (beg != end) {
            if (beg->isInteger()) {
                return true;
            }
            
            if (!iter) {
                iter = new NestedIterator(beg->getList());
            }
            if (iter->hasNext()) {
                return true;
            }
            iter = nullptr;
            ++beg;
            return hasNext();
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */