class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> map;
        
        for(int i=0; i<time.size(); i++) {
            time[i] %= 60;
        }
        int count = 0;
        signed long int zeroCount = 0;
        for(int i=time.size()-1; i>=0; i--) {
            int key = 60 - time[i];
            if(time[i] != 0) {
                if(map.find(key) != map.end()) {
                    count += map[key];
                } 
                map[time[i]]++;
            }
            else {
                zeroCount+=1;
            }
                
        }
        if(zeroCount != 0) {
            zeroCount = zeroCount*(zeroCount-1)/2;
            return count + zeroCount;
        }
        return count;
    
    }
    
};