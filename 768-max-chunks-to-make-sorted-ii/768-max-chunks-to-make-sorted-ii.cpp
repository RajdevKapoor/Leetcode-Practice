class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        
        int n=a.size();
        
        vector<int> minn(n+1,INT_MAX);
        
        for(int i=n-1;i>=0;i--){
            minn[i]=min(minn[i+1],a[i]);
        }
        int ans=0;
        int msf = a[0];
        for(int i=0;i<n;i++){
            
            if(a[i]>msf){
                msf=a[i];
            }
            
            if(msf<=minn[i+1]){
                ans++;
            }
        }
        
        return ans;
        
    }
};