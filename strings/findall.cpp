#include<iostream>
#include<string> 
#include<vector>
using namespace std;


void printVector(vector<int> vec){

    for(int i=0; i<vec.size(); i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

//find all occurances of a word in a string 
int main(){

    string word = "hello"; 
    vector<int> indices; 
    string sentence = "hello hello hello is there anybody in there... Hello is anyone home?";

    int index = sentence.find(word);
    while(index!=-1){
        indices.push_back(index);
        index = sentence.find(word, index+1); //you can specify where to start searching from as well
    }

    printVector(indices);
    

    return 0;
}