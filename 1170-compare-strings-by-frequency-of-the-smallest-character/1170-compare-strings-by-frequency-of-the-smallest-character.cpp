class Solution {
public:
    int cnt(string s){
        map<char,int> mp;
        for(auto i: s){
            mp[i]++;
        }

        char c='z';
        int fre = 0;
        for(auto x: mp){
            if(x.first<=c){
                c = x.first;
                fre = x.second;
            }
        }
        return fre;
    }
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& words) {
        
        vector<int> wrd,que,v;

        for(int i=0; i<q.size();i++){
            que.push_back(cnt(q[i]));
        }
        
        for(int i = 0; i<words.size();i++){
            wrd.push_back(cnt(words[i]));
        }
        sort(wrd.begin(),wrd.end());

        for(int i = 0; i < que.size();i++){
            int check = que[i];
            int u = upper_bound(wrd.begin(),wrd.end(),check)-wrd.begin();
            v.push_back(wrd.size()-u);
        }
        return v;






    }
};