#include<iostream>
#include<limits>
//function of linear search
int linearSearch(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i] ==  key){
            return i;
        }
    }
    return -1;
}
//function of binary search
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int index = (end - start)/2;
    int count = 0;
    while(start!=end){
        if(arr[index] ==  key){
            return index;
        }
        else if(arr[index] > key){
            end = index;
            index = (end - start)/2;
        }
        else if(arr[index] < key){
            start = index;
            index = start + (end - start)/2 + 1;
        }
        count++;
    }
    return -1;
}
//function of bubble sort
void bubbleSort(int arr[], int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j = i;j<size;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int valid(int num){
    while(true){
        std::cin>>num;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<< "Invalid input! please try again"<<std::endl;
        }
        else{
            return num;
        }
    }   
}
int main(){
    int arr[10];
    std::cout<< "Array: ";
    for(int i=0;i<10;i++){
        arr[i] = rand()%100;
        std::cout<< arr[i] <<"\t";
    }
    std::cout<< std::endl;
    int key;
    std::cout<< "Enter the value you are looking for: ";
    key = valid(key);
    //linear search function
    int index = linearSearch(arr,10,key);
    if(index == -1){
        std::cout<< "The value you are looking for dosent exist in the array"<<std::endl;
    }
    else{
        std::cout<< "The value "<<arr[index]<< " exist at position "<< index + 1<<std::endl;
    }
    //bubble sort function(the list has to be ordered befor operating binary search)
    bubbleSort(arr, 10);
    std::cout<<"Array after sorting: ";
    for(int i=0;i<10;i++){
        std::cout<<arr[i] <<"\t";
    }
    std::cout<< std::endl;
    //binary search fucntion
    std::cout<< "Enter the value you are looking for: ";
    key = valid(key);
    index = binarySearch(arr, 10, key);
    if(index ==  -1){
        std::cout<< "The value you are looking for doesnt exist in the list."<<std::endl;
    }
    else{
        std::cout<< "The value "<<arr[index]<< " exists at position "<<index + 1<<std::endl; 
    }
    
    index = binarySearch(arr, 10,key);
    
}