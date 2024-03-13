#include <iostream>
#include <vector>
#include <utility>
#include <queue> 
using namespace std;

// Function to add an edge to the adjacency list
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight)); // For undirected graphs
}

// Function to print the adjacency list
void printAdjacencyList(vector<pair<int, int>> adj[], int V) {
    for (int i = 0; i < V; ++i) {
        
        for (auto& pair : adj[i]) {
            cout << i << "-> " << pair.first << "," << pair.second  << endl;
        }
        cout << endl;
    }
}
void dikj(vector<pair<int, int>> adj[ ]  , int V  , int source , vector<int>&dist ) {

    
    dist [ source ] = 0 ; 
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0 , source }) ; 
    while ( !pq.empty( )) { 
        int dis = pq.top().first ;
        int node = pq.top( ).second ; 
        pq.pop( ) ; 
        for ( auto x : adj[node] ) { 
            int adjnode = x.first ; 
            int edgeweight = x.second ; 

            if (dist[adjnode] > dis + edgeweight ) { 
                dist [ adjnode ] = dis + edgeweight ; 
                pq.push( {dist [ adjnode ] , adjnode }) ; 
            }

        }

    }
          
}
int main() {
    int V = 6; // Number of vertices
    vector<pair<int, int>> adj[V]; // Adjacency list

    // Example graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 2, 4, 1);
    addEdge(adj, 2, 5, 6);
    addEdge(adj, 2, 4, 1);
    addEdge( adj , 3 , 5 , 2 ) ; 
    addEdge(adj, 4, 5, 3);
    
    // Print the adjacency list
    printAdjacencyList(adj, V);
    vector<int>dist(V , 1e9) ; 
    dikj(adj , V , 0  , dist) ; 
    for ( int i = 0 ; i < dist.size( ) ; i ++ ) { 
        cout << dist [ i ] << " , " ; 
    }
    
    return 0;
}
