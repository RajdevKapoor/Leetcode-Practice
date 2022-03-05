class Solution {
public:
    int nthUglyNumber(int n) {
        
        set <long long int> s;
        s.insert(1);
        
        auto it=s.begin();
        
        int i=1;
        
        while(i<n){
            s.insert((*it)*2);
            s.insert((*it)*3);
            s.insert((*it)*5);
            
            it++;
            i++;
        }
        it = s.begin();
        advance(it, n-1);
        return *it;
        
        
    }
};