class Solution {
public:
    bool checkPowersOfThree(int n) {
        
        if(n==1) return true;
        
        unordered_set <int> s;
        
        while(n>0){
            
            int log= (int)(log10(n)/log10(3));
            if(s.find(log)!=s.end()){
                return false;
            }
            s.insert(log);
            
            n -= pow(3,log);
            if(n==0){
                return true;
            }
        }
        
        for(auto x:s){
            cout<<x<<" ";
        }
        
        return false;
        
        
    }
};