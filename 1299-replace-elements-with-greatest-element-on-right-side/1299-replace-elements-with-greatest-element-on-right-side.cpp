class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        vector<int> ans(arr.size(),-1);
        
        int msf = arr[arr.size()-1];
        
        for(int i=arr.size()-2;i>=0;i--){
            ans[i] = max(msf,ans[i+1]);
            msf = max(msf,arr[i]);
        }
        
        return ans;
        
    }
};