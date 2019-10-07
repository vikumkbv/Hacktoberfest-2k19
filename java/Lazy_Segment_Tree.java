//package Library.Algorithms;

import java.util.*;

public class Lazy_Segment_Tree{
	static int tree[];
	static int lazy[];
	static int arr[];
	/*public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		arr = new int[n];
		int k = (int) Math.pow(2,Math.ceil((Math.log(n)/Math.log(2)+1)))+1;
		tree = new int[k];
		lazy = new int[k];
		int i;
		
		for(i=0;i<n;i++)
		{
			arr[i] = in.nextInt();
		}
		constructST(1,0,n-1);

		int q = in.nextInt();
		for(i=0;i<q;i++)
		{
			int y = in.nextInt();
			if(y==0)
			{
				int l = in.nextInt()-1;
				int r = in.nextInt()-1;
				int ans = query(1,l,r,0,n-1);
				System.out.println(ans);
			}
			else
			{
				int l = in.nextInt()-1;
				int r = in.nextInt()-1;
				int x = in.nextInt();
				update(1,l,r,x,0,n-1);
			}
		}
	}*/

	static void constructST(int id,int l,int r){
		if(r==l)
		{
			tree[id] = arr[l];
			return;
		}

		int mid = (l+r)/2;
		constructST(2*id,l,mid);
		constructST((2*id)+1,mid+1,r);
		tree[id] = Math.min(tree[2*id],tree[(2*id)+1]);
	}

	static void update(int id,int x,int y,int val,int l,int r){
		if(l>r)
			return;

		//lazy propogation
		if(lazy[id] != 0)
		{
			tree[id] += lazy[id];
			if(l != r)
			{
				lazy[2*id] = lazy[id];
				lazy[(2*id)+1] = lazy[id];
			}
			lazy[id] = 0;
		}

		//full overlap
		if(x<=l && r<=y)
		{
			tree[id] += val;
			if(l != r)
			{
				lazy[2*id] += val;
				lazy[(2*id)+1] += val;
			}
			return;
		}

		//no overlap
		if(y<l ||r<x)
			return;

		//partial overlap
		int mid = (l+r)/2;
		update(2*id,x,y,val,l,mid);
		update((2*id)+1,x,y,val,mid+1,r);
		tree[id] = Math.min(tree[2*id],tree[(2*id)+1]);
	}

	static int query(int id,int x,int y,int l,int r){
		if(l>r)
			return 999;

		if(lazy[id] != 0)
		{
			tree[id] += lazy[id];
			if(l != r)
			{
				lazy[2*id] = lazy[id];
				lazy[(2*id)+1] = lazy[id];
			}
			lazy[id] = 0;
		}

		if(x<=l && r<=y)
		{
			return tree[id];
		}

		if(y<l || r<x)
			return 999;

		int mid = (l+r)/2;
		int a = query(2*id,x,y,l,mid);
		int b = query((2*id)+1,x,y,mid+1,r);
		return Math.min(a,b);
	}
}

