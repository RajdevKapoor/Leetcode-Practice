class Solution {
public:
    bool areAnagram(string a, string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return a==b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> myvec;
        int n=words.size();
        for(int i=0; i<n;i++){
            int j=i+1;
            while(j<n && areAnagram(words[i],words[j]))
                    j++;
            myvec.push_back(words[i]);
            i=j-1;
       }
        return myvec;
    }
};