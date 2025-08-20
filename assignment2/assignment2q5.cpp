#include<iostream>
using namespace std;
void createDiagonalMatrix(int &rows, int &columns, int array[50]){
    cout << "enter number of rows \n";
    cin >> rows;
    cout << "enter number of columns \n";
    cin >> columns;
    if(rows==columns){
    cout << "please enter non-zero numbers in your diagonal matrix in row major order: \n";
    for(int i=0; i<rows; i++){        
    cin >> array[i];
    }
    }
    else{
        cout << "diagonal matrix must be square \n";
}
}
void createTridiagonalMatrix(int &rows, int &columns, int array[50]){
cout << "enter number of rows \n";
    cin >> rows;
    cout << "enter number of columns \n";
    cin >> columns;
    if(rows==columns){
    cout << "please enter non-zero numbers in your tridiagonal matrix in row major order: \n";
    for(int i=0; i<3*rows-2; i++){        
    cin >> array[i];
    }
    }
    else{
        cout << "diagonal matrix must be square \n";
}
}
void createLowerTriangularMatrix(int &rows, int &columns, int array[50]){
    cout << "enter number of rows \n";
    cin >> rows;
    cout << "enter number of columns \n";
    cin >> columns;
    if(rows==columns){
    cout << "please enter non-zero numbers in your lower triangular matrix in row major order: \n";
    for(int i=0; i<rows*(rows+1)/2; i++){        
    cin >> array[i];
    }
    }
    else{
        cout << "diagonal matrix must be square \n";
}
}
void createUpperTriangularMatrix(int &rows, int &columns, int array[50]){
       cout << "enter number of rows \n";
    cin >> rows;
    cout << "enter number of columns \n";
    cin >> columns;
    if(rows==columns){
    cout << "please enter non-zero numbers in your upper triangular matrix in row major order: \n";
    for(int i=0; i<rows*(rows+1)/2; i++){        
    cin >> array[i];
    }
    }
    else{
        cout << "diagonal matrix must be square \n";
}
}
void createSymmetricMatrix(int &rows, int &columns, int array[50]){
       cout << "enter number of rows \n";
    cin >> rows;
    cout << "enter number of columns \n";
    cin >> columns;
    if(rows==columns){
    cout << "please enter upper triangular non-zero numbers in your symmetric matrix in row major order: \n";
    for(int i=0; i<rows*(rows+1)/2; i++){        
    cin >> array[i];
    }
    }
    else{
        cout << "diagonal matrix must be square \n";
}
}

void displayDiagonalMatrix(int rows, int columns, int array[50]){
    if(rows==columns){
        int k = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(i==j){
            cout << array[k] << " ";
            k++;
    }
    else{
        cout << "0 ";
    }
}
cout << "\n";
}
}
else{
    return;
}
return;
}
void displayTridiagonalMatrix(int rows, int columns, int array[50]){
    if(rows==columns){
    int k = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(i==j || i-j == 1 || i-j == -1){
            cout << array[k] << " ";
            k++;
    }
    else{
        cout << "0 ";
    }
}
cout << "\n";
}
}
else{
    return;
}
return;
}
void displayLowerTriangularMatrix(int rows, int columns, int array[50]){
    if(rows==columns){
    int k = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(i>=j){
            cout << array[k] << " ";
            k++;
    }
    else{
        cout << "0 ";
    }
}
cout << "\n";
}
}
else{
    return;
}
return;
}
void displayUpperTriangularMatrix(int rows, int columns, int array[50]){
    if(rows==columns){
        int k = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(i<=j){
            cout << array[k] << " ";
            k++;
    }
    else{
        cout << "0 ";
    }
}
cout << "\n";
}
}
else{
    return;
}
return;
}
void displaySymmetricMatrix(int rows, int columns, int array[50]){
    if(rows==columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(i<=j){
            int k = i*rows - i*(i-1)/2 + j-i ; 
            cout << array[k] << " ";
            }
            else{
            int k = j*rows - j*(j-1)/2 + i-j ; 
            cout << array[k] << " ";
            }
}
cout << "\n";
}
}
else{
    return;
}
return;
}
int main(){
    int r,c,arr[50];
    createSymmetricMatrix(r,c,arr);
    displaySymmetricMatrix(r,c,arr);
    return 0;
}