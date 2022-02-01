#include<iostream>
#include<vector>

using namespace std;

//find the number of ways to get to the top of a ladders if you can reach any step by jumping either 1,2 or 3 steps

 int numSubsets(vector<int> arr, int size, int start, int targetSum){

        //base case 
        if (start == size){
             if(targetSum == 0){

            return 1;
        }
        return 0;
        }
       

        int inc_current_element = numSubsets(arr, size, start+1, targetSum-arr[start]);
        int exc_current_element = numSubsets(arr, size, start+1, targetSum);
        return inc_current_element+ exc_current_element;
    }


int main(){

    vector<int> arr  = {1,2,3,4,5};
    int subsets = numSubsets(arr, arr.size(), 0, 10);
    cout << "The number of subsets are: " << subsets << endl;
    return 0;
}