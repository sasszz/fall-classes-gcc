import java.util.Arrays;
import java.util.Random;

public class SortingUtils {

    public static void measureTime(String algorithm, int[] array) {
        long startTime = System.currentTimeMillis();

        // Run the sorting algorithm
        switch (algorithm) {
            case "Arrays.sort() (Best Case)":
            case "Arrays.sort() (Average Case)":
            case "Arrays.sort() (Worst Case)":
                Arrays.sort(array);
                break;
            default:
                System.out.println("Invalid algorithm");
                return;
        }

        long endTime = System.currentTimeMillis();
        System.out.println(algorithm + ": " + (endTime - startTime) + " ms");
    }

    public static int[] generateRandomArray(int size) {
        int[] array = new int[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(size);
        }
        return array;
    }

    public static int[] generateSortedArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = i;
        }
        return array;
    }

    public static int[] generateInverseSortedArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = size - i;
        }
        return array;
    }
}
