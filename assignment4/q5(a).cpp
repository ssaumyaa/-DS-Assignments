#include<iostream>
#define MAX 100
using namespace std;
typedef struct queues{
    int front; 
    int rear;
    int arr[MAX];
}que;
que init(que &q){
    q.front = -1;
    q.rear = -1;
    return q;
}
bool isEmpty(que &q){
    return((q.front == -1 && q.rear == -1) || q.front > q.rear);
}
bool isFull(que &q){
    return(q.rear == MAX - 1);
}
int size(que &q){
    return q.rear - q.front + 1;
}
que enqueue(que &q, int &data){
    if(isFull(q)){
        cout << "queue is full\n";
    }
    else if(isEmpty(q)){
        q.front = q.rear = 0;
        q.arr[q.rear] = data;
    }
    else{
        q.arr[++q.rear] = data;
    }
    return q;
}
int dequeue(que &q){
    int item = -1;
    if(isEmpty(q)){
        cout << "queue is empty\n";
    }
    else{
        item = q.arr[q.front++];
    }
    return item;
}
int peek(que &q){
    if(isEmpty(q)){
        return 0;
    }
    else{
    return q.arr[q.rear];
    }
}
void popStack(que &q1, que &q2){
    if(isEmpty(q1)){
        cout << "stack is empty\n";
        return;
    }
    while(size(q1) > 1){
        int data = dequeue(q1);
        enqueue(q2, data);
    }
    dequeue(q1);
    for(!isEmpty(q2)){
        int data = dequeue(q2);
        enqueue(q1, data);
    }
    return;
}
void displayStack(que &q1){
    for(int i=q1.front; i<=q1.rear; i++){
        cout << q1.arr[i] << " ";
    }
}
int main(){
    que Q1, Q2;
    init(Q1);
    init(Q2);
    int data;
    cout << "enter data to be pushed onto stack: \n";
    cin >> data;
    enqueue(Q1, data);
    cout << "enter data to be pushed onto stack: \n";
    cin >> data;
    enqueue(Q1, data);
    cout << "enter data to be pushed onto stack: \n";
    cin >> data;
    enqueue(Q1, data);
    cout << "enter data to be pushed onto stack: \n";
    cin >> data;
    enqueue(Q1, data);
    popStack(Q1,Q2);
    cout << "your stack is: ";
    displayStack(Q1);
    return 0;
}
