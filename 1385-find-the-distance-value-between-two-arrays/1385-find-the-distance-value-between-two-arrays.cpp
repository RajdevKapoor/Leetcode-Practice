class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(),arr1.end());
        long ans = 0;
        sort(arr2.begin(), arr2.end());
        for(int i = 0; i<size(arr1); i++){
            long long start = 0, end = arr2.size()-1;
            int ok = 0;
            while(start<=end){
                long long mid = (end-start)/2 + start;
                if(abs(arr2[mid]-arr1[i])<=d){
                    ok++; 
                    break;
                } else if(arr2[mid]>arr1[i]){
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            }
            if(!ok) ans++;
        }
        return ans;
    }
};