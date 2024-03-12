#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    
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
stack<int>st  ; 
void TopoSortDfs(vector<vector<int>> adj ,vector<bool> &visited , int source ){
    
    visited [ source ] = true ; 

    for ( auto x : adj [ source ]) { 
        if ( visited [ x ] == false ) { 
            TopoSortDfs(adj , visited , x ) ;
        }
    }
    st.push( source ) ;  

}
int main() {
    int vertices = 5;
    vector<vector<int>> adj(vertices); 
    addEdge( adj , 0 , 1 ) ; 
    addEdge( adj , 1 , 3 ) ; 
    addEdge( adj , 2 , 3 ) ; 
    addEdge( adj , 3 , 4 ) ; 
    addEdge( adj , 2 , 4 ) ; 
    vector<bool> visited ( vertices ) ; 
    // Graph may be Disconnected -> 

    for ( int i = 0 ; i < vertices ; i ++ ) { 
    	if ( visited [ i ] == false ) {
            TopoSortDfs( adj , visited , i ) ; 
    	}
    }
    cout << "topological sort using dfs is :: " << endl ; 
    while ( !st.empty( )){ 
        cout << st.top( )<< " , " ; 
        st.pop( ) ; 
    }

    return 0;
}




