## Binary Trees ##

### Definition ###

Binary trees are data strcutures which have a node comprising of a data element, and points to two other nodes (hence the name binary). 

(<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/1200px-Binary_search_tree.svg.png" alt="Binary search tree - Wikipedia" style="zoom:50%;" />)

### Building Strategies ###

**Pre-order build:** Building a binary tree in a manner such that the left sub-tree is built, followed by the right sub-tree. It does not follow a method where all nodes of a single level are built. 

Level Order build: Building a binary tree in a manner such that all the nodes of a given level are built in an ascending order - i.e., level 0 -> 1 -> 2 etc. 

### Some terminology: ###

1. Children: Left/Right node from a parent node are called its children
2. Root: The first node in the tree that has no parents 
3. Leaf: The final nodes in the tree that have no children
4. Height of tree: Maximum height of the tree from the root to the leaf
5. Diameter: Largest distance between any two nodes of the binary tree

