#include<iostream>
#include<string> 
#include<vector>


using namespace std;

//Given an array, return the indices of a contiguous sub-array whose sum equals k. 

void printVectorPairs(vector<pair <int,int> >vec){

    for(int i=0; i<vec.size(); i++){
        cout << vec.at(i).first << " " << vec.at(i).second;
        cout << endl;
    }
    
}

vector<pair<int,int> > plots(vector< int > arr, int targetSum){


    int i = 0;
    int j = 0;
    int currentSum = 0;
    vector<pair<int,int>> res;

    while (i <= j && j < arr.size()){

        cout << "i: " << i << " " << "j: " << j << " " << "Current Sum: " << currentSum << endl;
        if(currentSum == 0){
        currentSum += arr[i];        
        }

        if(currentSum == targetSum){
            
            pair <int,int> p = make_pair(i,j);
            res.push_back(p);
            j++;
            currentSum += arr[j];
        }

        if(currentSum < targetSum && j < arr.size()-1){
            
            j++;
            currentSum += arr[j];
        }

        if(currentSum > targetSum && i < arr.size()-1){
            
            currentSum -= arr[i];
            i++;
        }
        if(j == arr.size() - 1 && currentSum < targetSum){
            break;
        }
    }

    return res;
}

int main(){


    vector<int> arr = {1,4,1,6,5,3,2,1};
    int targetSum = 51;
    vector<pair<int,int> > res = plots(arr, targetSum);
    printVectorPairs(res);
    if(res.size() == 0){
        cout << "No solution found!" << endl;
    }

    return 0;
}