#include<iostream>
#include<limits>
//function of linear search
int linearSearch(int arr[], int size, int key){
    int count = 0;
    for(int i=0;i<size;i++){
        count++;
        if(arr[i] ==  key){
            std::cout<< "Loop count: "<<count<<std::endl;
            return i;
        }
    }
    return -1;
}
//function of binary search
int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size - 1;
    int index;
    int count = 0;
    while(start<=end){
        count++;
        index = start +  (end - start)/2;
        if(arr[index] ==  key){
            std::cout<< "Loop count: "<<count<<std::endl;
            return index;
        }
        else if(arr[index] < key){
            start =  index + 1;
        }
        else{
            end = index - 1;
        }
    }
    std::cout<< "Loop count: "<<count<<std::endl;
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
    return 0;
}
