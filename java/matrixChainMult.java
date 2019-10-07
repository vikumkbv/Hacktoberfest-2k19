import java.util.*;
public class matrixChainMult
{
	public static void matchainmult(int[] a)
	{
		int[][] str = new int[a.length - 1][a.length - 1];
		
		for(int g = 0; g < a.length - 1; g++)
		{
			for(int i = 0; i < a.length - 1 - g; i++)
			{
				int j = i + g;
				
				if(g == 0)
					str[i][j] = 0;
				
				else if(g == 1)
					str[i][j] = a[i] * a[j] * a[j + 1];
				
				else
				{
					int min = Integer.MAX_VALUE;
					for(int k = 0; k < g; k++)
					{
						int left = str[i][i + k];
						int right = str[i + k + 1][j];
						int mult = a[i] * a[i + k + 1] * a[j + 1];
						
						if(left + right + mult< min)
						{
							min = left + right + mult;
						}
					}
					str[i][j] = min;
				}
			}
		}
		
		for(int i = 0; i < a.length - 1; i++)
		{
			for(int j = 0; j < a.length - 1; j++)
			{
				System.out.print(str[i][j] + "\t");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args)
	{
		int[] a = {1, 2, 3, 4, 5, 6};
		matchainmult(a);
	}
}