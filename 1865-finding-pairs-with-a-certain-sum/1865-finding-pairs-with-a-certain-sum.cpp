class FindSumPairs {
public:
    vector<int>v1,v2;
    unordered_map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    {
        v1=nums1;
        v2=nums2;
        for(int i=0;i<v2.size();i++)
        {
            mp[v2[i]]++;
        }
    }
    
    void add(int index, int val)
    {
        mp[v2[index]]--;
        v2[index]+=val;
        mp[v2[index]]++;
    }
    
    int count(int tot)
    {
        int count=0;
        for(int i=0;i<v1.size();i++)
        {
            int k=tot-v1[i];
            if(mp.find(k)!=mp.end())
            {
                count+=mp[k];
            }
            
        }
        return count;
    }
};