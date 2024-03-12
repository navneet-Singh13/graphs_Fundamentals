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
int main() {
    int vertices = 4;
    vector<vector<int>> adj(vertices); // Initialize adjacency list with size vertices


    return 0;#include<bits/stdc++.h>
    using namespace std ; 
    int main ( ) { 
    
    
    
    
    
    
    
    	return 0 ; 
    }
}




