class Solution {
public:
    int minCost(string s, vector<int>& c) {
        
        int n = s.length();

        int cost=0;

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                if(c[i]>c[i+1]){
                   swap(c[i],c[i+1]);
                }
                cost+=c[i];
            }
        }

        return cost;
        
    }
};