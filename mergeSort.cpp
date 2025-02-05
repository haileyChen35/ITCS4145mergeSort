#include <iostream>
#include <vector>
#include <random>


using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> c;
    c.reserve(a.size() + b.size());

    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        c.push_back((a[i] <= b[j]) ? a[i++] : b[j++]);
    }

    c.insert(c.end(), a.begin() + i, a.end());
    c.insert(c.end(), b.begin() + j, b.end());

    return c; 
}


vector<int> mergeSort(vector<int>& a){
    if(a.size() == 1){
        return a;
    }

    vector<int> arrayOne(a.begin(), a.begin() + a.size() / 2);
    vector<int> arrayTwo(a.begin() + a.size() / 2, a.end());

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

int main(int argc, char* argv[]){

   

    clock_t start, end;
    double time;
    vector<int> arr;
    int x;

/** Ask for size input*/

    if (argc < 2) {
        cout << "Error: Please provide an integer as input!" << endl;
        return 1;
    }

    x = stoi(argv[1]);
    

    arr = generateArr(x);

    start = clock();
    
    arr = mergeSort(arr);

    end = clock();

    time = (double)(end-start) / CLOCKS_PER_SEC;

    cout << "size: " << arr.size() <<" time: " << time << " seconds" << endl;

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



