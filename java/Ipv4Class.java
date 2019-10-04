// Java program to determine class of Given ipv4 address
// This is a part of Hacktoerfest 2019
// @author: descifrado

import java.util.*;
class IPV4Class
{ 
	public static boolean isValidNum(String num)
	{
    	for(int i=0;i<num.length();i++)
    	{
    		if(num.charAt(i)>='0' && num.charAt(i)<='9')
    			continue;
    		else
    			return false;
    	}
    	int n=Integer.parseInt(num);
    	if(n<0 || n>255)
    		return false;
    	return true;
	}
	public static boolean isValidIpAddr(String ipAddr)
	{
		ipAddr=ipAddr+'.';
		String num="";
		int dots=0;
		for(int i=0;i<ipAddr.length();i++)
		{
			if(ipAddr.charAt(i)=='.')
			{
				dots++;
				if(!isValidNum(num))
					return false;
				num="";
			}
			else
			{
				num+=ipAddr.charAt(i);
			}
		}
		if(dots!=4)
			return false;
		return true;
	}

    public static String findClass(String ipAddr)
    {
    	int index = ipAddr.indexOf('.'); 
        String ipsub = ipAddr.substring(0,index); 
        int ip = Integer.parseInt(ipsub);
        // Class A 
        if (ip>=1 && ip<=126) 
            return "A"; 
        // Class B 
        else if (ip>=128 && ip<=191) 
            return "B"; 
        // Class C 
        else if (ip>=192 && ip<223) 
            return "C"; 
        // Class D 
        else if (ip >=224 && ip<=239) 
            return "D"; 
        // Class E 
        else
            return "E"; 
    } 
    public static void main(String[] args) 
    {
    	Scanner scan =new Scanner(System.in);
    	String ipAddr = scan.nextLine();
    	if(isValidIpAddr(ipAddr))
    	{
    		System.out.println("Valid: ");
    		String ipClass = findClass(ipAddr); 
        	System.out.println("Given IP address belings to Class "+ipClass);
    	}
    	else
    	{
    		System.out.println("Given IP address is not Valid");
    	}
    } 
} 
