class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans;
    
    int xor2 = 0;
    for(int i=0;i<n;i++){
        xor2 ^= nums[i];
    }
    
    int cnt = 0;
    while(xor2){
        if(xor2 & 1){
            break;
        }
        cnt++;
        xor2= xor2 >> 1;
    }
    int xor1 = 0, xor0 = 0;
    for(int i=0;i<n;i++){
        if(nums[i] & (1<<cnt)){
            xor1 ^=nums[i];
        }
        else{
            xor0 ^= nums[i];
        }
    }
    
    ans.push_back(xor1);
    ans.push_back(xor0);
    
    return ans;
}
};