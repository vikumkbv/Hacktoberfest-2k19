import java.util.*;

import javax.lang.model.util.ElementScanner6;

public class kruskals
{
    static class Edge
    {
        int nbr;
        int wt;
        Edge(int nbr,int wt)
        {
            this.nbr=nbr;
            this.wt=wt;
        }
    }
    public static class KEdge implements Comparable<KEdge>{
        int v1;
        int v2;
        int wt;
        KEdge(int v1,int v2,int wt)
        {
            this.v1=v1;
            this.v2=v2;
            this.wt=wt;
        }
        public int compareTo(KEdge other)
        {
            return this.wt-other.wt;
        }
    }
    static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
    static void addEdge(ArrayList<ArrayList<Edge>> g,int v1,int v2,int wt)
    {
        Edge e1 = new Edge(v2,wt);
        g.get(v1).add(e1);
        Edge e2 = new Edge(v1,wt);
        g.get(v2).add(e2);// here we are making edge

    }
    static void merge(int [] pa,int [] ra,int v1sl,int v2sl)
    {
        if(ra[v1sl]<ra[v2sl])
        {
            pa[v1sl]=v2sl;
        }
        else if(ra[v2sl]<ra[v1sl])
        {
            pa[v2sl]=v1sl;
        }
        else 
        {
            pa[v1sl]=v2sl;
            ra[v2sl]++;
        }
    }
    static int find(int [] pa,int v)
    {
        if(pa[v]==v)
        {
            return v;
        }
        else 
        {
            pa[v] = find(pa,pa[v]);
            return pa[v];// recursion to find the leader to which that vertex points
        }
    }
    static void kruskal(ArrayList<ArrayList<Edge>> g)
    {
        ArrayList<ArrayList<Edge>>mst = new ArrayList<>();
        int[]pa = new int[g.size()];
        int []ra = new int[g.size()];
        PriorityQueue<KEdge> pq = new PriorityQueue<>();
        for(int v=0;v<g.size();v++)
        {
            pa[v] = v;
            ra[v] = 1;
            mst.add(new ArrayList<Edge>());
            
        }
        for(int v=0;v<g.size();v++)
        {
            for(int n=0;n<g.get(v).size();n++)
            {
                Edge ne = g.get(v).get(n);
                if(v<ne.nbr)
                {
                    KEdge ke = new KEdge(v,ne.nbr,ne.wt);
                    pq.add(ke);
                }
            }
        }
            while(pq.size()>0)
            {
                KEdge ke = pq.remove();
                int v1 = ke.v1;
                int v2 = ke.v2;
                int v1sl = find(pa,v1); // find merge leader of vertex v1
                int v2sl = find(pa,v2); // find merge leader of vertex v2
                if(v1sl!=v2sl)
                {
                    merge(pa,ra,v1sl,v2sl); // merge their leader
                    addEdge(mst,v1,v2,ke.wt); // add edge btw vertex v1 and v2
                }
            }
        display(mst);
    }
    static void display(ArrayList<ArrayList<Edge>> g)
    {
        for(int v=0;v<g.size();v++)
        {
            System.out.print(v+" -> ");
            for(int n=0;n<g.get(v).size();n++)
            {
                Edge ne = g.get(v).get(n);// here we are extracting edge
                System.out.print(" [ "+ne.nbr+" , " +ne.wt+" ] ");

            }
            System.out.println();
        }
    }
    public static void main(String[] args)
    {
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        graph.add(new ArrayList<Edge>());
        addEdge(graph,0,1,20);//0
        addEdge(graph,1,2,10);
        addEdge(graph,0,3,40);
        addEdge(graph,2,3,20);
        addEdge(graph,3,4,2);
        addEdge(graph,2,5,5);
        addEdge(graph,4,5,3);
        addEdge(graph,5,6,3);
        addEdge(graph,4,6,8);//6
        //display(graph);
        kruskal(graph);
    }
}