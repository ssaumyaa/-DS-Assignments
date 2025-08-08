#include<iostream>
using namespace std;
void createArray(int &r, int &c, int array[][20]){
    cout << "enter number of rows: "<<endl;
    cin>>r;
    cout << "enter number of columns : "<<endl;
    cin>>c;
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
void multiplyArrays(int &m, int &n, int &p, int &q, int arr1[][20], int arr2[][20], int res[][20]){
    if(n==p){
        for(int i = 0; i<m; i++){
            for(int j=0; j<q; j++){
                res[i][j] = 0;
                for(int k = 0; k<n; k++){
                res[i][j] += arr1[i][k]*arr2[k][j];
                }
            }
        }
    }
    else{
        cout<<"matrices cannot be multiplied"<<endl;
    }
}
int main(){
    int arr[20][20], brr[20][20], row1, column1, row2, column2, res[20][20];
    createArray(row1, column1, arr);
    createArray(row2, column2, brr);
    multiplyArrays(row1, column1, row2, column2, arr, brr, res);
    cout<<"the multiplication of the matrices is: "<<endl;
    displayArray(row1, column2, res);
    return 0;
}
