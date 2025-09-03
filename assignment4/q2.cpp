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
    return(q.front == -1);
}
bool isFull(que &q){
    return(q.front == (q.rear + 1) % MAX);
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
        q.rear = (q.rear+1) % MAX;
        q.arr[q.rear] = data;
    }
    return q;
}
que dequeue(que &q){
    if(isEmpty(q)){
        cout << "queue is empty\n";
    }
    else{
        // int item = q.arr[q.front];
        cout << "removed element: " << q.arr[q.front];
        if(q.front == q.rear){
            q.front = q.rear = -1;
        }
        else{
        q.front = (q.front+1) % MAX;
        cout << "front element was deleted.\n";
        }
    }
    return q;
}
int peek(que &q){
    if(isEmpty(q)){
        return -1;
    }
    else{
    return q.arr[q.front];
    }
}
void display(que q){
    if(isEmpty(q)){
        cout << "queue is empty\n";
        return;
    }
    cout << "your queue is : \n";
    int i = q.front;
    while (i!=(q.rear+1) % MAX) {
        cout << q.arr[i] << " ";
        i = (i + 1) % MAX;        
    }
    cout << "\n";
}
int main(){
    que Q;
    init(Q);
    int x;
    cout << "your options are: \n1. enqueue\n2. dequeue\n3. peek\n4. display\n5. exit\nenter operation number please: \n";
    int opNo;
    int size;
    while(true){
    cin >> opNo;
    switch(opNo){
        case 1:
        enqueue(Q, x);
        break;
        case 2: 
        dequeue(Q);
        break;
        case 3:
        cout << "front element of your queue is: " << peek(Q);
        break;
        case 4:
        display(Q);
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
