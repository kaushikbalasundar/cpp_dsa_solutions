#include<string>
#include<iostream>
#include<set>

using namespace std;

// return a set of unique strings 

//sets are like maps without the value part - just the keys. Sets store elements in ordered/sorted fashion
// time complexity for accessing any element in the set is O(log(n)). If we dont care about the ordering and 
// just want to know if an element exists or not, you can use unordered set, which has element access
//time complexity as O(1) instead. 
void print(set <string> s)
{
    cout << "unique elements are : " << endl;
    for (auto str: s){
        
        cout << str << endl;
    }
}
int main(){

    set<string> s;
    
    string str = "";
    
    while(str!="d"){
        cout << "Enter string : \n " ;
        cin >> str; 
        
        if(str!="d"){
        s.insert(str);}
    }

    print(s);

    //find some element
    str = "";
    cout << "here" << endl;
    while(str!="q"){

        cout << "Enter element to find, q to exit: "; 
        if (str!="q"){
            cin >> str;
            auto it = s.find(str);

            if(it != s.end()){
                cout << "Element exists! " << endl; 
            }
            else{
                cout << "Element not found!" << endl;
            }
        }
    } 


    return 0;
}