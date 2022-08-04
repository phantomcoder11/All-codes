#include<bits/stdc++.h>
using namespace std;
//Using 1 queue
class MyStack {
public:
    MyStack() {
       
    }
     queue<int>q;
    void push(int x) {
        q.push(x);
        int size=q.size()-1;
        while(size--){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    int pop() {
        
        int temp=q.front();
        q.pop();
        return temp;
    }
    
    int top() {
      return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};


// Using 2 queues

class MyStack {
public:
    MyStack() {
       
    }
     queue<int>q1,q2;
    void push(int x) {
        q2.push(x);
        while(q1.size()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
        
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

