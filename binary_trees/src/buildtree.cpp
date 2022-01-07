#include "../include/buildPOBinaryTree.h"

int main(){
    
    node n;
    
    node* root = n.levelOrderBuild();
    cout << "Built Tree!" << endl; 
    n.levelOrderPrint(root);
    // int h = n.height(root);
    // cout << "The height of the tree is: " << h << endl; 
    // if(n.heightBalancedTree(root)){
    //     cout << "The tree is balanced!" << endl;
    // }
    // else {
    //     cout << "The tree is unbalanced" << endl;
    // }


    // pair <int, bool> p = n.heightBalancedTreeOptimized(root);

    // if(p.second){
    //     cout << "The tree is balanced!" << endl;
    // }
    // else {
    //     cout << "The tree is unbalanced" << endl;
    // }
    
    // pair<int, int> p1 = n.maxSubsetSum(root); 

    // int max_sum = max(p1.first, p1.second);
    // cout << "The maximum subset sum is: " << max_sum << endl;

    // int k = 1;
    // // n.printAtLevelK(root, k);
    // node * target_node = root -> right;
    // cout << "K from target node: " << target_node ; 
    // n.distKfromTarget(root, k, target_node);
    // cout << "Same vertical height: "<< endl;
    // n.nodesAtSameVerticalHeight(root);
    cout << "Sum of descendants" << endl; 
    n.sumDescendents(root);
    n.levelOrderPrint(root);
    int d = n.diameter(root);
    cout << "The diameter is: " << d << endl;
    return 0;

}