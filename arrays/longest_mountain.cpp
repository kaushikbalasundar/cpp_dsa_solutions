//find the biggest mountain in a given array of numbers

#include<iostream> 
#include<vector> 
#include<unordered_set> 
#include<algorithm>
using namespace std; 

int biggestMountain(vector<int> nums){

    int cnt = 1;
    int largest = 0;
    

    for(int i=1; i<nums.size()-1; ){ //no update condition! yes, this is possible

        if (nums.at(i) > nums.at(i-1) && nums.at(i) > nums.at(i+1)){
            //peak reached. Count backwards from peak
            cout << "Peak! "<< nums.at(i) << endl;
            cnt = 0;
            int j =i;
            while(j>=1 and nums[j]> nums[j-1]){
                cnt++;
                j--;
            }
            // next count forward from peak
            while(i<nums.size()-1 and nums[i] > nums[i+1]){
                cnt++;
                i++;
            }


            //update largest peak yet
            largest = max(largest, cnt);


        }
        else{
            //explore until the peak is found
            i++;
        }
        
    }
    //return largest peak found
    return largest;
}

int main(){

    int max_element = biggestMountain({5,6,1,2,3,4,5,4,3,2,1,0,1,2,-1});
    cout << "The length of the biggest mountain is: " << max_element << endl;
    
    return 0;
}