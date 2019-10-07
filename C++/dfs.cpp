// A simple representation of graph using STL, 
// for the purpose of competitive programming 
#include<bits/stdc++.h> 
using namespace std; 

// A utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

// A utility function to do DFS of graph 
// recursively from a given vertex u. 
void DFSUtil(int u, vector<int> adj[], 
					vector<bool> &visited) 
{ 
	visited[u] = true; 
	cout << u << " "; 
	for (int i=0; i<adj[u].size(); i++) 
		if (visited[adj[u][i]] == false) 
			DFSUtil(adj[u][i], adj, visited); 
} 

// This function does DFSUtil() for all 
// unvisited vertices. 
void DFS(vector<int> adj[], int V) 
{ 
	vector<bool> visited(V, false); 
	for (int u=0; u<V; u++) 
		if (visited[u] == false) 
			DFSUtil(u, adj, visited); 
} 

// Driver code 
int main() 
{ 
    cout<<"Enter the number of vertex and edge respectively: -"<<endl;
	int V ,E;
    cin>>V>>E ;

	// The below line may not work on all 
	// compilers. If it does not work on 
	// your compiler, please replace it with 
	// following 
	// vector<int> *adj = new vector<int>[V]; 
	vector<int> adj[V]; 
    cout<<"Start entering the edges :- "<<endl;
	// Vertex numbers should be from 0 to 4. 
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        addEdge(adj, a, b);
    }
	 
cout<<"Below is the Depth first order of given tree :-"<<endl;
	DFS(adj, V); 
    cout<<endl;
	return 0; 
} 
