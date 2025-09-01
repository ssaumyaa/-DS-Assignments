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
int main(){
    stack oper;
    init(oper);
    string answer;
    string input;
    cout<<"Enter infix\n";
    getline(cin,input);
    for(int i=0;i<input.length();i++){
        char c = input[i];
        if(c>='0' && c<='9' || isalpha(c)){
            answer += c;
        }
        else if(c=='+' || c=='-' || c=='/' || c=='*'){
            while(!isEmpty(oper) && precedence(oper.arr[oper.top]) > precedence(c)){
                answer += pop(oper);
            }
            push(oper, c);
        }
        else if(c == '('){
                push(oper, c);
        }
        else if(c == ')'){
            while(!isEmpty(oper) && peek(oper) != '('){
                answer += pop(oper);
            }
            if(!isEmpty(oper) && peek(oper) == '('){
            pop(oper);
        }
        }
    }
    while (!isEmpty(oper)) {
        answer += pop(oper);
    }
    cout<<answer<<"\n";
}