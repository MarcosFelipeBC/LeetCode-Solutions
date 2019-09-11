//https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        if(str1.size() == 0 || str2.size() == 0) return ans;
        int n = str1.size(), m = str2.size(), ans_sz = 0;
        for (int sz=1; sz<=n; sz++){
            if(n%sz == 0 && m%sz == 0){
                bool flag = true;
                for (int j=0; j<max(n, m); j++){
                    if(j < n) {
                        if(str1[j] != str1[j%sz] || str1[j] != str2[j%sz]){
                            flag = false;
                            break;
                        }
                    }
                    if(j < m) {
                        if(str2[j] != str2[j%sz] || str2[j] != str1[j%sz]){
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag) ans_sz = sz;
            }
        }
        ans = str1.substr(0, ans_sz);
        return ans;
    }
};
