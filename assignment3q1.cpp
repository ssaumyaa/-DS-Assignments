#include<iostream>
#define MAXLEN 100
using namespace std;
typedef struct Stack{
    int arr[MAXLEN];
    int top;
}Stack;
void init(Stack &s){
    s.top = -1;
}
bool isEmpty(Stack &s){
    return(s.top == -1);
}
bool isFull(Stack &s){
    return(s.top == MAXLEN - 1);
}
void push(Stack &s){
    if(isFull(s)){
        cout << "stack is in overflow condition\n";
    }
    else{
        int data;
        cout << "enter number to be pushed onto stack\n";
        cin >> data; 
        ++s.top;
        s.arr[s.top] = data;
    }
}
int pop(Stack &s){
if(isEmpty(s)){
    cout << "stack is in underflow condition\n";
    return -1;
}
else{
    return s.arr[s.top--];
}
}
void display(Stack &s){
    if(isEmpty(s)){
        cout << "stack is in underflow condition\n";
    }
    else{
        for(int i=0; i<=s.top; i++){
            cout << s.arr[i] << " ";
        }
    }
}
int peek(Stack &s){
    if(isEmpty(s)){
        cout << "stack is in underflow condition\n";
    }
    else{
        return(s.arr[s.top]);
    }
}
int main(){
    Stack numbers;
    init(numbers);
    push(numbers);
    push(numbers);
    push(numbers);
    push(numbers);
    cout << "the topmost number is: " << peek(numbers) << "\n";
    cout << "your stack is: "; 
    display(numbers);
    cout << "\n";
    cout << "the topmost number was: " << pop(numbers) << "\n";
    cout << "your stack is: "; 
    display(numbers);
    cout << "\n";
    return 0;
}