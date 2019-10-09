// Java program to print DFS traversal from a given given graph 
import java.io.*; 
import java.util.*; 

// This class represents a directed graph using adjacency list 
// representation 
class dfsTraversal 
{ 
	private int V; // No. of vertices 

	// Array of lists for Adjacency List Representation 
	private LinkedList<Integer> adj[]; 

	// Constructor 
	dfsTraversal(int v) 
	{ 
		V = v; 
		adj = new LinkedList[v]; 
		for (int i=0; i<v; ++i) 
			adj[i] = new LinkedList<Integer>(); 
	} 

	//Function to add an edge into the graph 
	void addEdge(int v, int w) 
	{ 
		adj[v].add(w); // Add w to v's list. 
	} 

	// A function used by DFS 
	void DFSUtil(int v,boolean visited[]) 
	{ 
		// Mark the current node as visited and print it 
		visited[v] = true; 
		System.out.print(v+" "); 

		// Recur for all the vertices adjacent to this vertex 
		Iterator<Integer> i = adj[v].listIterator(); 
		while (i.hasNext()) 
		{ 
			int n = i.next(); 
			if (!visited[n]) 
				DFSUtil(n, visited); 
		} 
	} 

	// The function to do DFS traversal. It uses recursive DFSUtil() 
	void DFS(int v) 
	{ 
		// Mark all the vertices as not visited(set as 
		// false by default in java) 
		boolean visited[] = new boolean[V]; 

		// Call the recursive helper function to print DFS traversal 
		DFSUtil(v, visited); 
	} 

	public static void main(String args[]) 
	{ 	
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the no. of nodes to be present in the graph");
		int n=sc.nextInt();
		dfsTraversal g = new dfsTraversal(n); 
		
		System.out.println("Enter the no. of edges to present in the graph");
		int no_edges=sc.nextInt();
		
		System.out.println("Enter the edges as (edgeno, edgeno)");
		for(int i=0;i<no_edges;i++){
			g.addEdge(sc.nextInt(),sc.nextInt());
		}		
		System.out.println("Enter the vertex no from which the bfs should start \n (Note : 0 based indexing is followed.)");
		int x=sc.nextInt();
		System.out.println("Following is Depth First Traversal "+ 
						"(starting from vertex "+x+" )"); 

		g.DFS(x); 
	} 
}