#include <iostream>
using namespace std;
void createArray(int &n, int array[]){
    cout << "enter number of elements in array : "<<endl;
    cin >> n; 
    cout << "enter elements of array"<<endl;
    for(int i=0; i<n; i++){
        cin >> array[i];
    }

}
void displayArray(int n, int array[]){
    cout << "the array is: "<< endl;
    for(int i=0; i<n; i++){
        cout << array[i] << " " ;
    }
}
void removeDuplicate(int &n, int array[]){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
                if(array[i]==array[j]){
                    for(int a=j; a<n; a++){
                        array[a] = array [a+1];
                    }
                    n--;
                }
                else{
                    j++;
                }
        }
    }
}
int main(){
    int arr[50], n;
    createArray(n , arr);
    cout << "original array was: "<<endl;
    displayArray(n, arr);
    removeDuplicate(n, arr);
    cout << "array after removing duplicate elements is: "<<endl;
    displayArray(n, arr);
    return 0;
}
