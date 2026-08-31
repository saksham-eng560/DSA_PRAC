class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> st1;
    stack<int> st2;
    void push(int x) {
        if(st2.empty() == true){
            st2.push(x);
            return;
        }
        while(!st2.empty()){
            int t = st2.top();st2.pop();
            st1.push(t);
        }
        st1.push(x);
        while(!st1.empty()){
            int t = st1.top();st1.pop();
            st2.push(t);
        }
    }
    
    int pop() {
        int t = st2.top();
        st2.pop();
        return t;
    }
    
    int peek() {
        return st2.top();
    }
    
    bool empty() {
        if(st2.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */