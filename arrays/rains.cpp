//find the volume of water stored in a structure, whose various block heights are given by the number in the array

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

int rains(vector<int> arr){
    int vol = 0;
    int n = arr.size();
    vector<int>maxLeftArr(n,0);  // note how a constructor is used to set all elements of an n-sized vector with 0s
    vector<int> maxRightArr(n,0); 
    
    
    maxLeftArr[0] = arr[0];
    maxRightArr[n-1] = arr[n-1];
    if(n<3){return 0;} //no water can be stored if the number of elements is 2 or less

    for(int i = 1; i<n; i++){

        maxLeftArr[i] = max(maxLeftArr[i-1], arr[i]);
        maxRightArr[n-i-1] = max(maxRightArr[n-1], arr[n-1-i]);
    }

    for(int i = 1; i<n; i++){

        vol += min(maxLeftArr[i], maxRightArr[i]) - arr[i];
    }

    return vol;
}

int main(){

    int vol = rains({0,1,0,2,1,3,0,1,0});
    cout << "The volume of water stored is: " << vol << endl;
}