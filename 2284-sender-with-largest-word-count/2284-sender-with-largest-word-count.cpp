class Solution {
public:
    static bool cmp(pair<int,string>&a,pair<int,string> &b)
    {   
        if(a.first == b.first) return a.second > b.second;
        
        return a.first > b.first;
    
    }
    int countspace(string s){
        int cnt = count(s.begin(),s.end(),' ');
        return cnt+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m;
        vector<pair<int,string>> vec;
        vector<string> v;
        
        int n = senders.size();
        for(int i=0;i<n;i++){
            m[senders[i]] += countspace(messages[i]);
           
        }
        
        for(auto i :m)
            vec.push_back({i.second,i.first});
        
        sort(vec.begin(),vec.end(),cmp);
        return vec[0].second;
        
        
    }
};