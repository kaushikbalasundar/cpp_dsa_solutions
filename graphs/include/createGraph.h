/*
AUTHOR: Kaushik Balasundar (kbalasun@cs.cmu.edu)
Description: Header file to create a pre-order build binary tree
*/

#include <list> //Linked lists from STL 
#include <iostream>
#include <queue> 
using namespace std;
class Graph{

    //vertices
    int V; 
    //pointer to linked list representing connected nodes
    list<int> *l;

public:

    //default constructor 
    Graph() = default;

    //constructor 
    Graph(int v){
     V = v;
     //create an array of linked list dynamically according to the size the user specifies    
     l = new list<int>[V];
    }

    //create an edge between two nodes in the graph 
    void createEdge(int a, int b, bool dir=false){
        
        l[a].push_back(b);

        if(!dir){ //if undirected, create connection in the oppposite direction as well 
            l[b].push_back(a);
        }
    }

    void printAdjList(){

        for (int i=0; i<=V; i++){
            
            cout << i << ": " ;
            for (auto element:l[i]){

                cout << element << " "; 
            }

            cout << endl;
        } 


        }

    void bfs(int source){

        //create a queue 
        queue <int> q; 

        //create a visited array of booleans initialized with 0s
        bool *visited = new bool[V]{0}; 

        //push the first element of the graph into the queue 
        q.push(source);

        //then mark it as being visited 
        visited[source] = true;

        //iterate through the queue and pop out the first element and print it 
        while(!q.empty()){

            int f = q.front();
            q.pop();
            std::cout << f << endl;

            //iterate through the neighbours of source 
            for(auto nbr: l[f]){

                if(!visited[nbr]){
                    //if not visited, mark as visited
                    visited[nbr] = true;
                    //push to queue
                    q.push(nbr); 
                }
            }

        }

        return;

        }
    
        
};


