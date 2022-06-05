class FreqStack {
private:
    unordered_map<int, int> freqs;
    vector<stack<int>> freqsordered;
    
public:
    FreqStack() {
        freqsordered.push_back({});
    }
    
    void push(int val) {
        freqs[val]++;
        if(freqs[val] == freqsordered.size()){
            stack<int> s;
            s.push(val);
            freqsordered.push_back(s);
        }
        else{
            freqsordered[freqs[val]].push(val);
        }
    }
    
    int pop() {
        int mostfrequent = freqsordered.back().top();
        freqsordered.back().pop();
        if(freqsordered.back().empty()){
            freqsordered.pop_back();
        }
        freqs[mostfrequent]--;
        return mostfrequent;
    }
};