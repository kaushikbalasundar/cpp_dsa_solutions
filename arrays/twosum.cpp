//given an array, find a pair of numbers that add up to a sum S. 

#include<iostream> 
#include<vector> 
#include<unordered_set> 

using namespace std; 
unordered_set<int> s; 

void twosum(int sum, vector<int> arr){

    for (int i=0; i<arr.size(); i++){

        int target = sum - arr[i];
        cout << "target is: " << target << endl;

        
        if(s.find(target) == s.end()){ //s.find(target) returns iterator to the element if found, and to s.end() if not found
            s.insert(arr[i]);
        }

        else{
            cout << "The pair is : " << arr[i] << " and " << target <<endl; 
            return; 
        } 
    }

    cout << "No pair found" << endl;
    return; 

}

int main(){
    vector<int> arr = {-1,4,5,6,-1,2};
    int target_sum = 11;
    twosum(target_sum, arr);
    return 0;
}