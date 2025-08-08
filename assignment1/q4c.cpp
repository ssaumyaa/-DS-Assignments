#include<iostream>
using namespace std;
void createArray(int &r, int &c, int array[][20]){
    cout << "enter number of rows: "<<endl;
    cin>>r;
    cout << "enter number of columns : "<<endl;
    cin>>c;
    cout << "enter the elements of the array";
    for(int i = 0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>array[i][j];
        }
    }
}
void displayArray(int &r, int &c, int array[][20]){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void transposeMatrix(int &r, int &c, int array[][20]){
    for(int i=0; i<r; i++){
        for(int j=i; j<c; j++){
            swap(array[i][j] , array[j][i]);
        }
    }
}
int main(){
    int arr[20][20], rows, columns; 
    createArray(rows, columns, arr);
    cout << "the original array was: "<<endl;
    displayArray(rows, columns, arr);
    transposeMatrix(rows, columns, arr);
    cout << "the transpose of the matrix is: "<<endl;
    displayArray(rows, columns, arr);
    return 0;
}
