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
        cout << "enter number to be added to queue\n";
        cin >> data;
        q.arr[q.rear] = data;
    }
    else{
        cout << "enter number to be added to queue\n";
        cin >> data;
        q.arr[++q.rear] = data;
    }
    return q;
}
que dequeue(que &q){
    if(isEmpty(q)){
        cout << "queue is empty\n";
    }
    else{
        int item = q.arr[q.front++];
    }
    return q;
}
int peek(que &q){
    if(isEmpty(q)){
        return 0;
    }
    else{
    return q.arr[q.front];
    }
}
void display(que q, int &n){
    n = size(q);
    cout << "your queue is : \n";
    for(int i=q.front; i<=q.rear; i++){
        cout << q.arr[i] << " ";
    }
    cout << "\n";
}
int main(){
    que Q;
    init(Q);
    cout << "your options are: \n1. enqueue\n2. dequeue\n3. peek\n4. display\n5. exit\nenter operation umber please: \n";
    int opNo;
    int size;
    while(true){
    cin >> opNo;
    switch(opNo){
        case 1:
        int n;
        enqueue(Q, n);
        break;
        case 2: 
        dequeue(Q);
        break;
        case 3:
        cout << "front element of your queue is: " << peek(Q);
        break;
        case 4:
        display(Q, size);
        break;
        case 5:
        cout << "exiting..";
        return 0;
        default:
        cout << "please enter valid option number \n";
    }
}
    return 0;
}
