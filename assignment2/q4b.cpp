#include<iostream>
using namespace std;

void createString(char str[], int size){
    cout << "enter your string: \n";
    cin.getline(str, size);
}

void displayString(char str[]){
    cout << str;
}

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}
int findSize(char str[]){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}
void reverseString(char str[], int &size){
    int i=0; int j=size-1;
    while(i<j){
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

int main(){
    char str[50]; int size=0;
    createString(str, 50);
    size = findSize(str);
    reverseString(str, size);
    cout << "the reverse of your string is: ";
    displayString(str);
    return 0;
}
