#include<iostream>
using namespace std;
void createArray(int arr[], int &size){
    cout << "enter size of array \n";
    cin >> size;
    cout << "enter elements of array \n";
    for(int i=0; i<size; i++){
        cin >> arr[i];
        if(arr[i] != 0 && arr[i] != 1 && arr[i] != 2){
            cout << "invalid input please try again\n";
            i--;
        }
    }
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void sortArray(int arr[], int &size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void displayArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int array[20], n;
    createArray(array, n);
    sortArray(array, n);
    displayArray(array, n);
    return 0;
}