#include<bits/stdc++.h>
using namespace std;
class Stack{
    int size;
    int * arr;
    int top;
    public:
    Stack(){
        size=1000;
        arr=new int[size];
        top=-1;
    }
    void push(int ele){
        arr[++top]=ele;
    }
    int Top(){
        return (top!=-1)?arr[top]:-1;
    }
    int Size(){
        return top+1;
    }
    void pop(){
        top--;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    cout<<"The top element is "<<s.Top()<<endl;
    s.push(3);
    cout<<"The size of the stack is "<<s.Size()<<endl;
    s.pop();
    cout<<"The top element is "<<s.Top()<<endl;
    return 0;
}