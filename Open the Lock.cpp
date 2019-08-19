//https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    unordered_map < string, int > dist;
    
    int bfs(string target){
        if(dist["0000"] == -1) return -1;
        dist["0000"] = 0;
        queue < string > q;
        q.push("0000");
        while (!q.empty()){
            string u = q.front();
            q.pop();
            if(u == target) return dist[u];
            for (int i=0; i<4; i++){
                string v = u;
                if(v[i] == '9') v[i] = '0';
                else v[i]++;
                if(!dist.count(v)){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
                if(v[i] == '1') v[i] = '9';
                else if(v[i] == '0') v[i] = '8';
                else v[i] -= 2;
                if(!dist.count(v)){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
    
    int openLock(vector<string>& deadends, string target) {
        for (string x : deadends) dist[x] = -1;
        return bfs(target);
    }
};

