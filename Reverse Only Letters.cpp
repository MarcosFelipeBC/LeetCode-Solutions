class Solution {
public:
    bool isLetter(char c){
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }
    
    string reverseOnlyLetters(string S) {
        string str;
        reverse(S.begin(), S.end());
        for (int i=0; i<(int)S.size(); i++){
            if(isLetter(S[i])) str.push_back(S[i]);
        }
        string ans;
        int pos = 0;
        cout << str << endl;
        for (int i=(int)S.size()-1; i>=0; i--){
            if(isLetter(S[i])){
                ans.push_back(str[pos]);
                pos++;
            }
            else ans.push_back(S[i]);
        }
        return ans;
    }
};
