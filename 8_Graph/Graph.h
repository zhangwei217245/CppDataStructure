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
 
    // Recur for all the vertices adjacent to this vertex
}
 
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
 
    // Call the recursive helper function to print DFS traversal
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
 
    // Create a queue for BFS
 
    // Mark the current node as visited and enqueue it
 
    // 'i' will be used to get all adjacent vertices of a vertex

        // Dequeue a vertex from queue and print it
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
}
 
