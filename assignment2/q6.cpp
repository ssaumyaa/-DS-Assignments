#include<iostream>
using namespace std;
void createMatrix(int &rows, int &columns, int &nonzero, int mat[20][3]){
    cout << "enter number of rows \n";
    cin >> rows;
    cout << "enter number of columns \n";
    cin >> columns;
    cout << "enter number of non-zero elements \n";
    cin >> nonzero;
    mat[0][0] = rows;
    mat[0][1] = columns;
    mat[0][2] = nonzero;
    cout << "enter non zero elements (row, column, element) \n";
    for(int i=1; i<=nonzero; i++){
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2] ;
    }
}
void swapTriplet(int mat[][3], int &rowno){
    int i = rowno; int j = rowno+1;
        for(int k=0; k<3; k++){
            int temp = mat[i][k];
            mat[i][k] = mat[j][k];
            mat[j][k] = temp;
        }
}
void transpose(int &rows, int &columns, int mat[20][3], int transpose[20][3], int nonzero){
    transpose[0][0] = columns;
    transpose[0][1] = rows;
    transpose[0][2] = nonzero;
    for(int i=1; i<=nonzero; i++){
        transpose[i][0] = mat[i][1];
        transpose[i][1] = mat[i][0];
        transpose[i][2] = mat[i][2];
    }
}
void displayMatrix(int nonzero, int mat[20][3]){
    for(int i=0; i<=nonzero; i++){
        for(int j=0; j<3; j++){
            cout << mat[i][j];
        }
        cout<<"\n";
    }
    cout << "\n";
}
int addMatrices(int mat1[20][3], int mat2[20][3], int added[20][3]){
    if(mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1]){
        cout << "dimensions of matrices do not match \n";
    }
    else{
    int r = mat1[0][0];
    int c = mat1[0][1];
    int n1 = mat1[0][2];
    int n2 = mat2[0][2];
    int i=1,j=1,k=1;
    added[0][0] = r;
    added[0][1] = c;
    while(i<=n1 && j<=n2){
    if(mat1[i][0] < mat2[j][0] || mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1]){
        added[k][0] = mat1[i][0];
        added[k][1] = mat1[i][1];
        added[k][2] = mat1[i][2];
        i++; k++;
    }
    else if(mat2[j][0] < mat1[i][0] || mat2[j][0] == mat1[i][0] && mat2[j][1] < mat1[i][1]){
        added[k][0] = mat2[j][0];
        added[k][1] = mat2[j][1];
        added[k][2] = mat2[j][2];
        j++; k++;
    }
    else{
        int sum = mat1[i][2] + mat2[j][2];
        if(sum!=0){
        added[k][0] = mat1[i][0];
        added[k][1] = mat1[i][1];
        added[k][2] = sum;
        k++;
    }
    i++;j++;
}
}
while(i<=n1){
    added[k][0] = mat1[i][0];
    added[k][1] = mat1[i][1];
    added[k][2] = mat1[i][2];
    i++;k++;
}
while(j<=n2){
    added[k][0] = mat2[j][0];
    added[k][1] = mat2[j][1];
    added[k][2] = mat2[j][2];
    j++;k++;
}
added[0][2] = k-1;
}
return added[0][2];
}
void sortMatrix(int nonzero, int matrix[][3]){
    for(int i=1; i<=nonzero; i++){
        for(int j=1; j<=nonzero-i; j++){
        if(matrix[j][0] > matrix[j+1][0] || matrix[j][0] == matrix[j+1][0] && matrix[j][1] > matrix[j+1][1]){
            swapTriplet(matrix, j);
        }
        }
    }
}
void multiplication(int mat1[20][3], int mat2[20][3]){

}
int main(){
    int r,c,n,matrix1[20][3],matrix2[20][3];
    int trans[20][3],res[20][3];
    createMatrix(r,c,n,matrix1);
    sortMatrix(matrix1[0][2], matrix1);
    displayMatrix(n,matrix1);
    createMatrix(r,c,n,matrix2);
    sortMatrix(matrix2[0][2], matrix2);
    displayMatrix(n,matrix2);
    int resNonZero = addMatrices(matrix1,matrix2,res);
    cout << "your resultant matrix is : \n";
    displayMatrix(resNonZero, res);

    return 0;
}
