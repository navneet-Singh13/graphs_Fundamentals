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
void Dfs(vector<vector<int>> adj , int source  , int destination){
    
    cout << source << "," ; 
    if ( source == destination ){ 
        cout << endl ; 
        return ; 
    }
    for ( auto x : adj [ source ]) { 
        
        Dfs(adj ,  x, destination ) ;
        
    }


      

}
int main() {
    int vertices = 4;
    vector<vector<int>> adj(vertices);
    vector<bool>visited( vertices );  
    addEdge( adj , 0 , 1) ; 
    addEdge( adj , 0 , 2) ; 
    addEdge( adj , 1 , 3) ; 
    addEdge( adj , 2 , 3) ; 
     
    Dfs( adj , 0  , 3) ;

    return 0;
}




