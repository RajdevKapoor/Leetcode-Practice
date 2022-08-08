class Solution {
public:
    bool solve(vector<int>& arr, int i,vector<bool> &vis){
        
       
        
        if(i<0 or i>=arr.size() or vis[i]) return false;
        
        if(arr[i]==0) return true;
        
        vis[i]=true;
        
        return solve(arr,i-arr[i],vis) or solve(arr,i+arr[i],vis);
        
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(),false);
        return solve(arr,start,vis);
    }
};