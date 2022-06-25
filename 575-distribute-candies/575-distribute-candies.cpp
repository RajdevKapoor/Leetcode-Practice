class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_set <int>s;
        
        for(int x:candyType){
            s.insert(x);
            if(s.size()==candyType.size()/2){
                return candyType.size()/2;
            }
        }
        
        return s.size();
        
    }
};