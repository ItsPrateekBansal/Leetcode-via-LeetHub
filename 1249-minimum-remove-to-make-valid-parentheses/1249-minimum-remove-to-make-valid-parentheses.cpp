class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int lastValidIndex = -1;
        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == '(') {
                st.push(i);
                continue;
            }
            
            if(s[i] == ')') {
                if(st.size() == 0) s[i] = '.';
                else st.pop();
            }
            
        }
        while(st.size()) {
            s[st.top()] = '.';
            st.pop();
        }
        string answer = "";
        for(char ch : s) {
            if(ch=='.') continue;
            answer += ch;
        }
        return answer;
    }
};