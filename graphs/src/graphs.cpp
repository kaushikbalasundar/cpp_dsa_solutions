/*
AUTHOR: Kaushik Balasundar (kbalasun@cs.cmu.edu)
Description: Header file to create a pre-order build binary tree
*/

#include "../include/createGraph.h"
#include <iostream>
using namespace std;


int main(){
    Graph g(5);
    g.createEdge(0,1);
    g.createEdge(1,2);
    g.createEdge(1,3);
    g.createEdge(3,2);
    g.createEdge(2,4);
    cout << endl;
    g.printAdjList();
    
    // g.dfs(0);
    return 0; 
}
