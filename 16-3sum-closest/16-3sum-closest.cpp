class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        int ans = a[0]+a[1]+a[2];
        
        
        for(int i=0;i<a.size();i++){
            int l = i+1;
            int r = a.size()-1;
            
            while(l<r){
                int sum = a[i]+a[l]+a[r];
                
                if(sum==target){
                    return target;
                }else if(sum > target){
                    
                    if(abs(target-ans)>abs(target-sum)){
                        ans=sum;
                    }
                    
                    r--;
                }else{
                    
                    if(abs(target-ans)>abs(target-sum)){
                        ans=sum;
                    }
                    
                    l++;
                }
            }
        }
        
        return ans;
        
    }
};