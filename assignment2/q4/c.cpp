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

char removeVowels(char str[], int &size){
    for(int i=0; i<size; i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] =='u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] =='U'){
            for(int j=i; j<size; j++){
                str[j] = str[j+1];
            }
            size--;
            i--;
        }
        else{
            continue;
        }
    }
    return str[size];
}

int main(){
    char str[50]; int size=0;
    createString(str, 50);
    size = findSize(str, size);
    str[size] = removeVowels(str, size);
    cout << "your string without vowels: ";
    displayString(str);
    return 0;
}
