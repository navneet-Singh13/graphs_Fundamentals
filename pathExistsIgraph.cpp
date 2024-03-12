#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void PrintGraph(vector<vector<int>> adj , int vertices ) {
	 for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (auto x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}
bool BfsGraph(vector<vector<int>> adj , int vertices , int source   , vector<bool>&visited , int destination  ) {
	 
	 visited [source] = true; 
	 queue<int>q ; 
	 q.push(source) ; 
	 while (!q.empty()) { 
	 	int front = q.front( ) ; 
	 	
	 	q.pop( ) ; 
	 	for(int  i  = 0 ;  i < adj[front].size( ) ; i ++  ) {
	 		if( visited [ adj[ front] [ i ]] == false) { 
                if ( adj [ front ] [ i ] == destination ){ 
                    return true ; 
                }
	 			visited [ adj [ front] [ i ] ] = true ;
	 			q.push(adj [ front ] [ i ]) ; 
	 		}
	 	}
        cout << endl ; 
	 }
     return false ; 
}
int main() {
    int vertices = 6;
    vector<vector<int>> adj(vertices); // Initialize adjacency list with size vertices
    vector<bool>visited(vertices) ;
    addEdge( adj , 0 , 1 ) ; 
    addEdge( adj , 1 , 3 ) ; 
    addEdge( adj , 0 , 2 ) ; 
    addEdge( adj , 3 , 4 ) ;
    addEdge (adj , 3 , 5 ) ; 
    addEdge( adj , 4 , 5 ) ; 
     
    
    //PrintGraph( adj  , vertices ) ; 
    // if source not given and graph is disconnected
    // so we start from the 0 vertex
    
    	
   cout <<  BfsGraph( adj ,  vertices , 5 , visited , 0 ) ;
    	
    
    
    
     
    
    return 0;
}




