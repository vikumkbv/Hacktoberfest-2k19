mport java.util.Scanner;
import java.util.*;

class Graph{
    Node front ;
	Node rear ;
    int size = 0;
    
    public int L;
    public Node[] arr;

    //public int[] array;
    //public int count =1;
    //public int[] array = new int[10*10*10*10];
    public class Node{
        int data;
        int distance;
        Node next;
        Node(int data){
            this.data = data;
            next = null;
        }   
    }

    Graph(int L){
        this.L = L;   
        arr = new Node[L];
        //array = new int[L];
        for(int i=0;i<L;i++){
            Node n = new Node(i);
            arr[i] = n;
            //array[i] = -1;
        }
    }

    public void edge(int x,int y){
        Node n = new Node(y);
        Node n1 = arr[x];
        while(n1.next!=null){
            n1 = n1.next;
        }
        n1.next = n;
        n1.distance = a;
        // System.out.println(n1.data + " " + n1.next.data);
    }

    public int time =0;

    public void DFSvisit(int visitedArr[], Node n1, int discoveredArr[],int finalTime[]){
        System.out.print(n1.data+" ");
        visitedArr[n1.data]=1;
        time = time +1;
        discoveredArr[n1.data]=time;
        while(n1.next!=null){
            if(visitedArr[n1.next.data]==0){
                DFSvisit(visitedArr,arr[n1.next.data],discoveredArr,finalTime);
            }
            n1=n1.next;
        }
        visitedArr[n1.data]=2;
        time =time+1;
        finalTime[n1.data]=time; 
    }

    public void DFS(int x){
        int[] visited =new int[L];
        int[] discoveredTime = new int[L];
        int[] finalTime = new int[L];
        
        Node n1 = arr[x];
        if(visited[x]==0){
            DFSvisit(visited,n1,discoveredTime,finalTime);
        }
        
    }   

}

class DFSImplemented{
    public static void main(String[] args){
        Graph graph = new Graph(8);
        // graph.edge(1,2);
        // graph.edge(2,3);
        // graph.edge(2,4);
        // graph.edge(3,4);
        // graph.edge(3,5);
        // graph.edge(5,6);
        // graph.edge(5,4);
        // graph.edge(6,7);
        // graph.edge(6,4);
        // graph.edge(7,4);


        graph.edge(1,2);
        graph.edge(2,3);
        graph.edge(3,4);
        graph.edge(4,2);
        graph.edge(4,4);

        // graph.edge(0,1);
        // graph.edge(0,2);
        // graph.edge(1,4);
        // graph.edge(4,3);
        // graph.edge(2,4);
        // graph.edge(2,5);

        // graph.edge(1,2);
        // graph.edge(1,3);
        // graph.edge(2,4);
        // graph.edge(3,5);
        // graph.edge(3,2);
        // graph.edge(5,4);
        // graph.edge(5,6);
        // graph.edge(4,7);
        // graph.edge(6,7);

        graph.DFS(1);
    }
}