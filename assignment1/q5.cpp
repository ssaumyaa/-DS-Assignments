#include <iostream>
using namespace std;
void createArray(int &r, int &c, int array[][20]){
    cout << "enter number of rows: "<<endl;
    cin>>r;
    cout << "enter number of columns : "<<endl;
    cin>>c;
    cout << "enter elements of the array"<<endl;
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
int rowsum(int &r, int &c, int array[][20], int sum){
    int rowno; sum=0;
    cout << "enter row number : "<<endl;
    cin >> rowno;
    for(int j=0; j<c; j++){
        sum += array[rowno-1][j];
    }
    return sum;
}
int columnsum(int &r, int &c, int array[][20], int sum){
    int columnno; sum=0;
    cout << "enter column number : "<<endl;
    cin >> columnno;
    for(int i=0; i<r; i++){
        sum += array[i][columnno-1];
    }
    return sum;
}
int main(){
    int arr[20][20], rows, columns, rsum=0, csum=0; 
    createArray(rows, columns, arr);
    cout << "the array is: " << endl;
    displayArray(rows, columns, arr);
    csum = columnsum(rows, columns, arr, csum);
    cout << "the sum of your column number is: "<<csum<<endl;
    rsum = rowsum(rows, columns, arr, rsum);
    cout << "the sum of your row number is: "<<rsum<<endl;
    return 0;
}
