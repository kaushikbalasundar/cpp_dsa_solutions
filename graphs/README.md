# Graphs Key Concepts

## Basic Terminology

![Graph — Isaac Computer Science](https://isaaccomputerscience.org/api/v2.19.3/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/Isaac_Computer_Science_2_Data_Structures_Project_OUTLINE_V6_1_2.png)

* A graph is a set of nodes (aka vertices) connect to each other by edges. There are many types of graphs as listed below:

  * **Weighted graph:** When each edge has some weighting factor associated with it. It can represent the cost, length, etc.
  * **Unweighted graph:** No weight or value attached to the edges of the graphs. 
  * **Directed graphs:** When the edges are represented by arrows that indicate the possible directions of traveral, then we call those as directed graphs. 
  * **Undirected graphs: **When there is no directionality associated with the edges of the graphs, then the resulting graph is called an undirected graph. 

  ## Storing Graphs

  * It is possible to store graphs using two popular methods: 

    * Adjacency List 
    * Adjacency Graph

  * The image below shows different kinds of graphs and the associated adjacency matrices:

    ![Different types of graphs and their corresponding adjacency matrix... |  Download Scientific Diagram](https://www.researchgate.net/publication/347300725/figure/fig1/AS:969208926044162@1608088823984/Different-types-of-graphs-and-their-corresponding-adjacency-matrix-representations-The.ppm)

* An alternative way to do this is by using adjacency lists as shown in the image below:

  <img src="https://gateoverflow.in/?qa=blob&qa_blobid=14901742589732224722" alt="Cormen - GATE Overflow" style="zoom:135%;" />

* Using the list represenation, it is possible to traverse the list and get all the neighbours of a particular node. This is not possible with a matrix. Matrices also takes a larger amount of memory [O(*v^*2) order] - quadratic. Adjacency list however, takes linear memory, not quadratic - i.e. [O(*v+e*)], where *v* are vertices and e are edges.  

* However, with a matrix, without having to traverse a list, we can check if there is a connection between two nodes. This operation will have O(1) time complexity, and O(n) in case of a list. 

* Adjacancy lists however are easier to create and the operations typically involve checking neighbours more than their connections. Therefore, the adjacancy list represtation will be used throughout this repository. 

* During the actual implementation, adjacency lists are created in a class that contains an array of lists, with each element in the array representing the associations between nodes. We can use the STL's <list> to include doubly linked lists. So each element of the array will be a doubly linked list. 

* Elements of a graph can also be complex, and an example of this is shown in complexGraph.cpp, where a Node() class is used for the creation of nodes. 

## Graph Traversals

* The process of visiting all the nodes in a graph is called graph traversal. We can do this in a bread-first manner or a depth-first manner. 

### Breadth-First Search (BFS)

* You can traverse a graph in a breadth-first or a depth-first manner. The illustration below depicts this traversal: 

  <img src="https://www.guru99.com/images/1/020820_0543_BreadthFirs1.png" alt="Breadth First Search (BFS) Algorithm with EXAMPLE" style="zoom:67%;" />

* Each time you visit a node, push it into a queue and mark it as visited in a seperate array. Then pop out the first node, and push the neighbours of that node into the queue, and mark them as visited. Visit, the next element in the queue, print it, pop it out and push its neighbours in the queue. Do this until all nodes are visited. This is the priniple behind the implementation of BFS. The nature of BFS is **iterative.** 

### Depth-First Search (DFS)

* Unlike, BFS, DFS is **recursive** in nature. Each time a node is visited, it gets marked as visited, and makes a recursive call on one of its unvisited neighbours. When there are no more unvisited neighbours the function returns. The image below shows the working of DFS and compares it to BFS: 

  <img src="https://qph.fs.quoracdn.net/main-qimg-7b145b86b4bca7d619028bc160f8332a" alt="What are some examples of depth or breadth first search applied to real  life? - Quora" style="zoom: 40%;" />

* Both BFS and DFS have linear time complexity. If E is the number of edges and V are the number of vertices then the time complexity is given by: **O(V+E)**

