#include <iostream>
#include <vector>
#include<utility>
#include<unordered_map>
#include<stack> 
#include<cmath>
using namespace std;


void addEdge(unordered_map<int , vector<pair<int , int >>> &mymap  , int u ,  pair<int, int > p  ) {
     
    vector<pair<int , int >> subpart ; 
    
    mymap[u].push_back(p);  

    

}
void PrintGraph(unordered_map<int , vector<pair<int , int >>> mymap ) {
	 for ( auto entry : mymap) {
        std::cout << "Key: " << entry.first << "->" ;
        for ( auto  pair : entry.second) {
            cout << "  Pair: (" << pair.first << ", " << pair.second << ")" ;
        }
        cout << endl; 
    }
}
void TopoSort(unordered_map<int , vector<pair<int , int >>> mymap , int source  , vector<int> &visited ,  stack<int>&mystack ) { 
	visited [ source ] = true ; 

	for ( auto x : mymap [ source ]){ 
		if ( !visited [ x.first ]) { 
			TopoSort ( mymap , x.first , visited , mystack ) ; 
		}
		
	}
	 
    mystack.push(source) ; 

}
 

void sPathDag(unordered_map<int , vector<pair<int , int >>> mymap , stack<int>&mystack ,  vector<int>&distance  , int source ){ 
	distance [ source ] = 0 ; // because source to source distance will always be 0 

	while ( !mystack.empty( )){
		int top = mystack.top() ; 
		
		mystack.pop( ) ; 
			for( auto x : mymap[ top ]){ 
				if ( distance [ x.first ] > x.second + distance [ top ] ) { 
					distance [ x.first ] =  x.second  + distance [ top ]; 
				}
			}
			
		

	}


}
int main() {
     
    
    unordered_map<int , vector<pair<int , int >>> mymap ;
    addEdge( mymap , 0 , {1 ,5} ) ; 
    addEdge( mymap , 0 , {2 ,3} ) ; 
    addEdge( mymap , 1 , {2 ,2} ) ; 
    addEdge( mymap , 1 , {3 ,6} ) ; 
    addEdge( mymap , 2 , {3 ,7} ) ; 
    addEdge( mymap , 2 , {4 ,4} ) ;
    addEdge( mymap , 2 , {5 ,2} ) ; 
    addEdge( mymap , 3 , {4 ,-1} ) ;
    addEdge( mymap , 4 , {5 ,-2} ) ;
    vector<int>visited(6) ;
    vector<int>distance(6 , 1e9) ;  
    stack<int>mystack ; 
    PrintGraph( mymap ) ; 
     // topo sort to find the ordering of visiting node 
    TopoSort( mymap , 0 , visited , mystack) ; 

    // while ( !mystack.empty( )) { 
    // 	cout << mystack.top ( ) << " , " ; 
    // 	mystack.pop(  ); 
    // }
    

     sPathDag(mymap , mystack , distance , 1  ) ; 
    
     for ( int i = 0 ; i < distance.size( ) ; i ++ ){ 
     	cout << distance [ i ] << " , " ; 
     }


    return 0;
}




