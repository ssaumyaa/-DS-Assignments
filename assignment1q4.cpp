#include <iostream>
using namespace std;
void createArray(int &n, int array[]){
    cout << "enter size of array: "<<endl;
    cin>>n;
    cout << "enter elements of the array : "<<endl;
    for(int i = 0; i<n; i++){
        cin >> array[i];
    }
}
void displayArray(int &n, int array[]){
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void reverseArray(int &n, int array[]){
    for(int i=0, j=n-1; i<n/2, j>n/2; i++, j--){
        swap(array[i], array[j]);
    }
}
int main(){
    int arr[50],n;
    createArray(n,arr);
    cout<<"original array was: "<<endl;
    displayArray(n,arr);
    cout<<"the reverse of the array is "<<endl;
    reverseArray(n,arr);
    displayArray(n, arr);
    return 0;
}