class Solution {
public:
    vector<int> bh;
    
    bool check(long a){
        
        vector<int> ah(10,0);
        
        
        while(a){
            ah[a%10]++;
            a /= 10;
        }
        
        
        
        for(int i = 0 ; i < 10 ; i++){
            
            if(ah[i] != bh[i])
                return false;
            
        }
        
        return true;
    }
    
    bool reorderedPowerOf2(int n) {
        
        bh.resize(10,0);
        
        while(n){
            bh[n%10]++;
            n /= 10;
        }
        
        for(int i = 0 ; i < 31 ; i++){
            
            long num = pow(2,i);
            
            if(check(num))
                return true;
            
        }
        
        return false;
    }
};