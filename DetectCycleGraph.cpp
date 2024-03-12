#include <iostream>
#include <vector>
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
bool check = false;

void DfsGraph(vector<vector<int>>& adj, vector<bool>& visited, int source, int parent) {
    visited[source] = true;
    for (int x : adj[source]) {
        if (!visited[x]) {
            DfsGraph(adj, visited, x, source);
        } else if (visited[x] && parent != x) {
            check = true;
            return; // Exit the function if a cycle is found
        }
    }
}
int main() {

    
    int vertices = 3;
    vector<vector<int>> adj(vertices); 
    addEdge(adj , 0 , 1 ) ; 
    addEdge( adj , 1 , 2 ) ; 
    addEdge( adj , 0 ,2 ) ; 
    
   

     
    vector<bool>visited(vertices) ; 
    
    for ( int i = 0 ; i < vertices ; i ++ ) { 

    	if ( visited[ i ] == false ) { 
           
    		DfsGraph( adj , visited , i  , -1 ); 
    	}
    	
    }
    cout << check ;  





    return 0;
}

