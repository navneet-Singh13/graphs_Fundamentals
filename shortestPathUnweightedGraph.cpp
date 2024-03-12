#include <iostream>
#include <vector>
#include<cmath>
#include<queue> 
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void PrintGraph(vector<vector<int>> adj , int n ) {
	 for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}
void bfs( vector<vector<int>> adj , vector<bool>&visited  , vector<int>&dist , int source ){
	queue<int>q  ; 
	visited [ source] = true; 
	dist [ source ] = 0 ; 
	q.push(source) ; 
	while ( !q.empty ( )) {
		int front = q.front () ; 
		q.pop( ) ; 
		for ( auto x : adj [ front  ]) { 
			if ( !visited [ x ]){ 
				dist [ x ] = dist [ front ] + 1 ; 
				visited [ x ] = true; 
				q.push(x) ; 
			}
		}
	
}


}
int main() {
    int n = 8;
    vector<vector<int>> adj(n); 
    addEdge( adj , 0 , 1 ) ; 
    addEdge( adj , 1 , 2 ) ; 
    addEdge( adj , 0 , 3 ) ; 
    addEdge( adj , 3 , 4 ) ; 
    addEdge( adj , 3 , 7 ) ; 
    addEdge( adj , 4 , 6 ) ; 
    addEdge( adj , 4 , 7 ) ; 
    addEdge( adj , 4 , 5 ) ; 
    addEdge( adj , 5 , 6 ) ; 
    vector<bool>visited ( n ) ;
    vector<int>dist(n) ; 
    int source = 0 ; 
    bfs(adj , visited  , dist , source  ) ; 

    for (int i = 0; i < n; ++i)
    {
    	cout << dist [ i ]  << " , " ; 
    }
    






    return 0;
}




