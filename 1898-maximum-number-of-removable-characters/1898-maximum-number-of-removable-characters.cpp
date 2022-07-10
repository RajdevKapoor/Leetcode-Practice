class Solution {
public:
    bool ispossible(string s,string p,int mid ,vector<int>&remove){
        
        for(int i=0;i<mid;i++){
            s[remove[i]]='.';
        }
        
        int j=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]==p[j]){
                j++;
            }
            
            if(j==p.length()) return true;
        }
        return false;
    }
    
    int maximumRemovals(string st, string p, vector<int>& removable) {
        int s=0;
        int ans=0;
        
        int e=removable.size();
        while(s<=e){
            int mid=(s+e)/2;
            if(ispossible(st,p,mid,removable)){
                ans=max(ans,mid);
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
        
    }
};