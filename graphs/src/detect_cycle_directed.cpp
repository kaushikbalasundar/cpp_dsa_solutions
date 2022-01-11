#include <list> 
#include <iostream> 
#include <vector> 

using namespace std; 

class Graph{

    public:

        int V; //number of nodes
        list<int> *l;  //linked list containing neighbours of each node 

    //construtor 

            Graph(int v){
                V = v;
                l = new list <int> [V];
            }

            void createEdge(int a, int b, bool dir= true){

                l[a].push_back(b);

                if(!dir){ 
                l[b].push_back(a);
                }
            }


            bool dfs(int node, vector <bool> visited, int parent){

                for (auto nbr:l[node]){

                    if(!visited[nbr]){

                        visited[nbr] = true;  
                        bool cycle = dfs(nbr, visited, node);
                        if(cycle){
                            return true;
                        }
                    }

                    else if (nbr != parent){
                        return true;
                    }

                }

                    return false;


            }
        

        };


bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method

    Graph g(V); //create a graph with V nodes
    vector <bool> visited(V, false);


    for (auto edge: edges){
       
        g.createEdge(edge.first, edge.second);
    }

    return(g.dfs(0,visited, -1));
} 

int main(){

    vector<pair <int, int> > graph = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {6,5},{6,4}};
    bool res = contains_cycle(7, graph);
    if(res == true){
        cout << "Contains cycle" << endl; 
    }

    else {
        cout << "Does not contain cycle" << endl;
    }

    return 0;
}
