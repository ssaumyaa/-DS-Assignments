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
bool isMatching(char open, char close){
    return(open == '(' && close == ')' || open == '{' && close == '}' || open == '[' && close == ']');
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
bool isBalanced(string expr){
    Stack s;
    init(s);
    for(int i=0; i<expr.length(); i++){
        char ch = expr[i];
        if(ch == '(' || ch == '{' ||ch == '['){
        push(s,expr[i]);
        }
        else if(ch == ')' || ch == '}' ||ch == ']'){
            if(isEmpty(s)){
                return false;
            }
            if(!isMatching(pop(s), ch)){
                return false;
            }
        }
    }
    return isEmpty(s);
}
int main(){
    Stack stack;
    init(stack);
    cout << "enter your expression\n";
    string expression;
    getline(cin, expression);
    if(isBalanced(expression)){
        cout << "your expression is balanced\n";
    }
    else{
        cout << "your expression is not balanced\n";
    }
    return 0;
}