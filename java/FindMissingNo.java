//Program to find missing number in an array !
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public static int GetInt() throws IOException
	{
	    return Integer.parseInt(br.readLine());
	}
	public static String[] GetArray() throws IOException
	{
	    return br.readLine().split(" ");
	}
	public static int ParseInt(String s)
	{
		return Integer.parseInt(s);
	}
	public static void main (String[] args) throws java.lang.Exception {
		int t=GetInt();
	    StringBuilder sb=new StringBuilder();
		while(t-->0)
		{
            int n=GetInt();
            String sarr[]=GetArray();
            int asum=((n)*(n+1))/2;
            int sum=0;
            
            for(int i=0; i<n-1; i++)
            {
                sum+=ParseInt(sarr[i]);
            }
            //System.out.println(sum);
            sb.append(asum-sum).append("\n");
		}
		System.out.println(sb);
	}
}
