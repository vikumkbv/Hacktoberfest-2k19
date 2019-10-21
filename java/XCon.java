import java.util.Scanner;

public class XCon {
  public static void main(String[] args) {
    Scanner kb = new Scanner(System.in);
    String response = "";
    int tries = 0;
    
    System.out.println("X");
    do {
      if(tries == 5) System.out.println("Just write X... -_-");
      tries++;
      response = kb.nextLine();
    } while(response.equals("X"));
    
    System.out.println("Okay, bye.");
    
  }
}
