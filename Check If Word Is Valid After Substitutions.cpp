//https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

class Solution {
public:
    bool isValid(string str) {
        stack < int > st;
        int n = str.size();
        for (int i=0; i<n; i++){
            st.push(str[i]);
            if(st.size() >= 3) {
                int a, b, c;
                c = st.top();
                st.pop();
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                if(a != 'a' || b != 'b' || c != 'c'){
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }
        }
        return st.empty();
    }
};
