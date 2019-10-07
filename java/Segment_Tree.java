import java.util.*;

class Segment_Tree{

	static int tree[];
	static int arr[] = {1,2,3,4};

	/*public static void main(String args[]){
		int n = 4;
		
		int q = 3;
		int mat[][] = {{0,0,2},{1,1,2},{0,0,2}};
		int k = (int) Math.pow(2,Math.ceil((Math.log(n)/Math.log(2))+1))+2;
		tree = new int[k];

		constructST(1,0,n-1);

		for(int i=0;i<q;i++)
		{
			if(mat[i][0] == 0)
			{
				int a = query(1,mat[i][1],mat[i][2],0,n-1);
				System.out.println(a);
			}
			else
			{
				update(1,mat[i][1],mat[i][2],0,n-1);
			}
		}

	}*/

	static void constructST(int id,int l,int r){
		if(l==r)
		{
			tree[id] = arr[l];
			return;
		}

		int mid = (l+r)/2;
		constructST(2*id,l,mid);
		constructST((2*id)+1,mid+1,r);
		tree[id] = tree[2*id] + tree[(2*id)+1];
	}

	static int query(int id,int x,int y,int l,int r){
		if(x<=l && r<= y)
		{
			return tree[id];
		}
		if(r<x || y<l)
		{
			return 0;
		}
		int mid = (l+r)/2;
		int a = query(2*id,x,y,l,mid);
		int b = query((2*id)+1,x,y,mid+1,r);
		return a+b;
	}

	static void update(int id,int x,int val,int l,int r){
		if(l==r)
		{
			return;
		}
		if(l<=x && x<=r)
		{
			tree[id] += val;
		}
		if(x<l || r<x)
		{
			return;
		}
		int mid = (l+r)/2;
		update(2*id,x,val,l,mid);
		update((2*id)+1,x,val,mid+1,r);
	}
}