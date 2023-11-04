class Solution {
public:
    int characterReplacement(string a, int k) {
        int maxcount=0,i=0,j=0,ans=0;
        int n=a.size();
        int arr[26]={0};
        while(j<n){
            arr[a[j]-'A']++;
            maxcount=max(maxcount,arr[a[j]-'A']);
            int len=j-i+1;

            if(len-maxcount<=k){
                ans=max(ans,len);
            }
            else{
                arr[a[i]-'A']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};