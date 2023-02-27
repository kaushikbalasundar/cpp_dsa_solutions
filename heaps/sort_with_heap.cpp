#include <iostream>
#include <queue> 

int main(){

    int arr[] = {1, 5,18,9,99};
    int n = sizeof(arr) / sizeof(int);

    std::priority_queue<int, std::vector<int>, std::greater<int> > q; 
    for (int i : arr){
        q.push(i);
    }

    //Print the elements
    while(!q.empty()){
        std::cout << q.top() << ", "; 
        q.pop();
    }

    return 0;
}