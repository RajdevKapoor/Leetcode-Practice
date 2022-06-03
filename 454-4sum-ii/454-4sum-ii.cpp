class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int count =0;
        unordered_map <int,int> mp;
        
        for(int a:nums1){
            for(int b:nums2){
                mp[a+b]++;
            }
        }
        
        for(int a:nums3){
            for(int b:nums4){
                
                if(mp.count(0-a-b)){
                    count+=mp[0-a-b];
                }
                
            }
        }
        
        return count;
        
    }
};