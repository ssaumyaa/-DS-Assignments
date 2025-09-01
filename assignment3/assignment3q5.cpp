#include<iostream>
#include<string>
#define MAX 100
using namespace std;
typedef struct stack{
    int top;
    char arr[MAX];
}stack;
bool isEmpty(stack &s){
    return(s.top == -1);
}
bool isFull(stack &s){
    return(s.top == MAX-1);
}
void init(stack &s){
    s.top = -1;
}
char peek(stack &s){
    return(s.arr[s.top]);
}
void push(stack &s, char data){
    if(isFull(s)){
        cout << "stack is full\n";
    }
    else{
    s.arr[++s.top] = data;
    }
}
char pop(stack &s){
    if(isEmpty(s)){
        cout << "stack is empty\n";
        return '\0';
    }
    else{
        return(s.arr[s.top--]);
    }
}
int precedence(char &a){
    if(a == '*' || a == '/'){
        return 2;
    }
    else if(a == '+' || a == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int evaluatePostfix(string &input, stack &st, int &result){
    for(int i=0; i<input.length(); i++){
        if(input[i] >='0' && input[i] <= '9'){
            push(st, input[i] - '0');
        }
        else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            char a = pop(st);
            char b = pop(st);
            if(input[i] == '+'){
                result = b + a;
            }
            if(input[i] == '-'){
                result = b - a;
            }
            if(input[i] == '*'){
                result = b * a;
            }
            if(input[i] == '/'){
                result = b / a;
            }
            push(st,result);
        }
    }
    return result;
}
int main(){
    stack st;
    init(st);
    int answer;
    string input;
    cout<<"Enter postfix expression\n";
    getline(cin,input);
    cout << "the evaluation of your postfix expression is: " << evaluatePostfix(input, st, answer) << "\n";

}