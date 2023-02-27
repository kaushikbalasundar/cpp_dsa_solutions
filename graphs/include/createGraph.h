/*
AUTHOR: Kaushik Balasundar (kbalasun@cs.cmu.edu)
Description: Header file to create a pre-order build binary tree
*/

#include <list> //Linked lists from STL 
#include <iostream>
#include <queue> 
#include <vector>

using namespace std;
class Graph{

public:

    int size_;
    vector<list<int>> nodes_;

    //constructor 
    Graph() = default; 

    //Alternate constructor 
    Graph(int size){
        size_ = size;
        nodes_ = vector<list<int>>(size);
    }

    //create an edge between two nodes in the graph 
    void createEdge(int a, int b, bool dir=false){

        nodes_[a].push_back(b);
        if(!dir){
            nodes_[b].push_back(a);
        }
       
    }

    void printAdjList(){

        for(int i=0; i<size_; i++){
            for(int node: nodes_[i]){
                std::cout << node << ", ";
            }
            std::cout << std::endl;
        }
    }


    void bfs(int source, int dest=-1){

        return; 

        }

        void dfs_helper(int source, bool* visited){

        }

        void dfs(int source){

        }
    
        
};


