class MyQueue {
public:

stack<int>s,ss;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s.empty()){
            ss.push(s.top());
            s.pop();
        }
        s.push(x);

        while(!ss.empty()){
            s.push(ss.top());
            ss.pop();
        }
    }
    
    int pop() {
        int ans = s.top();
        s.pop();
        return ans;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
     return   s.empty();
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