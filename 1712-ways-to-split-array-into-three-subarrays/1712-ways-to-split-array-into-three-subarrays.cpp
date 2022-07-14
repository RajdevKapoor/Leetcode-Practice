class Solution {
public:
    const int mod=1e9+7;
    int find_ans(int s,int e,vector<int>&prefix,int sum,int n){
        int left=s;
        int right=e;
        
        int ans=1e8;
        while(s<=e){
            int mid=(s+e)/2;
            int sum1=prefix[mid+1]-prefix[left];
            int sum2=prefix[n]-prefix[mid+1];
            if(sum1>=sum){
                if(sum1<=sum2){
                    e=mid-1;
                    ans=min(ans,mid);
                }
                else{
                    e=mid-1;
                }
            }
            else{
                s=mid+1;
            }
            
        }
        return ans;
    }
       int find_ans2(int s,int e,vector<int>&prefix,int sum,int n){
        int left=s;
        int right=e;     
         int ans=-1;
    
        while(s<=e){
            int mid=(s+e)/2;
            int sum1=prefix[mid+1]-prefix[left];
            int sum2=prefix[n]-prefix[mid+1];
            if(sum1>=sum){
                if(sum1<=sum2){
                    s=mid+1;
                    ans=max(ans,mid);
                }
                else{
                    e=mid-1;
                }
            }
            else{
                s=mid+1;
            }
            
        }
        return ans;
    }
    
    
    int waysToSplit(vector<int>& nums) {

        int n=nums.size();
        vector<int>prefix(n+1,0);
        
        int ans=0;
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0;i<=n-3;i++){
            int sum=prefix[i+1]-prefix[0];
            int op1=find_ans(i+1,n-2,prefix,sum,n);
            int op2=find_ans2(i+1,n-2,prefix,sum,n);
        
            if(op1!=(int)1e8 and op2!=-1){
                if(op1>i and op1<n-1 and op2<n-1 and op2>=op1){
                    int val=op2-op1+1;
                    ans+=val;
                    ans%=mod;
                    
                }
            }
        }
        
        return ans;
        
    }
};