#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std; 

//given most of the elements are sorted in ascending order, a subset of elements are not sorted. Find the smallest subset 
// which when sorted makes the entire array sorted in asceding order 

// input:{0,1,2,3,5,4,6,8,7,9}
// output: {5,4,6,8,7}

void printVector(vector<int> vec){

    for(int i=0; i<vec.size(); i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;
}


bool outofOrder(vector<int> arr, int i){

    int n = arr.size();
    // cout << "Index: " << i <<endl;
    if(i == 0){
    return arr[i] > arr[1];}

    if(i == n-1){
        return arr[i] < arr[i-1];
    } 
    return arr[i]<arr[i-1] or arr[i] > arr[i+1];

}

vector<int> subArraySort(vector<int> arr){

    vector<int> res;
    int smallest = INT_MAX;
    int largest = INT_MIN;

    //find the smallest and largest element that is out of order 
    for (int i=0; i<arr.size(); i++){
        cout << "index : " << i;
        if(outofOrder(arr, i)){
            cout << "Out of order : "<< i << endl;
            smallest = min(smallest, arr[i]);
            largest = max(largest, arr[i]);
        }
    }
        //find index at which the smallest and largest element need to be placed
        cout << "Smallest: "<<smallest;
        cout << "Largest : " << largest;

        int left_idx = 0;
        int right_idx = arr.size()-1;
        while(smallest >= arr[left_idx]){
            
            left_idx ++;}
            
        while(largest <= arr[right_idx]){
                    
                    right_idx--;}

        //How do you slice a vector from index x to index y?: easiest way is to use the copy function 

        auto start = arr.begin() + left_idx; 
        auto end = arr.begin() + right_idx;
        copy(start, end, res.begin());

    return res;
}

int main(){

    vector<int> arr = subArraySort({0,1,2,3,5,4,6,8,7,9});
    cout << "The subarray to be sorted is: " << endl;
    printVector(arr);

    return 0;
}