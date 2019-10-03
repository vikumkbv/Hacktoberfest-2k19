// Import the HashMap class
import java.util.HashMap;

public class HashMap {
  public static void main(String[] args) {
    // Create a HashMap object called capitalCities
    HashMap<String, String> capitalCities = new HashMap<String, String>();

    // Add keys and values (Country, City)
    capitalCities.put("England", "London");
    capitalCities.put("Germany", "Berlin");
    capitalCities.put("Norway", "Oslo");
    capitalCities.put("USA", "Washington DC");
    capitalCities.put("Sri Lanka", "Sri Jayawardenapura Kotte");
    System.out.println(capitalCities);
  }
}