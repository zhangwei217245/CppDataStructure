// C++ program to print DFS traversal from a given vertex in a  given graph
#include<iostream>
#include "genDLList.h"
 
using namespace std;
 
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    DoublyLinkedList<int> *adj;  // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
	void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new DoublyLinkedList<int>[V];
    int i = 0;
    for(; i < V; i++){
        adj[i]= *(new DoublyLinkedList<int>());
    }
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].addToDLLTail(w); // Add w to v’s list.
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    DLLNode<int> *i=NULL;
    for (i = adj[v].headNode(); i != NULL; i=i->next)
        if (!visited[i->info])
            DFSUtil(i->info, visited);
}
 
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    DoublyLinkedList<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.addToDLLTail(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    DLLNode<int> *n; 

    while(!queue.isEmpty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.firstEl();
        cout << s << " ";
        queue.deleteFromDLLHead();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(n = adj[s].headNode(); n != NULL; n=n->next)
        {
            if(!visited[n->info])
            {
                visited[n->info] = true;
                queue.addToDLLTail(n->info);
            }
        }
    }
}
 
