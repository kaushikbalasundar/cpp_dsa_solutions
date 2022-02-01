#include<iostream>
using namespace std;

//find the number of ways to get to the top of a ladders if you can reach any step by jumping either 1,2 or 3 steps

int countWays(int n){

    //base case 
    if (n<0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    return countWays(n-1) + countWays(n-2) + countWays(n-3);
}

int main(){
    int n;
    cout << "Enter number of stairs: ";
    cin >>  n;
    cout << "The number of ways to reach the nth step is : " << countWays(n) << endl;
}

