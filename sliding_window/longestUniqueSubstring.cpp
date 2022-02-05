#include<iostream>
#include<string> 
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

void printVectorPairs(vector<pair <int,int> >vec){

    for(int i=0; i<vec.size(); i++){
        cout << vec.at(i).first << " " << vec.at(i).second;
        cout << endl;
    }

    
    
}


vector<pair<int,int> > longestUniqueSubstr(string s){
    vector<pair<int,int> > res; 
    unordered_map<char, bool> um;

    int i =0, j =0;

    while (i <= j && j < s.length()){

        if(um.size() == 0){
            um.insert({s.at(i), true});
            j++;
            um.insert({s.at(j), true});
        }

        

        

    }
    return res;
}



int main(){


    string s = "kaushikbalasundar";
    int targetSum = 51;
    vector<pair<int,int> > res = longestUniqueSubstr(s);
    printVectorPairs(res);
    if(res.size() == 0){
        cout << "No solution found!" << endl;
    }

    return 0;
}