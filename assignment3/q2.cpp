#include<iostream>
#define MAXLEN 100
using namespace std;
typedef struct Stack{
    char arr[MAXLEN];
    int top;
}Stack;
void init(Stack &s){
    s.top = -1;
}
bool isEmpty(Stack &s){
    return(s.top == -1);
}
bool isFull(Stack &s){
    return(s.top == MAXLEN-1);
}
void push(Stack &s, char data){
    if(isFull(s)){
        cout << "stack is in overflow condition\n";
    }
    else{
    s.arr[++s.top] = data;
    }
}
char pop(Stack &s){
    if(isEmpty(s)){
        cout << "stack is in underflow condition\n";
        return '\0';
    }
    else{
        return(s.arr[s.top--]);
    }
}
void display(Stack &s){
    if(isEmpty(s)){
        cout << "stack is in underflow condition\n";
    }
    else{
        for(int i=0; i<=s.top; i++){
            cout << s.arr[i];
        }
    }
}
void reverseStackElements(Stack &s){
    if(isEmpty(s)){
        cout << "stack is in underflow condition\n";
    }
    else{
        for(int i=0, j=s.top; i<j; i++,j--){
            char temp = s.arr[i];
            s.arr[i] = s.arr[j];
            s.arr[j] = temp;
        }
    }
}
void pushCharactersOnStack(string str, Stack &s){
    for(int i=0; i<str.length(); i++){
        push(s, str[i]);
    }
}
int main(){
    Stack stack;
    init(stack);
    cout << "enter your string\n";
    string str;
    getline(cin, str);
    pushCharactersOnStack(str, stack);
    reverseStackElements(stack);
    cout << "the reverse of your string is : ";
    display(stack);
    return 0;
}
