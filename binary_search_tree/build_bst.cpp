#include <iostream>
#include <vector>


class Node{

    public: 
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};

// A class for the binary search tree 
class BST{

    public:
        std::vector<int> values_;
        Node* root_ = nullptr;

        //Constructor 
        BST(std::vector<int> values, bool sorted=false){
            values_ = values;
            if(!sorted){
                for (int i=0; i<values_.size(); i++){
                 root_ = insertNode(values_[i], root_);
                }
            }
            else{
                root_ = constructMinHeightTree(values);
            }

            
            
        }
        
        //Function to call recursive in-order print
        void inOrderPrint(){
            inOrderPrintRecursive(root_);
            return;
        }

        // Function to determine if an element exists in the tree or not 
        void searchForElement(int value){

            if(searchForElementRecursive(root_, value)){
                std::cout << "The number " << value << " exists in the BST!" << std::endl; 
            }

            else{
                std::cout << "The number " << value << " does not exist in the BST" << std::endl;
            }

        }

        // Function to contruct a minimum height BST given a sorted array 
        Node* constructMinHeightTree(std::vector<int> sorted_array){

            Node* root = constructMinHeightTreeRecursive(sorted_array, 0, sorted_array.size()-1);
            return root;
        }

        // Function to find closest element in the tree to a given element recursively
        void findClosestElement(int value){
            int min_difference = INT8_MAX;
            int closest_value = findClosestElementRecursive(root_, value, min_difference, root_ -> value);
            std::cout << "The closest element to " << value << " is : " << closest_value << std::endl;
        }

        // Function to find the closest element in the tree to a given element iteratively 
        void findClosestElementIterative(int value){

            int closest_value = -1;
            int minimum_difference = INT8_MAX;
            int diff = INT16_MAX; 
            Node* curr = root_; 
            while(curr != nullptr){
                
                //Return the element if its equal to the value being searched for
                if(curr -> value == value){
                    closest_value = curr -> value;
                    std::cout << "The closest element to " << value << " is : " << curr -> value << std::endl;
                    return;
                }

                //Compute the difference 
                diff = abs(value - curr -> value);
                if(diff > minimum_difference){
                    closest_value =  curr -> value;
                    
                }

                //Condition to traverse down the left sub-tree
                if((value < curr -> value) && (diff < minimum_difference)){
                    minimum_difference = diff; 
                    closest_value = curr -> value;
                    curr = curr -> left;
                }

                //Condition to traverse down the right sub-tree 
                else if((value > curr -> value) && (diff < minimum_difference)){
                    minimum_difference = diff; 
                    closest_value = curr -> value;
                    curr = curr -> right;
                }
            }
                std::cout << "The closest value to " << value << " is: " << closest_value << std::endl;
        }

    private:

        // Function to recursively build a BST
        Node* insertNode(int value, Node* root){

            // Base case 
            if(root == nullptr){
                return new Node(value);
            }

            //If value is less than root's value, insert into the left sub-tree
            if(value < root -> value)
                root -> left = insertNode(value, root -> left);

            // If value is greater than the root's value, insert it into the right sub-tree
            else
                root -> right = insertNode(value, root -> right);

            return root;
        }

        // Recursive function for in order printing of the BST (the output should be sorted)
        void inOrderPrintRecursive(Node* root){

            //Base case
            if(root == nullptr){
                return;
            }

            inOrderPrintRecursive(root -> left);
            std::cout << root -> value << ", "; 
            inOrderPrintRecursive(root -> right);

            return;
        }

        //Recursive function to search for a value in the BST
        bool searchForElementRecursive(Node* root, int value){

            // Base case: If element is equal to the root, return true
            if(root == nullptr){
                return false;
            }

            if (root -> value == value){
                return true;
            }

            if(value < root -> value){
                return searchForElementRecursive(root -> left, value);
            }

            else 
                return searchForElementRecursive(root -> right, value);

            return false;
        }

        // Recursive function to construct the minimum height BST given 
        Node* constructMinHeightTreeRecursive(std::vector<int> sorted_array, int start, int end){
            
            // If start > end, return nullptr since no elements exist 
            if(start > end){
                return nullptr;
            }

            // Find the middle of the array and create a new node 
            int mid = start + (end - start)/2; 
            Node* root = new Node(sorted_array[mid]);

            root -> left = constructMinHeightTreeRecursive(sorted_array, start, mid-1);
            root -> right = constructMinHeightTreeRecursive(sorted_array, mid+1, end);

            return root;
        
        }


        //Recursive function to find the closest element to a given value
        int findClosestElementRecursive(Node* root, int &value, int &min_difference, int &prev_node_val){
            
            int closest_value = -1;
            if(root == nullptr){
                return prev_node_val;
            }
            int difference = abs(value - root -> value); 

            if(difference > min_difference){
                return prev_node_val;
            }

            if(root -> value == value){
                return root -> value;
            }
            
            if((value < root -> value) && (difference < min_difference)){
                min_difference = difference;
                closest_value = findClosestElementRecursive(root -> left, value, min_difference, root -> value);
            }

            else if((value > root -> value) && (difference < min_difference)){
                min_difference = difference;
                closest_value = findClosestElementRecursive(root -> right, value, min_difference, root -> value);
                
            }

            return closest_value;

        }
                
};

int main(){

    std::vector<int> values = {1,6,7,4,3,8};
    std::vector<int> sorted_values = {1,3,5,11,12,15};

    // Normal BST
    // BST search_tree(values);
    // search_tree.inOrderPrint();
    // std::cout << std::endl;
    // search_tree.searchForElement(8);
    // search_tree.searchForElement(11);

    // Minimum height BST
    std::cout << "Constructing min height BST from a sorted array!" << std::endl;
    BST search_tree_2(sorted_values, true);
    search_tree_2.inOrderPrint();
    std::cout << std::endl;
    search_tree_2.findClosestElement(12);
    search_tree_2.findClosestElementIterative(12);
}