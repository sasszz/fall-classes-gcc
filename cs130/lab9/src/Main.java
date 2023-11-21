import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int[] sizes = {50000, 100000, 200000};

        for (int size : sizes) {
            int[] bestCaseArray = generateSortedArray(size);
            int[] averageCaseArray = generateRandomArray(size);
            int[] worstCaseArray = generateInverseSortedArray(size);

            System.out.println("Array Size: " + size);

            // Best Case (Already Sorted)
            long startTime = System.currentTimeMillis();
            selectionSort(bestCaseArray.clone());
            long bestCaseTime = System.currentTimeMillis() - startTime;
            System.out.println("Best Case Time: " + bestCaseTime + " milliseconds");

            // Average Case (Randomly Generated)
            startTime = System.currentTimeMillis();
            selectionSort(averageCaseArray.clone());
            long averageCaseTime = System.currentTimeMillis() - startTime;
            System.out.println("Average Case Time: " + averageCaseTime + " milliseconds");

            // Worst Case (Inverse Sorted)
            startTime = System.currentTimeMillis();
            selectionSort(worstCaseArray.clone());
            long worstCaseTime = System.currentTimeMillis() - startTime;
            System.out.println("Worst Case Time: " + worstCaseTime + " milliseconds");

            System.out.println(); // Separate results for different array sizes
        }
    }

    private static int[] generateSortedArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = i;
        }
        return array;
    }

    private static int[] generateRandomArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = (int) (Math.random() * size);
        }
        return array;
    }

    private static int[] generateInverseSortedArray(int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = size - i - 1;
        }
        return array;
    }

    private static void selectionSort(int[] array) {
        int n = array.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap the found minimum element with the first element
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
}
