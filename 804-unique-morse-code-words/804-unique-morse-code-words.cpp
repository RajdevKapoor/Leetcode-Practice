class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> code{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> unique_morse;
        
        for(int i=0; i<words.size(); i++){
            string morse_code = "";
            
            for(int j=0; j<words[i].length(); j++){
                morse_code += code[words[i][j]-'a'];
            }
            
            unique_morse.insert(morse_code);
        }
        
        return unique_morse.size();
    }
};