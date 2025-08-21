#include<iostream>
using namespace std;
void createArray(int &n, int array[]){
    cout << "enter size of array: \n";
    cin>>n;
    cout << "enter elements of the array : \n";
    for(int i = 0; i<n; i++){
        cin >> array[i];
    }
}
int countDistinctElements(int &n, int array[]){
    int k=0,j;
    for(int i=0; i<n; i++){
        for(j=0; j<i; j++){
            if(array[i] == array[j]){
                break;
            }
        }
        if(i==j){
            k++;
        }
    }
    return k;
}
int main(){
    int size, arr[50];
    createArray(size, arr);
    cout << countDistinctElements(size, arr);
}