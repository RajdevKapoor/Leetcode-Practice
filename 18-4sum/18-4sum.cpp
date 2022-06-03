class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        int n=a.size();
        for(int i=0;i<n;i++){
            if(i>0 and a[i]==a[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 and a[j]==a[j-1]) continue;
                int s = j+1;
                int e = n-1;
                
                while(s<e){
                    long long sum = a[i];
                    sum+=a[j];
                    sum+=a[s];
                    sum+=a[e];
                    if(sum>target) e--;
                    else if(sum<target) s++;
                    else{
                        ans.push_back({a[i],a[j],a[s],a[e]});
                        s++;
                        e--;
                        
                        while(s<e and a[s]==a[s-1])s++;
                        while(s<e and a[e]==a[e+1])e--;
                    }
                }
            }
        }
        
        return ans;
    }
};