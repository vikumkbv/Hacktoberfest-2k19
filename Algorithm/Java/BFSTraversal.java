
import java.io.*; 
import java.util.*; 

class BFSTraversal 
{ 
	private int V; // No. of vertices 
	private LinkedList<Integer> adj[]; //Adjacency Lists 

	// Constructor 
	BFSTraversal(int v) 
	{ 
		V = v; 
		adj = new LinkedList[v]; 
		for (int i=0; i<v; ++i) 
			adj[i] = new LinkedList(); 
	} 

	// Function to add an edge into the graph 
	void addEdge(int v,int w) 
	{ 
		adj[v].add(w); 
	} 

	// prints BFS traversal from a given source s 
	void BFS(int s) 
	{ 
		// Mark all the vertices as not visited(By default 
		// set as false) 
		boolean visited[] = new boolean[V]; 

		// Create a queue for BFS 
		LinkedList<Integer> queue = new LinkedList<Integer>(); 

		// Mark the current node as visited and enqueue it 
		visited[s]=true; 
		queue.add(s); 

		while (queue.size() != 0) 
		{ 
			// Dequeue a vertex from queue and print it 
			s = queue.poll(); 
			System.out.print(s+" "); 

			// Get all adjacent vertices of the dequeued vertex s 
			// If a adjacent has not been visited, then mark it 
			// visited and enqueue it 
			Iterator<Integer> i = adj[s].listIterator(); 
			while (i.hasNext()) 
			{ 
				int n = i.next(); 
				if (!visited[n]) 
				{ 
					visited[n] = true; 
					queue.add(n); 
				} 
			} 
		} 
	} 

	// Driver method to 
	public static void main(String args[]) 
	{ 
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the no. of nodes to be present in the graph");
		int n=sc.nextInt();
		BFSTraversal g = new BFSTraversal(n); 
		System.out.println("Enter the no. of edges to present in the graph");
		int no_edges=sc.nextInt();
		System.out.println("Enter the edges as (edgeno, edgeno)");
		for(int i=0;i<no_edges;i++){
			g.addEdge(sc.nextInt(),sc.nextInt());
		}
		System.out.println("Enter the vertex no from which the bfs should start \n (Note : 0 based indexing is followed.)");
		int x=sc.nextInt();
		System.out.println("Following is Breadth First Traversal "+ 
						"(starting from vertex "+x+" )"); 

		g.BFS(x); 
	} 
} 
