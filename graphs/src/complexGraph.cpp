/*
AUTHOR: Kaushik Balasundar (kbalasun@cs.cmu.edu)
Description: Header file to create a pre-order build binary tree
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {

public:

    string city;
    list<string> neighbours;

    Node(string city){
        this -> city = city;
    }

};

class Graph{

    //it needs to contain two elements, one for the name and the other for the address of that node 

    unordered_map<string, Node*> m;

    public:

        //in the previous case we used the constructor to create an arbitrary number of nodes 
        // then we populated those with data elements and created relationships 
        // here we take a vector of cities, and for each city use the Node class to create a node 
        // then for each node, we build its relationships
        Graph(vector <string> cities){

            for (auto city : cities){ 
                m[city] = new Node(city);
            }            
        }

    void addEdge(string cityA, string cityB, bool dir = true){

        //access the neighours element of the node class for city A and add city B.
        // Do it vice verse if directed 

        m[cityA]->neighbours.push_back(cityB);

        if(dir){
            m[cityB]->neighbours.push_back(cityA);

        }
    }

    void printAdjList(){

        for (auto cityPair : m){

            auto city = cityPair.first;
            cout << city << "---> "; 
            Node * node = cityPair.second;
            for (auto nbr : node -> neighbours){
                cout << nbr << " ";
            }
            cout << endl;
        }

    }

};

int main(){

    cout << "Creating complex graph: " << endl;
    cout << endl;
    vector<string> cities = {"Dubai", "Pittsburgh", "Bengaluru", "Chennai", "Baden"};
    Graph g(cities);
    g.addEdge("Chennai", "Bengaluru", false);
    g.addEdge("Bengaluru", "Baden"); 
    g.addEdge("Bengaluru", "Dubai");
    g.addEdge("Dubai","Pittsburgh");
    g.printAdjList();
    return 0;

}






