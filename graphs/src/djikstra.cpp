#include<vector>
#include<set>
#include<iostream>
#include<list>

using namespace std; 

class Graph{

public:

    int V; //no of vertices 
    list<pair <int,int>> *l;
    //constructor 
    Graph(int v){
        V= v;
        l = new list< pair <int,int>> [V];
    }


    //add edges to a weighted graph

    void addEdge(int src, int dest, int weight, bool directed=false){

        pair <int,int> p; 
        p.first = dest; 
        p.second = weight;
        l[src].push_back(p);

        if(!directed){

            p.first = src;
            l[dest].push_back(p);
        }
    }

    void printGraph(){

        for (int i=0; i<V; i++){
            
            cout << i << " : ";
            for(auto nbr: l[i]){
                
                cout << nbr.first << "{" << nbr.second << "}" << " "; 

            }
        
            cout << endl;
        }
    }


};

int main(){

    Graph g(5); 

    g.addEdge(0,1,1); 
    g.addEdge(1,2,1);
    g.addEdge(1,3,2);
    g.addEdge(2,3,3);
    g.addEdge(2,4,4);

    g.printGraph();


    return 0;
}