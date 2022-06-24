class Solution {
public:
    bool count(int mid,vector<vector<int>>& matrix,int n,int m,int k)
    {
         int cnt=0;

         for(int i=0;i<n;i++)
         {
             int c=m-1;
             while(c>=0 && matrix[i][c]>mid)
                c--;
             cnt+=c+1;
         }

            return cnt<k;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=matrix[0][0];
        int ans=matrix[0][0];
        int e=matrix[n-1][m-1];
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(count(mid,matrix,n,m,k))
                s=mid+1;
            else
            {
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};