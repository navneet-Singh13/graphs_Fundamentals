#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    
}
void PrintGraph(vector<vector<int>> adj , int vertices ) {
	 for (int i = 1; i < vertices; i++) {
        cout << i << ": ";
        for (auto x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}
void BfsGraph(vector<vector<int>> adj , int vertices , int source   , vector<bool>&visited ) {
	 
	 visited [source] = true; 
	 queue<int>q ; 
	 q.push(source) ; 
	 while (!q.empty()) { 
	 	int front = q.front( ) ; 
	 	
	 	q.pop( ) ; 
	 	for(int  i  = 0 ;  i < adj[front].size( ) ; i ++  ) {
	 		if( visited [ adj[ front] [ i ]] == false) { 
	 			visited [ adj [ front] [ i ] ] = true ;
	 			q.push(adj [ front ] [ i ]) ; 
	 		}
	 	}
        cout << endl ; 
	 }
}
int main() {
    int vertices = 4;
    vector<vector<int>> adj(vertices); // Initialize adjacency list with size vertices
    vector<bool>visited(vertices) ;
    addEdge( adj , 2 , 3 ) ; 
    addEdge( adj , 1 , 3 ) ;
    addEdge ( adj , 3 , 1 ) ; 
  
    // addEdge( adj , 3 , 4 ) ;
    // addEdge (adj , 3 , 5 ) ; 
    // addEdge( adj , 4 , 5 ) ; 
     
    
    PrintGraph( adj  , vertices ) ; 
    // if source not given and graph is disconnected
    // so we start from the 0 vertex
    
    	
    // BfsGraph( adj ,  vertices , 0 , visited) ;
    	
    
    
    
     
    
    return 0;
}




