class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> smap,hmap;   
        for(int num : nums) smap[num]++;
        for(int num : nums){
            if(smap[num]==0) continue;     
            smap[num]--;                 
            if(hmap[num-1]>0){       
                hmap[num-1]--;    
                hmap[num]++;     
            }
            else if(smap[num+1]>0 && smap[num+2]>0){
                    smap[num+1]--;          
                    smap[num+2]--;    
                    hmap[num+2]++;         
                }
            else return false;       
        }
        return true;                       
    }
};