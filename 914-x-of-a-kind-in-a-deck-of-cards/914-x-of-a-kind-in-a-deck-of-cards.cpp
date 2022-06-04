class Solution {
public:
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        
        
        
        unordered_map <int,int> mp;
        
        for(auto n:deck){
            mp[n]++;
        }
        
        vector<int>fq;
        for(auto x:mp){
            if(x.second==1){
                return false;
            }
           fq.push_back(x.second);
        }
        
        
        int n = fq[0];
        for (int i = 1; i < fq.size(); i++)
        {
            n = gcd(fq[i], n);

            if(n == 1)
            {
               return false;
            }
        }
        return true;
        
    }
};