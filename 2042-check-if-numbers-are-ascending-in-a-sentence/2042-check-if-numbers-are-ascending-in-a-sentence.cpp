class Solution {
public:
    bool areNumbersAscending(string s) {
        int min_value = 0;
        int size = s.size();

        for(int i = 0; i < size; i++){

            if(s[i] - '0' <= 9 && s[i] - '0' >= 0){

                int number = s[i] - '0';

                if(i < size - 1)
                    if(s[i + 1] - '0' <= 9 && s[i + 1] - '0' >= 0){
                        number = (s[i] - '0') * 10 + (s[i + 1] - '0');
                        i++;
                    }

                if(min_value < number){
                    min_value = number;
                }
                else
                    return false;
            }

        }

        return true;    
    }
};