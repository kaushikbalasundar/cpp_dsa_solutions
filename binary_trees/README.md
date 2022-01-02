## Binary Trees ##

### Definition ###

Binary trees are data strcutures which have a node comprising of a data element, and points to two other nodes (hence the name binary). 

(<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/1200px-Binary_search_tree.svg.png" alt="Binary search tree - Wikipedia" style="zoom:50%;" />)

### Some terminology: ###

1. Children: Left/Right node from a parent node are called its children
2. Root: The first node in the tree that has no parents 
3. Leaf: The final nodes in the tree that have no children
4. Height of tree: Maximum height of the tree from the root to the leaf. This can also be done recursively. 
5. Diameter: Largest distance between any two nodes of the binary tree. It is not necessary that the diameter of the tree has to take a path that goes through the root node of the tree. 


### Building Strategies ###

**Pre-order build:** Building a binary tree in a manner such that the left sub-tree is built, followed by the right sub-tree. It does not follow a method where all nodes of a single level are built. 

**Level Order build**: Building a binary tree in a manner such that all the nodes of a given level are built in an ascending order - i.e., level 0 -> 1 -> 2 etc. When doing level order build or level order print with c++, a common strategy is to use a queue, and use -1/NULL to indicate that a child doesn't exist. 


### Height of Tree ###

Finding the height of the tree is really simple when using recursion. Recusion requires a base case and recursive case. The recursive case will be that when we hit a NULL pointer, we return 0. The recursive case will be a call to the height function again. 

### Height of a balanced tree ###

A tree is said to be balanced if:

1. The left sub tree is balanced 
2. The right sub tree is balanced 
3. The difference in height between the left and the right sub-trees is not more than 1. 

The inefficient way to do this would be to visit each node and do the following: 

1. If the node is NULL, then it has to be balanced, so return true. 
2. If not NULL, Make recursive call to find the height of the left (h1) and right sub trees (h2)
3. Make a recursive call on the left child, and right child. 
4. If (left is balanced && right is balanced && h1-h2 <=1) then the tree is balanced, else it is unbalanced.  

It is inefficient because it has O(N^2) time complexity because it visits each node twice. The first time is a recursive call to determine the height and the second is to find if it is balanced.

