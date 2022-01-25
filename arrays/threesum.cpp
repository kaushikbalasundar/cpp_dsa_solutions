//given an array, find a set of three numbers that add up to a sum S. 

//sort each triplet

#include<iostream> 
#include<vector> 
#include<unordered_set> 
#include <algorithm>

using namespace std; 

vector< vector<int> > triplets(vector <int> arr, int targetSum){

    //sort the array 
    sort(arr.begin(), arr.end());
    int currentSum = 0;
    vector <vector<int> > tripletsSet; 
    vector <int> triplet;

    //iterate through sorted array with three pointers 
    int n = arr.size();
    for (int i=0; i<=n-3; i++){
        currentSum = 0;
        currentSum += arr.at(i); 

        int j = i+1; //one element after i 
        int k = n-1; //last element 
        cout << "i: " << i << " j: " << j << " k: " << k << endl;
        while(j<k){ //while the pointers dont meet each other 
            
            currentSum += arr.at(j);
            currentSum += arr.at(k);
            cout << currentSum << endl;

            if(currentSum == targetSum){

                triplet.push_back(arr.at(i));
                triplet.push_back(arr.at(j));
                triplet.push_back(arr.at(k));
                tripletsSet.push_back(triplet);
                
                j++; 

            }

            else if (currentSum < targetSum){
                j++;
            }

            else{ 
                k--;
            }
        }


    }

    //sort(tripletsSet.begin(), tripletsSet.end());
    return tripletsSet;

}

int main(){

    vector <vector<int> > result = triplets({0,0,1,1,3,4,5,6}, 6);

    for (auto triplet: result){

        for (int element: triplet){
            
            cout << element << " ";

        }

        cout << endl;
    }

    return 0; 
}


