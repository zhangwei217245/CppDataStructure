#include "Graph.h"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    string filename = "graph.txt";
    if (argc > 1){
        filename = argv[1];
        cout <<"reading file : " << filename << endl;
    }
    std::ifstream infile(filename);
    int linecounter = 0;
    int a, b;
    Graph g;
    while (infile >> a >> b)
    {
        if (linecounter == 0){
            g.init(a);
        }else{
            g.addEdge(a, b);
        }
        cout << a << "," << b<< endl;
        linecounter++;
    }
    /*
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    */
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    cout << endl ;

    cout << "Following is Breadth First Traversal "
                 << "(starting from vertex 2) \n";
    g.BFS(2);
    cout << endl ;
    return 0;
}
