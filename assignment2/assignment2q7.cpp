#include<iostream>
using namespace std;
int createArray(int &n, int array[]){
    cout << "enter size of array: \n";
    cin>>n;
    cout << "enter elements of the array : \n";
    for(int i = 0; i<n; i++){
        cin >> array[i];
    }
    return n;
}
int countInversions(int size, int array[]){
    int k = 0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(array[i] > array[j]){
                k++;
            }
        }
    }
    return k;
}
int main(){
    int size = 0, arr[50];
    size = createArray(size, arr);
    cout << "number of inversions in the array is: " << countInversions(size,arr) << "\n";
    return 0;
}