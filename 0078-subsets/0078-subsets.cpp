class Solution {
public: 
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> answer;
        int n = pow(2,nums.size()) - 1; // total number of subsets
        
        for(int cnt = 0; cnt <= n; cnt++){
            int temp = cnt;
            vector<int> aux; //auxilliary vector
            int i = 0;
            while(temp){
                if(temp & 1)
                    aux.push_back(nums[i]);
                temp = temp>>1;
                i++;
            }
            answer.push_back(aux);
        }
        return answer;
    }
};