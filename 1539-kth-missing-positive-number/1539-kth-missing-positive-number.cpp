class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int i=1;
        while(k){
            if(binary_search(arr.begin(), arr.end(), i++)==false){
                k--;
            }
        }
        
        return i-1;
        
    }
};