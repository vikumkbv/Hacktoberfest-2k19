public class towerofhanoi {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s="s";
		String d="d";
		String h="h";
		int n=5;
		towerofhanoi(s,d,h,n);
	}
	public static void towerofhanoi(String s, String d, String h,int n)
	{
		if(n==0)
		{
			return;
		}
		towerofhanoi(s,h,d,n-1);
		System.out.println("move "+n+"th disk from "+s+" to +d");
		towerofhanoi(h,d,s,n-1);
	}

}
