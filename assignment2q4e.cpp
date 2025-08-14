#include<iostream>
using namespace std;

void createString(char str[], int size){
    cout << "enter your string: \n";
    cin.getline(str, size);
}

void displayString(char str[]){
    cout << str;
}

int findSize(char str[], int &size){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    size = i;
    return size;
}

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}
void upperToLowerCase(char str[], int size){
    for(int i=0; i<size; i++){
        int ascii = int(str[i]);
        if(ascii>=65 && ascii<=90){
            str[i] = char(ascii + 32);
        }
        else{
            continue;
        }
    }
}
int main(){
    char str[50]; int size=0;
    createString(str, 50);
    size = findSize(str, size);
    upperToLowerCase(str, size);
    cout << "your string in lowercase is: ";
    displayString(str);
    return 0;
}