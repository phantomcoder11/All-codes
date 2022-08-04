class MinStack {
public:
    MinStack() {
        
    }
    stack<long long>s;
    long long mn;
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mn=val;
        }
        else if(val>=mn){
            s.push(val);
        }else{
           
            s.push(2ll*val-mn);
             mn=val;
        }
    }
    
    void pop() {
        if(s.empty()) return;
        if(s.top()<mn){
             mn=2ll*mn-s.top();
        }
        s.pop();
        
    }
    
    int top() {
        if(s.empty()) return -1;
        if(s.top()<mn){
            return mn;
        }
        else{
            return s.top();
        }
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */