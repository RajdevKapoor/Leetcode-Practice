class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int ,int>> arr(speed.size());
        int c=0;
        stack<double> stk;
        int n=speed.size();
        for(int i=0;i<n;i++)
        {
                arr[i].first=position[i];
                arr[i].second=speed[i];
        }
        sort(arr.begin(),arr.end());
        stk.push((double)(target -arr[n-1].first)/(double) arr[n-1].second);
        for(int i=n-2;i>=0;i--)
        {
                double val= (double)( target - arr[i].first) / (double) arr[i].second  ;
                if( val > stk.top() )
                {
                        stk.push(val);
                }
               
        }
        
        return stk.size();
        
    }
};