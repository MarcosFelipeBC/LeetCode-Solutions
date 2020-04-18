class Solution {
public:
    bool isHappy(int n) {
        unordered_set < int > appeared;
        int now = n;
        while (appeared.find(now) == appeared.end()){
            if(now == 1) return true;
            appeared.insert(now);
            int nxt = 0;
            while (now){
                int x = now%10;
                now /= 10;
                nxt += x*x;
            }
            now = nxt;
        }
        return false;
    }
};