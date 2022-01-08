/*
AUTHOR: Kaushik Balasundar (kbalasun@cs.cmu.edu)
Description: Header file to create a pre-order build binary tree
*/

#include "../include/createGraph.h"
#include <iostream>
using namespace std;


int main(){
    Graph g(6);
    cout << "here";
    g.createEdge(1,2);
    g.createEdge(1,3);
    g.createEdge(2,4);
    g.createEdge(2,5);
    g.printAdjList();

    // return 0; 
}
