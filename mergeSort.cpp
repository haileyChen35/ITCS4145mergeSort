#include<iostream>
#include <vector>
#include <random>


using namespace std;

vector<int> merge(vector<int> a, vector<int>b){
    vector<int> c;

    while(a.size() > 0 && b.size() > 0){
        if(a[0] > b[0]){
            c.push_back(b[0]);
            b.erase(b.begin() + 0); // remove the element at index 0, remove a[0] from a 
        }else{
            c.push_back(a[0]);
            a.erase(a.begin() + 0); // remove the element at index 0, remove b[0] from b
        } 
    }

    // at this point either a or b is empty 

    while(a.size() > 0){
        c.push_back(a[0]);
        a.erase(a.begin()+0); // remove a[0] from a 
    }

    while(b.size() > 0){
        c.push_back(b[0]);
        b.erase(b.begin()+0); // remove b[0] from b
    }

    return c;
}

vector<int> mergeSort(vector<int> a){
    if(a.size() == 1){
        return a;
    }

    vector<int> arrayOne;
    vector<int> arrayTwo;
    for(int i = 0; i < a.size()/2; i++){
        arrayOne.push_back(a[i]);
    }
    for(int i = a.size()/2; i<a.size();i++){
        arrayTwo.push_back(a[i]);
    }

    arrayOne = mergeSort(arrayOne);
    arrayTwo = mergeSort(arrayTwo);

    return merge(arrayOne, arrayTwo);
}

vector<int> generateArr(int size){
    vector<int> arr(size);

    // Define range
    int min = 1;
    int max = 10000;

    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    for(int& value : arr){ // Use reference here!!!!!!
        value = distrib(gen);
    }

    return arr;
}

int main(){

    while(true){

    clock_t start, end;
    double time;
    vector<int> arr;
    int x;

/** Ask for size input*/

    cout<<"Enter the array size: ";
    cin >> x;
    cout<<"The array size is: "<< x <<endl;

    arr = generateArr(x);

    start = clock();
    
    arr = mergeSort(arr);

    end = clock();

    time = (double)(end-start) / CLOCKS_PER_SEC;

    cout << "execution time for an array size of " << arr.size() <<": ";
    cout << time << " seconds" << endl;

    }

    return 0;


/** ======================== This is for testing purpose */

    // std::cout << "Values in the vector before merge sort:" << std::endl;
    // for (int i = 0; i < arr.size(); i++) {
    //     std::cout << arr[i] << " "; 
    // }
    // arr = {2,8,5,3,9,4,1,7};
    // arr = mergeSort(arr);
    // std::cout << "After merge sort:" << std::endl;
    // for (int i = 0; i < arr.size(); i++) {
    //     std::cout << arr[i] << " "; 
    // }  
}

