class Solution {
public:
    int countVowelSubstrings(string word) {
        int cnt=0;
        unordered_map<char,int> mp;
        for(int i=0;i<word.size();i++)
        {
            mp.clear();
            for(int j=i;j<word.size();j++)
            {
                if(!(word[j]=='a'||word[j]=='e'||word[j]=='i'||word[j]=='o'||word[j]=='u'))
                {
                    break;
                }
                mp[word[j]]++;
                
                if(mp.size()==5)
                    cnt++; 
            }
        }
        return cnt;
    }
};