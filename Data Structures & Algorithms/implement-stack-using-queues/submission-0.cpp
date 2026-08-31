class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q1,q2;
    void push(int x) {
        if(q1.size() == 0){
            q1.push(x);
            return;
        }
        while(!q1.empty()){
            int t = q1.front();q1.pop();
            q2.push(t);
        }
        q1.push(x);
        while(!q2.empty()){
            int t = q2.front();q2.pop();
            q1.push(t);
        }
    }
    
    int pop() {
        int t = q1.front();
        q1.pop();
        return t;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.size() == 0) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj-.front();
 * bool param_4 = obj->empty();
 */