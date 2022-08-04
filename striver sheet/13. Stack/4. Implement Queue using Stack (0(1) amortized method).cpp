#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>s1,s2;
    void push(int x) {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x=s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
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
class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>input,output;
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        int x=output.top();
            output.pop();
            return x;
    }
    
    int peek() {
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        int x=output.top();
           
            return x;
    }
    
    bool empty() {
        return input.empty() && output.empty();
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