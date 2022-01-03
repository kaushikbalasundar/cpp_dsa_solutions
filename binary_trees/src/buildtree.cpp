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


    pair <int, bool> p = n.heightBalancedTreeOptimized(root);

    if(p.second){
        cout << "The tree is balanced!" << endl;
    }
    else {
        cout << "The tree is unbalanced" << endl;
    }
    
    pair<int, int> p1 = n.maxSubsetSum(root); 

    int max_sum = max(p1.first, p1.second);
    cout << "The maximum subset sum is: " << max_sum << endl;

    return 0;

}