//https://leetcode.com/problems/min-stack/

class MinStack {
public:
    vector < pair < int, int > > pq;
    
    MinStack() {}
    
    void push(int x) {
        pq.push_back({x, min(x, (pq.size()) ? pq.back().second : INT_MAX)});
    }
    
    void pop() {
        if(pq.size()) pq.pop_back();
    }
    
    int top() {
        return pq.back().first;
    }
    
    int getMin() {
        return pq.back().second;
    }
};
