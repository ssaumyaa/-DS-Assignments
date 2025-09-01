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
    cout << "enter size of array \n";
    cin >> size;
    cout << "enter elements\n";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
}
void nearestSmallerElements(int arr[], int resultArray[], int & size){
    st previous;
    int nearest;
    init(previous);
    for(int i=0; i<size; i++){
        while(!isEmpty(previous) && previous.array[previous.top] >= arr[i]){
            pop(previous);
        }
        if(isEmpty(previous)){
            nearest = -1;
        }
        else{
            nearest = peek(previous);
        }
        push(previous, arr[i]);
        resultArray[i] = nearest;
    }
}
void displayArray(int arr[], int &size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int A[MAX]; 
    int R[MAX];
    int n;
    createArray(A, n);
    nearestSmallerElements(A, R, n);
    displayArray(R, n);
    return 0;
}
