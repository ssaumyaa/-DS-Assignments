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
void binarySearch(int &n, int array[], int &x){
    cout<<"enter target\n";
    cin>>x;
    int l=0, r=n-1, m;
    bool flag = false;
    while(l<=r){
        m=(l+r)/2;
        if(array[m]<x){
            l=m+1;
        }
        else if(array[m]>x){
            r=m-1;
        }
        else if(array[m]==x){
            cout<<"target found at"<<" "<<m+1<<"\n";
            flag = true;
            break;
        }
    }
    if(flag==false){
        cout<<"target not found\n";
    }
}
int main (){
    int arr[50]; int n; int a;
    createArray(n, arr);
    displayArray(n,arr);
    bubbleSort(n,arr);
    binarySearch(n,arr,a);
    return 0;
}