#include "../include/buildPOBinaryTree.h"

int main(){
    
    node n; 
    node* root = n.levelOrderBuild();
    cout << "Built Tree!" << endl; 
    n.levelOrderPrint(root);
    int h = n.height(root);
    cout << "The height of the tree is: " << h << endl; 
    if(n.heightBalancedTree(root)){
        cout << "The tree is balanced!" << endl;
    }
    else {
        cout << "The tree is unbalanced" << endl;
    }
    return 0;

}