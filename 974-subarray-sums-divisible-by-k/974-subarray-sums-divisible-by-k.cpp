class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map <int,int> map;
        map[0]=1;
        
        int CurrSum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            CurrSum+=nums[i];
            
            if(map.find((CurrSum%k+k)%k) != map.end()){
                count += (map[(CurrSum%k+k)%k]);
            }
            map[(CurrSum%k+k)%k]++;
            
        }
        
        return count;
    }
};