#include<iostream> 
#include<vector> 
#include<unordered_set> 
#include<algorithm>
using namespace std; 


//find the longest band in a given array of integers 

//Input: {1,9,3,0,5,2,4,10,7,12,6}

//Output: 8 {0,1,2,3,4,5,6,7}

int longestBand(vector<int> arr){

    int result = 0;
    unordered_set<int> os;
    for(int element : arr){
        
    os.insert(element);
        
}

    for(auto element: os){ //note that you can iterate through an unordered set like this. You looked this up. 

        int parent = element -1 ; // find the root of a sequence 
        if(os.find(parent)==os.end()){ // if root is found 

            int count = 1;  // start counting 
            int next_element = element + 1; //find next element 
            while(os.find(next_element)!=os.end()){ //keep incrementing as long as the sequence holds 
                count++;
                next_element++;

            }

            if(count > result){// update maximum sequence found till now 
                result = count;
            }

        }
    }

    return result; //return maximum sequence 

}


int main(){
    
    int result = longestBand({1,9,3,0,5,4,10,7,12,6});
    cout << "The longest band is: " << result << endl;
    return 0;
}