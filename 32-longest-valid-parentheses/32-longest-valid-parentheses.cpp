class Solution {
public:
    int longestValidParentheses(string s) {
        
        int ans=0;
        
        stack<int> stack;
        stack.push(-1);
        for(int i=0;i<s.length();i++){
            char c = s[i];
            
            if(c=='('){
                stack.push(i);
            }else{
                stack.pop();
                if(stack.size()>0){
                    ans=max(ans, i-stack.top());
                }else{
                    stack.push(i);
                }
            }
            
        }
        
        return ans;
    }
};