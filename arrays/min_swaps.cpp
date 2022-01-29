#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std; 

int minSwaps(vector<int> arr){


    // we need to first sort the array to know what the actual positions of the elements need to be 
    int n = arr.size();
    pair<int,int> ap[n]; //making an array of pairs containing the element and its index
    for (int i=0; i<arr.size(); i++){ //populate elements into the array of pairs 
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    //now sort the array of pairs 
    sort(ap, ap+n);
    vector<bool> visited(n,false); //creating a visited array to keep track of which nodes we have visited so far 

    int res = 0;    //no of swaps = cycles - 1
    //iterate through the array until a
    for(int i=0; i<n; i++){
        int cycles = 0;
        int node = i;
        if(visited[i]==true or ap->second == i) {//if node is visited or the element is in its original position continue 
            continue;}
        

        while(!visited[node]){
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycles+=1;

        }

        res += cycles -1;

        }
    
    return res;
}


int main(){

    int minswaps = minSwaps({10,11,5,4,3,2,1});
    cout << "The minimum number of swaps is: " << minswaps << endl;

    return 0;
}