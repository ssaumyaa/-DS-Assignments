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
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void sortArray(int &n, int array[]){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
}
int countPairs(int &n, int array[], int k){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(array[i]-array[j] == k || array[j]-array[i] == k){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int arr[50], size;
    createArray(size, arr);
    sortArray(size, arr);
    int difference;
    cout << "enter target difference: \n";
    cin >> difference;
    cout << "the number of pairs with difference " << difference << " is: " << countPairs(size, arr, difference);
}
