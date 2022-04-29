class Solution {
public:
    
    int solve(vector<string>& words,vector<int> &freq,vector<int> score, int idx){
        
        if(idx==words.size()){
            return 0;
        }
        
        int sno = 0 + solve(words,freq,score,idx+1);
        
        int sword =0;
        string s =words[idx];
        bool flag = true;
        
        for(int i=0;i<s.length();i++){
            
            if(freq[s[i]-'a']==0){
                flag=false;
            }
            
            freq[s[i]-'a']--;
            
            sword+=score[s[i]-'a'];
        }
        
        int syes =0;      
        if(flag){
             syes = sword + solve(words,freq,score,idx+1);
        }
        
        for(int i=0;i<s.length();i++){
           
            freq[s[i]-'a']++;
           
        }
        
        return max(syes,sno);
        
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        vector<int> freq(26,0);
        
        for(auto l:letters){
            freq[l-'a']++;
        }
        
        
        return solve(words,freq,score,0);
        
        
    }
};