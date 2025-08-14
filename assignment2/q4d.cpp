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

void alphabeticalOrder(char str[], int &size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(int(str[j])>int(str[j+1])){
                swap(str[j], str[j+1]);
            }
            else{
                continue;
            }
        }
    }
}
int main(){
    char str[50]; int size=0;
    createString(str, 50);
    size = findSize(str, size);
    alphabeticalOrder(str, size);
    displayString(str);
    return 0;
}
