#include <iostream>
using namespace std;
void create(int &elements, int array[])
{
    cout << "enter size of the array" << endl;
    cin >> elements;
    cout<<"enter elements of the array one by one";
    for (int i = 0; i < elements; i++)
    {
        cin >> array[i];
    }

}

void display(int elements, int array[]){
    cout<<"the elements of the array are: ";
    for(int i=0;i<elements; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

}

void insert(int size, int index, int number, int array[]){
    cout<<"enter index"<<endl;
    cin>>index;
    cout<<"enter number to be inserted: "<<endl;
    cin>>number;
    for(int i=size; i>index; i--){
        array[i]=array[i-1];
    }
    array[index] = number;
}

void deleteElement(int size, int number, int array[]){
    cout<<"enter number to be deleted: "<<endl;
    cin>>number;
    for(int i=0;i<size;i++){
        if(array[i]!=number){
            continue;
        }
        else if(array[i]==number){
            for(int j=i; j<=size;j++){
                array[i]=array[i+1];
            }
        }

    }
}
void linearSearch(int size, int array[],int target){
    cout<<"enter number to be found"<<endl;
    cin>>target;
    for(int i = 0; i < size; i++){
        if(array[i]==target){
            cout << target <<" found at index "<< i << endl;
            break;
        }
        else if(i==size-1 && array[i] != target){
            cout<<"target has not been found"<<endl;            
        }
        else continue;
    }
}

int main()
{
    int n;
    int arr[n];
    cout<< "1. CREATE"<<endl<<"2. DISPLAY"<<endl<<"3. INSERT"<<endl<<"4. DELETE"<<endl<<"5. LINEAR SEARCH"<<endl<<"6. EXIT"<<endl;
    int option; int i,a,x,b;
    do{
    cout<<"enter option number: "<<endl;
    cin>>option;
    switch(option){
        case 1: create(n, arr);
        break;
        case 2: display(n,arr);
        break;
        case 3: insert(n,i,a,arr);
        break;
        case 4: deleteElement(n+1,x,arr);
        break;
        case 5: linearSearch(n, arr, b);
        break;
        case 6: cout<<"EXITED"<<endl;
    }
} while(option != 6);

    return 0;
}
