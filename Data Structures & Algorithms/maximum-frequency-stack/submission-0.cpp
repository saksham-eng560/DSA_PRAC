class FreqStack {
public:
    stack<int> st1;
    map<int,int> mp;
    stack<int> st2;

    FreqStack() {

    }
    
    void push(int val) {
        st1.push(val);
        mp[val]++;
    }
    
    int pop() {
        int max_freq = -1;
        for(auto it : mp){
            max_freq = max(max_freq,it.second);
        }
        while(mp[st1.top()] != max_freq){
            st2.push(st1.top());
            st1.pop();
        }
        int found = st1.top();
        mp[found]--;
        st1.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return found;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */