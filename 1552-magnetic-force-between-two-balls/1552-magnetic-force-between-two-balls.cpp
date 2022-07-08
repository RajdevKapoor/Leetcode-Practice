class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid){
        
        int lastPlaced = position[0];
        int placedSoFar=1;
        
        for(int i=1;i<position.size();i++){
            
            if(position[i]-lastPlaced>=mid){
                placedSoFar++;
                lastPlaced=position[i];
                if(placedSoFar>=m) return true;
            }
        }
        
        return false;
        
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s = 1;
        int e = position[position.size()-1];
        int ans;
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(isPossible(position,  m,  mid)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        
        return ans;
        
    }
};