#include <iostream>
#include <vector>
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
bool check = false ; 
void DirectedGraphCycleDetect(vector<vector<int>> adj , vector<bool>&visited , vector<bool>&currVisited , int source  ){
	visited [ source ] = true ; 
	currVisited [ source ] = true ; 
	for (auto x : adj [ source ]) { 
		if (!visited[ x ]) { 
			DirectedGraphCycleDetect( adj , visited , currVisited , x ) ; 
		}
		if ( visited [ x ] && currVisited [ x ]) { 
			check = true ; 
			return ; 
		}
	}
	currVisited [ source ] = false ; 
}
int main() {
    int v = 7;
    vector<vector<int>> adj(v); 
    vector<bool>visited(v) ; 
    vector<bool>currVisited(v); 

    // adjacency list creation //  
    addEdge( adj , 0 , 1 ) ; 
    addEdge( adj , 0 , 2 ) ; 
    addEdge( adj , 1 , 3) ; 
    addEdge( adj , 1 , 2 ) ; 
    addEdge( adj , 3 , 0 ) ; 
    addEdge( adj , 2 , 5 ) ; 
    addEdge( adj , 4 , 5 ) ; 
    addEdge ( adj , 6 , 6 ) ; 
    
    //----------------------//

    for ( int i = 0 ; i < v  ; i ++ ) { 
    	 if(visited [ i ] == false ) { 
    	 	DirectedGraphCycleDetect(adj , visited , currVisited , i  ) ; 
    	 }
    	 
    }
    for ( int i = 0 ; i < v ; i ++ ) { 
    	
    	cout << visited [ i ] << " , " ; 
    }
    cout << endl ; 
    for ( int i = 0 ; i < v ; i ++ ) { 

    	cout << currVisited [ i ] << " , " ; 
    }
    cout << endl ; 
    cout << check ; 







    return 0;
}




