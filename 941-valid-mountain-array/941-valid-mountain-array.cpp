class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int i=0;
        int n=arr.size();
        for(i=0;i+1<n;i++){
            if(arr[i]<arr[i+1]) continue;
            break;
        }
        
        if(i==0 or i==n-1) return false;
        
        for(;i+1<n;i++){
            if(arr[i]>arr[i+1]) continue;
            break;
        }
        
        return i==n-1;
        
        
        
        
    }
};