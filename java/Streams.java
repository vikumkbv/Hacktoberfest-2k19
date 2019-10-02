import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

/*
 * Example of Java 8's Streaming API.
 */
public class Streams {

    /*
     * Java's streaming API is an easy way of manipulating collections
     * using a stepped function approach. Data can be filtered or modified
     * depending on the steps used in the process.
     */

    // Example 1: Replace all instances of "old" with "rpl" in the given list.
    public static List<String> replace(List<String> in, String old, String rpl) {
        return in.stream()
        .map(s -> s.equals(old) ? rpl : old) // Replace element if it matches the old string
        .collect(Collectors.toList());       // Collect result
    }

    // Example 2: Filter out any strings that are duplicates or contain a vowel
    public static List<String> noVowel(List<String> in) {
        return in.stream()
            .distinct()                         // Ensure elements are unique
            .filter(i -> !i.matches("[aeiou]")) // Keep elements that don't contain a vowel
            .collect(Collectors.toList());      // Collect result
    }
    
    // Example 3: Get the total product of every number in the list
    public static int product(List<Integer> in) {
        return in.stream()
            .reduce((i1, i2) -> i1 * i2) // Multiply each element together to get the product
            .orElse(0);                  // Ensure an empty list results in 0
        }

    // Example 4: Get an array of cubed odd numbers
    public static int[] oddCubes(int low, int high) {
        return IntStream.range(low, high)
            .filter(i -> i % 2 != 0)  // Filter even values out
            .map(i -> Math.pow(i, 3)) // Multiply i to the power of 3
            .toArray();               // Collect result
    }        

    // Example 5: Execute a runnable if all list entries are true
    public static void run(Runnable run, List<Boolean> bools) {
        if (bools.stream().allMatch(b -> b == true)) // Check if all booleans are true
            run.run();                               // Ran if the above condition is met
    }
}
