class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        int ans=0,count=0;
        int n = arr.size();
        while(ans<n/2){
            ans+=pq.top().first;
            pq.pop();
            count++;
        }
        return count;
    }
};