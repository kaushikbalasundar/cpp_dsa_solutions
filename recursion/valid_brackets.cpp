#include<iostream> 
#include<vector>
#include<string>

using namespace std;

void generateBrackets(string output_string,int n, int open, int close, int i){

    //base case 
    if(i == 2*n){
        cout << output_string << endl;
        return;
    }

    //recursive case 

    if(close < open){
        generateBrackets(output_string + ")", n, open, close + 1, i+1);
    }

    if(open < n){
        generateBrackets(output_string + "(", n, open +1, close, i+1);
    }




}

int main(){
    int n = 5; //number of opening and closing bracket pairs 
    int open = 0;
    int close = 0;
    int i = 0; //keep track of how many characters we've added so far in the output string 
    string output_string = "";
    generateBrackets(output_string, n, open,close, i);
    return 0;
}