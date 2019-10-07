import java.io.*;

public class MaxSubarraySum {

  private static int findMaxSum(int[] a, int l, int h) {
    int max_sum = Integer.MIN_VALUE;
    int curr_sum = 0;

    for (int i = l; i <= h; i++) {
      curr_sum += a[i];
      if (curr_sum > max_sum) {
        max_sum = curr_sum;
      }
      if (curr_sum < 0) {
        curr_sum = 0;
      }
    }

    return max_sum;
  }

  public static void main(String[] args) {
    System.out.println(findMaxSum(new int[] { -3, 2, -1, 4, -5 }, 0, 4)); // Expected output: 5
    System.out.println(findMaxSum(new int[] { -1, -2, -3, -4, -5 }, 0, 4)); // Expected output: -1
  }
}