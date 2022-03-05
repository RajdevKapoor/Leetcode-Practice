class Solution {
public:
    double average(vector<int>& salary) {
        
        double n=salary.size()-2;
      
        
        int maxi=INT_MIN, mini = INT_MAX;
        
        int sum=0;
        
        for(auto x: salary){
            sum+= x;
            maxi=max(x,maxi);
            mini=min(x,mini);
        }
        
        
        return (sum-(maxi+mini))/n;
        
    }
};