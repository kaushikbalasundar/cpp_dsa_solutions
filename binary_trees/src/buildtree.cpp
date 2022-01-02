#include "../include/buildPOBinaryTree.h"

int main(){
    
    node n; 
    node* root = n.levelOrderBuild();
    cout << "Built Tree!" << endl; 
    n.levelOrderPrint(root);
    return 0;

}