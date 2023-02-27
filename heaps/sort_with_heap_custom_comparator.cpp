#include <iostream>
#include <queue> 

class Compare {
    public:
        bool operator()(int a, int b){
            return a > b;
        }
};

int main(){

    int arr[] = {1, 5,18,9,99};
    int n = sizeof(arr) / sizeof(int);

    std::priority_queue<int, std::vector<int>, Compare> q; 
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