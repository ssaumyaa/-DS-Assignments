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
        cout<<array[i]<<" "<<"\n";
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
void findMissingNoLinear(int n, int array[]){
    for(int i=0; i<n; i++){
        if(array[i]==i+1){
            continue;
        }
        else{
            cout<<"the missing number is "<<i+1<<"\n";
            break;
        }
    }
}
void findMissingNoBinary(int n, int array[]){
    int l=0, r=n-1, m;
    while(l<=r){
        m = (l+r)/2;
        if(array[m]==m+1){
            l=m+1;
        }
        else{
            r=m-1;
        }
        }
        cout<<"the missing number is "<< l+1;
    }
int main (){
    int arr[50]; int n; int a;
    createArray(n, arr);
    bubbleSort(n,arr);
    displayArray(n,arr);
    findMissingNoBinary(n, arr);
    return 0;
}