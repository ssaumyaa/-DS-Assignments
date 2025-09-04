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
int popStack(que &q){
    if(isEmpty(q)){
        cout << "stack is empty\n";
        return -1;
    }
    int popped = dequeue(q);
    if(isEmpty(q)){
        q.rear = q.front = -1;
    }
    return popped;
}
void pushStack(que &q, int &data){ // put new element always at the front after enqueueing 
    if(isFull(q)){
        cout << "stack is full\n";
    }
    enqueue(q,data);
    int x = q.arr[q.rear];
    for(int i=0; i<size(q)-1 ; i++){
        int temp = dequeue(q);
        enqueue(q, temp);
    }
}
void displayStack(que &q){
    for(int i=q.rear; i>=q.front; i--){
        cout << q.arr[i] << " ";
    }
}
int main(){
    que Q;
    init(Q);
    int data;
    cout << "enter data to be pushed onto stack: \n";
    cin >> data;
    pushStack(Q,data);
    cout << "enter data to be pushed onto stack: \n";
    cin >> data;
    pushStack(Q,data);
    cout << "enter data to be pushed onto stack: \n";
    cin >> data;
    pushStack(Q,data);
    cout << "enter data to be pushed onto stack: \n";
    cin >> data;
    pushStack(Q,data);
    popStack(Q);
    cout << "your stack is: ";
    displayStack(Q);
    return 0;
}
