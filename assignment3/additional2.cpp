#include<iostream>
#define MAX 100
using namespace std;
typedef struct stack{
    int top;
    int array[MAX];
    int minArray[MAX];
}st;
void init(st &s){
    s.top = -1;
}
bool isEmpty(st &s){
    return(s.top == -1);
}
bool isFull(st &s){
    return(s.top == MAX-1);
}
void push(st &s, int data){
    if(isFull(s)){
        cout << "stack is full\n";
        return;
    }
    s.array[++s.top] = data;
    if(s.top == 0){
        s.minArray[s.top] = data;
    }
    else{
        if(data < s.minArray[s.top - 1]){
            s.minArray[s.top] = data;
        }
        else{
            s.minArray[s.top] = s.minArray[s.top-1];
        }
    }
}
int pop(st &s){
    return(s.array[s.top--]);
}
int peek(st &s){
    return(s.array[s.top]);
}
int getMin(st &s){
    if(isEmpty(s)){
        cout << "stack empty!\n";
    }
    return s.minArray[s.top];
}
int main(){
    st nums;
    init(nums);
    push(nums, 1);
    push(nums, 3);
    push(nums, 0);
    push(nums, 8);
    push(nums, -4);
    cout << "the minimum number in your stack is: " << getMin(nums);
    return 0;
}
