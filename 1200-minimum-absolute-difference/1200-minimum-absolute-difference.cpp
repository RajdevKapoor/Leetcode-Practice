class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        
        int dsf = INT_MAX;
        vector<vector<int>> ans;
        
        for(int i=0;i<arr.size()-1;i++){
            int diff = arr[i+1]-arr[i];
            
            if(diff == dsf){
                ans.push_back({arr[i],arr[i+1]});
            }else if(diff<dsf){
                dsf=diff;
                ans.clear();
                ans.push_back({arr[i],arr[i+1]});
            }
        }
       return ans; 
    }
};