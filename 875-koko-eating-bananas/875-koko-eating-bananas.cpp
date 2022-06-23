class Solution {
public:
    int eatingSpeed(vector<int>& piles,int s){
        int time = 0;
        for(int i=0; i<piles.size(); i++)
        {
            int temp = piles[i]/s + (piles[i]%s > 0 ? 1:0);
            time += temp;
        }
        return time;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        int s=1;
        int e=*max_element(piles.begin(), piles.end());
        int ans=e;
        
        while(s<e){
            int mid = s + (e-s)/2;
            int result = eatingSpeed(piles,mid);
            if(result<=h){
                ans=min(result,ans);
                e=mid;
            }else{
                s=mid+1;
            }
        }
        return e;
    }
};