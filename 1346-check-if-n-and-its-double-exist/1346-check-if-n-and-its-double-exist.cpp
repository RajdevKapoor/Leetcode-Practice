class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_set<int> s;
        
        for(int a:arr){
            if(s.count(a*2) or (a%2==0 and s.count(a/2))){
                return true;
            }else{
                s.insert(a);
            }
        }
        return false;
    }
};