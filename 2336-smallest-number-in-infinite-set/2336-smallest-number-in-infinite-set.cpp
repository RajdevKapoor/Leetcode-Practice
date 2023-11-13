class SmallestInfiniteSet {
public:
    set<int>s;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++){
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int smallest = *s.begin();
        s.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};