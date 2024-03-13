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
        // i isme source denote kr rha hai 
        for (auto& pair : adj[i]) {
            cout << i << "-> " << pair.first << "," << pair.second  << endl;
            // fir jse agr hum i se mtlab 0 se 1 ja skte hai aur 
            // with wieght 4 toh voh as a pair exist krega 
            // mtlb pair 1,4 0 index pr lie kr rha hai adj list mei 
            // aur mai for 0 index pr exist krne vale saare pairs ko print kr rha hun 
        }
        cout << endl;
    }
}
void dikj(vector<pair<int, int>> adj[ ]  , int V  , int source , vector<int>&dist ) {

    
    dist [ source ] = 0 ; // mujhe pta hai ki src se src ka distance 0 hoga 
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // mne pq bnyi kyuki main har baar min dist vali node uthaunga 
    pq.push({dist[ source] , source }) ; 
    // pq mei mne fir 0 ke distance ko aur 0 vali node ko daldiya
    while ( !pq.empty( )) { 
        int dis = pq.top().first ; // dist[ 0 ]
        int node = pq.top( ).second ; // source node ie 0 
        pq.pop( ) ;  // pq se hta diya fir 
        for ( auto x : adj[node] ) {  // ab mai voh pair of nodes pr iterate krunga jo source node se connected thi 
            int adjnode = x.first ; // yeh 0 se connected adj node ko uthyega jse 1 ko 
            int edgeweight = x.second ; // yeh 1 ka weight btyega 

            if (dist[adjnode] > dis + edgeweight ) {  // dist[ adjnode ] jo ki 1e9 hai voh > hai dis + jo wieght lg rha 0 se 1 jne mai jo 0 + 4 hai 
                dist [ adjnode ] = dis + edgeweight ; // toh mai usko update krdunga 0 + 4 = 4 se 
                pq.push( {dist [ adjnode ] , adjnode }) ; // fir usko pq mei daldunga 
            }

        }

    }
          
}
int main() {
    int V = 6; // Number of vertices
    vector<pair<int, int>> adj[V]; // Adjacency list
    // yeh ek adjacency list bn rhi hai jo ek array of vector<pair< int , int >> type ki hai 
    // Example graph
    addEdge(adj, 0, 1, 4);
    // yeh adjacency list aise bn rhi hai ki jaise hum 
    // agr 0 se 1 ja rhe hai toh uska edge ka weight 4 hai fir 
    addEdge(adj, 0, 2, 5);
    //////////////////////////////////////////////////////////
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 2, 4, 1);
    addEdge(adj, 2, 5, 6);
    addEdge(adj, 2, 4, 1);
    addEdge( adj , 3 , 5 , 2 ) ; 
    addEdge(adj, 4, 5, 3);
    
    // Print the adjacency list
    printAdjacencyList(adj, V); // pehle adjacency list bnalo with given weight 
    vector<int>dist(V , 1e9) ; 
    dikj(adj , V , 0  , dist) ; 
    for ( int i = 0 ; i < dist.size( ) ; i ++ ) { 
        cout << dist [ i ] << " , " ; 
    }
    
    return 0;
}
