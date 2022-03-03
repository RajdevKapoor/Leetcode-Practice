class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        int obsp=0, ossp=0, ocsp=0;
        int nbsp=0, nssp=0, ncsp=0;
        
        obsp= ocsp - prices[0];
        
        for(int i=1;i<n;i++){
            
            if(ocsp - prices[i]> obsp){
                nbsp = ocsp-prices[i];
            }else{
                nbsp=obsp;
            }
            
            if(obsp+prices[i]>ossp){
                nssp=obsp+prices[i];
            }else{
                nssp=ossp;
            }
            
            if(ossp>ocsp){
                ncsp=ossp;
            }else{
                ncsp=ocsp;
            }
            
            obsp=nbsp;
            ossp=nssp;
            ocsp=ncsp;
            
            
        }
        
        return ossp;
        
    }
};