#include<iostream>
using namespace std;

void createString(char str[], int size){
    cout << "enter your string: \n";
    cin.getline(str, size);
}

void displayString(char str[]){
    cout << str;
}

void concatenate(char str1[], char str2[], char str3[]){
    int i=0;
    while(str1[i] != '\0'){
        str3[i] = str1[i];
        i++;
    }
    int j=0;
    while(str2[j] != '\0'){
        str3[i+j] = str2[j];
        j++;
    }
    str3[i+j] = '\0';
}
int main(){
    char str1[50], str2[50], str3[100];
    createString(str1, 50);
    createString(str2, 50);
    concatenate(str1, str2, str3);
    cout << "your concatenated string is: ";
    displayString(str3);
    return 0;
}