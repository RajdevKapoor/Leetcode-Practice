class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int start = 0;
        int def = 0;
        int bal = 0;
       
        for(int i = 0; i < gas.size(); i++){
            bal += gas[i] - cost[i];
            if(bal<0){
                def += bal;
                bal = 0;
                start = i+1;
            }
        }
        
        if(bal+def>=0){
            return start;
        }
        return -1;
        
    }
};