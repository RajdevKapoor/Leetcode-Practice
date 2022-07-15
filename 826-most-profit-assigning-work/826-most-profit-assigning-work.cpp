class Solution {
public:
    static bool cmp(vector<int>a, vector<int>b){
        if(a[0]==b[0]) return a[1]<b[1];
        
        return a[0]>b[0];
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        vector<vector<int>> v(profit.size());
        
        for(int i=0;i<profit.size();i++){
            v[i]={profit[i],difficulty[i]};
        }
        
        sort(v.begin(),v.end(),cmp);
        sort(worker.rbegin(), worker.rend());
        
        int i=0, j=0;
        
        int ans=0;
        while(i<v.size() and j<worker.size()){
            if(worker[j]>=v[i][1]){
                ans+=v[i][0];
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};