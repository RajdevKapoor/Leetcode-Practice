class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int water=0;
        int ans=0;
        for(int i=0 ; i<plants.size()-1 ; i++){
           water+=plants[i];
           if(water+plants[i+1]>capacity){
               water=0;
               ans+=(i+1)*2;
           }
        }

        ans+=plants.size();
        return ans;
    }
};