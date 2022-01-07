/*

AUTHOR: Kaushik Balasundar (kbalasun@cs.cmu.edu)
Description: Header file to create a pre-order build binary tree

*/

#include <iostream>
#include <queue> 
#include <map>

using namespace std;

class node{

    public:

        int data; 
        node* left;
        node* right;

    //Default constructor 
    node() = default;
    
    //Constructor overloading
    node(int d){

            data = d;
            left = NULL;
            right = NULL;
            
        }

    node* preOrderBuild(){

        // Input: 1,2,4,-1,-1,5,7,-1,-1,-1,3,-1,6,-1,-1
        cout << "Enter the elements of tree for preorder build. Use -1 for NULL" << endl;
        int element;

        cin >> element; 

        if(element == -1){

            return NULL;
        }

        node* n = new node(element);
        n -> left = preOrderBuild();
        n -> right = preOrderBuild();
    return n;

    }

    node* levelOrderBuild(){

    cout << "Enter root node" << endl; 
    
    //accept data part of root node as input 
    int data; 
    cin >> data;

    //create root node 

    node* root = new node(data); 
    std::queue<node*> q; 

    //push root into queue

    q.push(root); 

    //traverse queue

    while(!q.empty()){

    //Store first element of queue
        node* front = q.front(); 

    //pop front element 
        q.pop(); 

    //accept two inputs from user 

        int left_n, right_n; 
        cout << "Enter left and right children. Use -1 if NULL" << endl;
        cin >> left_n >> right_n; 
    
        if(left_n != -1){

            front -> left = new node(left_n);
            q.push(front -> left);
        }

        if (right_n != -1){

            front -> right = new node(right_n);
            q.push(front -> right);
        }

        
    }

    return root;

}


    void levelOrderPrint(node* root){
    
    /*
    NOTE: We create a queue data structure to perfrom BFS. 
    The elements of the queue CANNOT be the data field (int) of the node, since we would lose 
    access to the children of the node. The elements need to be either pointers to the node 
    or the node itself. However, creating the node itself means that we would need to store 
    copies of the node, which is not space efficient. Hence we use the queue elements as type
    node*.
    */

    //creating a queue of type node*
        std::queue<node*> levelorder; 
    
    //push root node inside queue and also a NULL pointer
        levelorder.push(root);
    //keeps track of levels
        levelorder.push(NULL);

        while(!levelorder.empty()){

            //store node at the front of the list
            node* current_node = levelorder.front();
            levelorder.pop();

            if(current_node == NULL){

                //null indicates end of level, so print a new line

                
                cout << endl;
                
                if(levelorder.empty()){
                    break;
                }

                else{
                    levelorder.push(NULL);
                }


            }

            else{

                cout << current_node -> data << " ";
                
                if(current_node -> left){
                    levelorder.push(current_node -> left);
                    }

                if(current_node -> right){
                    levelorder.push(current_node -> right);
                    }

                }



        }   

    }

    int height(node * root){

        //base case
        if(root == NULL){
            return 0;
        }

        //recursive call on the height of the left sub-tree 
        int h1 = height(root -> left);

        //recursive call on the height of the right sub-tree
        int h2 = height(root -> right);

        //add 1 to the maximum of the heights of the left and right sub-trees

        return 1+max(h1,h2); 


    }


    /*This implementation is however inefficient, it has O(N^2) time complexity because it visits each node twice.
    The first time is a recursive call to determine the height and the second is to find if it is balanced. 

    */
    bool heightBalancedTree(node* root){

        // base case - if you don't put this case, it will return a segmentation fault - recursion will not exit. 
        if(root == NULL){

            return true;
        }

        int h1 = height(root -> left);
        int h2 = height(root -> right);
        
        bool leftBalanced = heightBalancedTree(root -> left);
        bool rightBalanced = heightBalancedTree(root -> right);
                

        if(leftBalanced && leftBalanced && (h1-h2) <=1){
            return true;
        }

        else {
            return false;
    }
    
    }

// More efficient, since we make once recursive call and determine both height and if it is balanced at the same time. 

    pair<int, bool> heightBalancedTreeOptimized(node* root){

        pair<int, bool> p, left, right; 

        //base case 

        if(root == NULL){
            p.first = 0;
            p.second = true;
            return p;
        }

        //recursive case 

        left = heightBalancedTreeOptimized(root -> left);
        right = heightBalancedTreeOptimized(root -> right); 

        int height = max(left.first, right.first) + 1;
        p.first = height;
        
        if(left.second && right.second && (left.first - right.first) <=1){  
            p.second = true;
        }
        else{ 
              p.second = false;
        }

        return p;

    }

    struct Pair {
        
        int inc; //Sum when the current element is included in the sum
        int exc; //Sum when the current element is excluded from sum
    };


    pair <int, int> maxSubsetSum(node* root){

        //base case 
        pair <int, int> p, leftSum, rightSum;
        if (root == NULL){
            p.first = 0;
            p.second = 0;
            return p;
            
        }

        //recursive case 

        leftSum = maxSubsetSum(root -> left);
        rightSum = maxSubsetSum(root -> right);

        p.first = root-> data + leftSum.second + rightSum.second;  
        p.second = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);

        return p;

    }


// Given a value K, print all nodes at distance K from the root 
    void printAtLevelK(node* root, int k){
        int temp = k;
        //base case 
        //cout << "value of K is: " << k << endl;
        if(k<0){
            //cout << "K < 0" << endl;
            return;
        }
        
        if(root == NULL){
           //cout << "Data in the Kth level is does not exist " << endl; 
           return;
        }

        if(k==0){

            cout << root -> data << endl;
            return;
        }

        //recursive case
        else{
        printAtLevelK(root -> left, k-1);
        //out << "First recursive call done" << endl;
        printAtLevelK(root -> right, temp-1);       
        return;
        }

        
    }


    int distKfromTarget(node* root, int K, node* target){

        // cout << "Target is: " << target -> data << endl;
        //base case 
        if(root == NULL){

            return -1;
        }
        
        if(root == target){

            printAtLevelK(root, K);
            return 0;
            
        }

        int DL = distKfromTarget(root -> left, K, target);
        if (DL != -1){

            // if the node you are searching from is at a distance k from the target 
            if (DL + 1 == K){
                cout << root -> data << endl;   
            }

            else{

                printAtLevelK(root, K-DL-2);
                
            }

            return DL + 1;

        }

        int DR = distKfromTarget(root -> right, K, target);

        if(DR != -1){

            if (DR + 1 == K){
                cout << root -> data << endl;   
            }

            else{

                printAtLevelK(root, K-DR-2);
                
            }

            return DR + 1; 


        }

    return -1;


    }


    void traverseTree(node* root, int d, map<int, vector<int>> &m){

        //base case 
        if (root == NULL){
            return;
        }

        //recursive case 
        m[d].push_back(root -> data);
        traverseTree(root-> left, d-1, m);
        traverseTree(root-> right, d+1, m);

    }

    //root is at a distance 0 from itself
    //left child -> subtract one from distance 
    //right child -> add one to distance 

    void nodesAtSameVerticalHeight(node* root){

        if (root == NULL){
            return;
        }

        map<int, vector<int>> m; 
        int d = 0;

        traverseTree(root, d, m);
        
        //map traversal - each element of a map is a key value pair data structure
        //first element accessed as .first() and second element as .second()
        for (auto kv:m) {

            for (auto nums: kv.second){

                cout << nums << " "; 
            }

            cout << endl;
        }

    }

    int sumDescendents(node* root){

        //base case 

        if (root == NULL){
            return 0; 
        }

        if (root -> left == NULL and root -> right == NULL){
            return root -> data;
        }

        //recursive case 
        int SL = sumDescendents(root -> left);
        int SR = sumDescendents(root-> right);
        int temp = root -> data;
        root -> data = SL + SR;
        return temp + root -> data; 
    }

    int diameter(node* root){

        //base case 

        if(root == NULL){ return 0;}

        //recursive cases 

        // distance if diameter were through root 

        int D1 = height(root -> left) + height(root -> right); 

        // distance if diameter were not through the root 

        //diameter through the left sub-tree: 

        int D2 = diameter(root -> left);
        int D3 = diameter(root -> right); 

        return max(D1, max(D2, D3));

    }

};


