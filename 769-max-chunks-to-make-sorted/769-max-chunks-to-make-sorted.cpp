class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        
        int max = a[0];
        int ans=0;
        
        for(int i=0;i<a.size();i++){
            if(a[i]>max){
                max=a[i];
            }
            
            if(i==max){
                ans++;
            }
        }
        
        return ans;
        
    }
};