#include<iostream>
using namespace std;
void createString(char str[], int size){
    cout << "enter your string: \n";
    cin.getline(str, size);
}
int findSize(char str[]){
    int i=0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}
void swap(char &a, char &b){
    char temp = a; 
    a = b;
    b = temp;
}
void sortString(char str[], int &size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(str[j]>str[j+1]){
                swap(str[j], str[j+1]);
            }
        }
    }
}
void checkAnagram(int &size1, int &size2, char str1[], char str2[]){
    if(size1==size2){
        for(int i=0; i<size1; i++){
            if(str1[i] != str2[i]){
                cout << "not an anagram pair \n";
                return;
            }
    }
    cout << "is an anagram pair \n";
}
    else{
        cout << "not an anagram pair. \n";
    }
}

int main(){
    char string1[50],string2[50]; int size1,size2;
    createString(string1, 50);
    size1 = findSize(string1);
    createString(string2, 50);
    size2 = findSize(string2);
    sortString(string1, size1);
    sortString(string2, size2);
    checkAnagram(size1, size2, string1, string2);
}
