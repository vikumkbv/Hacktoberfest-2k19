import java.util.*;

public class BinarySearch {
    private ArrayList<Integer> arr;
    private int item;
    private int search = 0;

    public BinarySearch(ArrayList<Integer> arr, int item) {
        this.arr = arr;
        this.item = item;
    }


    public int search() {
//        index of low and high part of array
        int low = 0;
        int high = arr.size()-1;
        int mid = 0;
        int guess = 0;

//        while array has still more than one element
        while (low <= high) {
            search++;
            mid = (low + high)/2;
            guess = arr.get(mid);
            if (guess == item) {
                return mid;
            } else if (guess > item) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (arr.contains(item)) {
            return arr.size();
        } else {
            return -1;
        }
    }

    public int numSearch() {
        return search;
    }
}
