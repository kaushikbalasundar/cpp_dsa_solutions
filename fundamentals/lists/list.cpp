#include<list>
#include<iostream>
using namespace std; 

// this is an stl implementation of doubly linked lists. 
// if you want singly linked lists, use the stl member forward_list
// insertion and deletion operations in between linked lists are much faster than in vectors, since you don't need to create copies
// memeory allocation is staggered and not sequential 
// common functionalities: push_back, pop_back, push_front, pop_front, sort, remove, merge, reverse, front, back, empty, resize, size

int main(){

list<int> list1 = {5,6,9,1,3,5}; 
list<int> list2 = {12,10,8,6,4}; 
list<int> list3 = {11,10,9,34,1}; 

// sorting elements in the list
list1.push_back(0);
list1.sort();
list1.remove(5);

for(auto element : list1){
    cout << element << " ";
}
    cout <<endl;

// print elements of the list : method 1

for(auto it = list2.begin(); it!=list2.end(); it++){

    cout << *it << " "; 
}   

    cout << endl;

// print elements of the list : method 2

for(auto element : list3){
    cout << element << " ";
}
    cout <<endl;

return 0;
}


