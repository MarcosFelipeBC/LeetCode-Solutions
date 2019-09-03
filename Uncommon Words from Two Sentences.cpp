//https://leetcode.com/problems/uncommon-words-from-two-sentences/

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        A.push_back(' '), B.push_back(' ');
        unordered_set < string > s, appearAgain;
        string aux;
        vector < string > ans;
        for (int i=0; i<A.size(); i++){
            if(A[i] == ' '){
                if(s.find(aux) != s.end()) appearAgain.insert(aux);
                else s.insert(aux);
                aux.clear();
            }
            else aux.push_back(A[i]);
        }
        for (int i=0; i<B.size(); i++){
            if(B[i] == ' '){
                if(s.find(aux) != s.end()) appearAgain.insert(aux);
                else s.insert(aux);
                aux.clear();
            }
            else aux.push_back(B[i]);
        }
        for (unordered_set < string > :: iterator it = s.begin(); it != s.end(); it++){
            if(appearAgain.find(*it) == appearAgain.end()) ans.push_back(*it);
        }
        return ans;
    }
};
