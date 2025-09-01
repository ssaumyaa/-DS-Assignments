#include<iostream>
#define MAX 100
using namespace std;
typedef struct stack{
    int top;
    int array[MAX];
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
    s.array[++s.top] = data;
}
int pop(st &s){
    return(s.array[s.top--]);
}
int peek(st &s){
    return(s.array[s.top]);
}
void createArray(int arr[], int &size){
    cout << "enter number of temperatures \n";
    cin >> size;
    cout << "enter temperatures\n";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
}
void findDays(int arr[], int resultArray[], int & size){
    st next;
    int days = 0;
    init(next);
    for(int i=size-1; i>=0; i--){
        while(!isEmpty(next) && arr[peek(next)] <= arr[i]){
            pop(next);
        }
        if(isEmpty(next)){
            days = 0;
        }
        else{
            days = peek(next) - i;
        }
        push(next,i);
        resultArray[i] = days;
    }
}
void displayArray(int arr[], int &size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main(){
    int temperatures[MAX] , daysforwarmer[MAX];
    int n;
    createArray(temperatures, n);
    findDays(temperatures, daysforwarmer, n);
    displayArray(daysforwarmer, n);
    return 0;
}
