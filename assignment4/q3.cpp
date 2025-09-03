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
void interleave(que &q, int &n){
    que q2; // temporary queue
    init(q2);
    for(int i=n/2; i<n; i++){ // copying second half of the queue to another queue
        enqueue(q2, q.arr[i]);
    }
    for(int i=1; i<n; i=i+2){
        for(int j=n-1; j>i; j--){
            q.arr[j] = q.arr[j-1];
        }
        q.arr[i] = peek(q2);
        dequeue(q2);
    }
}
void display(que &q, int &n){
    for(int i=0; i<n; i++){
        cout << q.arr[i] << " ";
    }
    cout << "\n";
}
int main(){
    que q;
    init(q);
    int a;
    cout << "enter number to be added to queue\n";
    cin >> a;
    enqueue(q, a);
    cout << "enter number to be added to queue\n";
    cin >> a;
    enqueue(q, a);
    cout << "enter number to be added to queue\n";
    cin >> a;
    enqueue(q, a);
    cout << "enter number to be added to queue\n";
    cin >> a;
    enqueue(q, a);
    cout << "enter number to be added to queue\n";
    cin >> a;
    enqueue(q, a);
    cout << "enter number to be added to queue\n";
    cin >> a;
    enqueue(q, a);
    int N = size(q);
    interleave(q, N);
    display(q, N);
    return 0;
}
