// #include<bits/stdc++.h>
// using namespace std;

// class Queue{
//     int size;
//     int * arr;
//     int front;
//     int rear;

//     public:
//     Queue(){
//         size=1000;
//         arr=new int[size];
//         front=0;
//         rear=-1;
//     }
//     void push(int ele){
//         arr[++rear]=ele;
//     }
//     int Front(){
//         return arr[front];
//     }
//     void pop(){
//         front++;
//     }
//     bool isEmpty(){
//         return front>rear;
//     }
//     int Size(){
//         return (front<=rear)?rear-front+1:-1;
//     }
// };

// int main(){
//     Queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.pop();
//     q.push(4);
//     q.push(5);
//     q.push(6);
//     while(!q.isEmpty()){
//         cout<<q.Front()<<" "<<q.Size()<<endl;
//         q.pop();
//     }
//     cout<<q.Size();
//     return 0;
// }
#include<bits/stdc++.h>

using namespace std;
class Queue {
  int * arr;
  int start, end, currSize, maxSize;
  public:
    Queue() {
      arr = new int[16];
      start = -1;
      end = -1;
      currSize = 0;
    }

  Queue(int maxSize) {
    ( * this).maxSize = maxSize;
    arr = new int[maxSize];
    start = -1;
    end = -1;
    currSize = 0;
  }
  void push(int newElement) {
    if (currSize == maxSize) {
      cout << "Queue is full\nExiting..." << endl;
      exit(1);
    }
    if (end == -1) {
      start = 0;
      end = 0;
    } else
      end = (end + 1) % maxSize;
    arr[end] = newElement;
    cout << "The element pushed is " << newElement << endl;
    currSize++;
  }
  int pop() {
    if (start == -1) {
      cout << "Queue Empty\nExiting..." << endl;
    }
    int popped = arr[start];
    if (currSize == 1) {
      start = -1;
      end = -1;
    } else
      start = (start + 1) % maxSize;
    currSize--;
    return popped;
  }
  int top() {
    if (start == -1) {
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];
  }
  int size() {
    return currSize;
  }

};

int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;

  return 0;
}