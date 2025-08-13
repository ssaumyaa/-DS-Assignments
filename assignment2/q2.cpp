#include<iostream>
using namespace std;
void createArray(int &n, int array[]){
    cout<<"enter number of element in array: \n";
    cin>>n;
    cout<<"enter elements of the array";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
}
void displayArray(int &n, int array[]){
    cout<<"the array is: ";
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(int &n, int array[]){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
        if(array[j]>array[j+1]){
            swap(array[j], array[j+1]);
        }
        else{
            continue;
        }
        }
    }
}

int main (){
    int arr[7] = {64, 34, 25, 12, 22 ,11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(size,arr);
    displayArray(size,arr);
    return 0;
}
