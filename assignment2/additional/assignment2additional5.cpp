#include<iostream>
using namespace std;
void createArray(int arr[], int &size){
    cout << "enter size of array\n";
    cin >> size;
    cout << "enter elements of array: \n";
    for(int i=0 ; i<size; i++){
        cin >> arr[i];
    }
}
void doubleTwos(int arr[], int &size){
    for(int i=0; i<size; i++){
        if(arr[i] == 2){
            for(int j=size; j>i; j--){
                arr[j] = arr[j-1];
            }
            i++;
        }
    }
}
void displayArray(int arr[], int size){
    cout << "modified array is: \n";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}
int main (){
    int array[20], n;
    createArray(array, n);
    doubleTwos(array, n);
    displayArray(array, n);
    return 0;
}