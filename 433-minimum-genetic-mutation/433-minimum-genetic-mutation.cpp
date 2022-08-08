class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start == end)
            return 0;
        
        unordered_set<string> h, v;
        for(auto s : bank)
            h.insert(s);
        
        if(h.find(end) == h.end())
            return -1;
        

        vector<char> GENE = {'A', 'C', 'T', 'G'};
        

        queue<string> q;
        q.push(start);
        int count = 0;
        
        while(!q.empty()){
            queue<string> q1;
            while(!q.empty()){
                string cur = q.front();
                q.pop();
                
                if(cur == end){
                    return count;
                }
                
                
                for(int i = 0 ; i < 8 ; i++){
                    char temp = cur[i]; // cahce
                    for(int j = 0 ; j < 4 ; j++){
                        cur[i] = GENE[j];
                        if(h.find(cur) != h.end() && v.find(cur) == v.end()){
                            q1.push(cur);
                            v.insert(cur);
                        }
                    }
                    cur[i] = temp; // reset
                }         
            }
            q = q1;
            count++;
        }
        
        return -1;
        
    }
};