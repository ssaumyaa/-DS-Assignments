#include<iostream>
#define MAX 100
using namespace std;
typedef struct queue{
    int front;
    int rear;
    char arr[MAX];
}que;
void init(que &q){
    q.front = q.rear = -1;
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
void enqueue(que &q, char &data){
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
    return;
}
void dequeue(que &q){
    if(isEmpty(q)){
        cout << "queue is empty\n";
    }
    else{
        q.front++;
    }
    return;
}
char peek(que &q){
    if(isEmpty(q)){
        return 0;
    }
    else{
    return q.arr[q.front];
    }
}
string inputString(string &str){
    cout << "enter your string\n";
    getline(cin, str);
    return str;
}
void nonRepeating(que &q, int freq[], string &str){
    for(int i=0; i<str.length(); i++){
        enqueue(q, str[i]);
        freq[str[i]]++;
        while(!isEmpty(q) && freq[peek(q)] > 1){
            dequeue(q);
        }
        if(isEmpty(q)){
            cout << "-1 ";
        }
        else{
            cout << peek(q) << " ";
        }
    }
    cout << "\n";
}
int main(){
    string str;
    que q;
    init(q);
    inputString(str);
    int freq[256] = {0};
    nonRepeating(q, freq, str);
    return 0;
}
