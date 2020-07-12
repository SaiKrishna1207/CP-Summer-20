class Solution {
public:
    bool isValid(string S) {
        int i, j, k;
        int l = S.length();
        if (S.length() % 3 || (!S.empty() && S[0] != 'a') || (!S.empty() && S[l - 1] != 'c')) 
            return false;
    
        stack<char> st;
        for (i = 0; i < l; i++) {
            char c = S[i];
            if (c == 'c' && !st.empty() && st.top() == 'b') {
                st.pop();
                if (!st.empty() && st.top() == 'a') 
                    st.pop();     
                else {
                    st.push('b'); 
                    st.push('c');                  
                }
            }   
            else 
                st.push(c);
        }
        if(st.empty())
            return true;
        return false;
    }
};
