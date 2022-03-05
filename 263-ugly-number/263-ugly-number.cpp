class Solution {
public:
    bool isUgly(int n) {
        
        if(n==0) return false;
        int k=2;
        while(n%k==0){
            n=n/k;
        }
        
        
        k=3;
        while(n%k==0){
            n=n/k;
        }
        
        k=5;
        while(n%k==0){
            n=n/k;
        }
        
        return n==1;
    }
};