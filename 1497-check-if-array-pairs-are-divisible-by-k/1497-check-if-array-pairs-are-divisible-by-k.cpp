class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        if(arr.size() &1 ){
            return false;
        }
        
        vector <int> hash (k,0);
        
        for(auto x: arr){
            hash[(x%k + k)%k]++;
        }
        
        int i=1;
        int j=k-1;
        
        if(hash[0]&1){
            return false;
        }
        
        
        for(int i=1;i<=k/2;i++){
            if(hash[i] != hash[k-i]){
                return false;
            }
        }
        return true;
        
        
        
    }
};