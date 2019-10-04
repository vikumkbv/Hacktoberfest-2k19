import java.util.Scanner;
class Bank
{   
	static int count=0;
	int bal;
	int ac_no;
	String name;
	Bank(String name,int no)
	{
		this.name=name;
		bal=no;
		ac_no=++count;
		System.out.println("YOUR ACCOUNT NO IS:-"+ac_no);
	}
	void deposit(int amt)
	{
		bal=bal+amt;
	}
	void withdraw(int amt)
	{
		if ((bal-amt)<500)
		{
			System.out.println("Minimum balance of 500 is required");
	   	}
		else 
        {
				bal-=amt;
		}
	}
	void display()
	{
		System.out.println("ACCOUNT HOLDER'S NAME:-"+name+"\nACCOUNT NO:-"+ac_no+"\nBALANCE:-"+bal);
	}
	public static void main (String args[])
	{
		Scanner in = new Scanner(System.in);
		int choice,ac_no,amt,ac,sum,i;
		String mb;
		Bank person[]=new Bank[100];
		do
		{
		System.out.println("Menu\n1.To open an account\n2.To Deposit\n3.To Withdraw\n4.To Display\n5.Exit\nEnter your choice\n");
		choice = in.nextInt();
		
		switch (choice)
		{
			case 1:
					System.out.println("ENTER THE NO OF ACCOUNTS U WANT TO OPEN");
					ac = in.nextInt();
					sum=count+ac;
					System.out.println("ENTER MEMBER'S NAME");
					in.nextLine();
					for(i=count;i<sum;i++)
					{
					
					mb=in.nextLine();
					person[i]=new Bank(mb,500);
					}
					break;
			case 2: 
					System.out.println("ENTER ACCOUNT NO AND AMOUNT U WANT TO DEPOSIT");
					ac_no = in.nextInt();
					amt = in.nextInt();
					if (ac_no>count)
					{
						System.out.println("ACCOUNT DOESN'T EXIST");
					}
					else
					{
						person[ac_no-1].deposit(amt);
					}
					break;
			case 3: 
					System.out.println("ENTER ACCOUNT NO AND AMOUNT U WANT TO WITHDRAW");
					ac_no = in.nextInt();
					amt = in.nextInt();
					if (ac_no>count)
					{
						System.out.println("ACCOUNT DOESN'T EXIST");
					}
					else
					{
						person[ac_no-1].withdraw(amt);
					}
					break;
			case 4: System.out.println("Enter account no");
					ac_no = in.nextInt();
					if (ac_no>count)
					{
						System.out.println("ACCOUNT DOESN'T EXIST");
					}
					else
					{
						person[ac_no-1].display();
					}
					break;
			default:System.out.println("Invalid choice");
			
		}
		}while (choice!=5);
	}
}

//class BankAccount

	
	

					
					
			
