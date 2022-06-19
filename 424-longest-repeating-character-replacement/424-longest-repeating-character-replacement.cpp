class Solution {
public:
    int characterReplacement(string s, int k) {
         int maxCount = 0, maxLength = 0, left = 0, right = 0;
         unordered_map<char, int> freqLetters;     
         while(right < s.size())
         {
             freqLetters[s[right]]++;
             maxCount = max(maxCount, freqLetters[s[right]]);  
             if(right - left + 1 - maxCount > k)  
             {
                 freqLetters[s[left]]--;
                 left++;
             }
             maxLength = max(maxLength, right - left + 1);   
             right++;
         }
        return maxLength;
    }
};