#include <iostream>
#include <vector>
#include<queue> 
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
void toposort( vector<int>&indegree , vector<vector<int>> adj ) { 
	queue<int> q ; 

	for( int i = 0 ; i < indegree.size( ) ; i ++ ) { 
		if ( indegree[ i ] == 0 ) { 
			q.push( i ) ; 
		}
	} 
    int cnt = 0 ; 
	while( !q.empty( )) { 
		int front = q.front ( ) ; 
		q.pop( ) ; 
		cout << front << " ," ; 
        cnt++ ; 
		for ( auto x : adj[ front ]) { 
			indegree[x]--;
			if ( indegree [ x ] == 0 ){ 
				q.push( x ) ; 
			}
		}
	}
    cout << endl; 
    cout << cnt ; 

}
int main() {
    int vertices = 4;
    vector<vector<int>> adj(vertices); 
    addEdge( adj , 0 , 1 ) ; 
    addEdge( adj , 2 , 0 ) ; 
    addEdge( adj , 1 , 3 ) ; 
    addEdge( adj , 3 , 2 ) ; 
    // PrintGraph( adj , vertices ) ; 
    vector<int>indegree(vertices);
    // storing the indegree of the vertices 
    for ( int i = 0 ; i < adj.size( ) ; i ++ ) { 
    	for ( int j = 0 ; j < adj[ i ].size( ) ; j ++ ) { 
    		int x = adj [ i ] [ j ] ; 
    		indegree [x]++ ; 
    	}
    }
    // printing indegrees

    // for ( int i = 0 ; i < vertices ; i ++ ) { 
    // 	cout << indegree [ i ] << " , " ; 
    // }

    // starting from the vertex whose indegree in 0 
    
     
    toposort( indegree , adj ) ; 

    return 0;
}





