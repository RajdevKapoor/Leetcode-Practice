class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> umap;
        
        int res = 0;
        for(int right = 0, left = 0, L = 0; right < n; ++right){
            ++umap[nums[right]];
            if(umap.size() < k) continue;
        
            if(umap.size() > k){
                umap.erase(nums[left++]);
                L = left;
            }
            
            while(umap[nums[left]] != 1){
                --umap[nums[left++]];
            }
            res += left - L + 1;

        }
        
        return res;
    }
};