import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int[] sizes = {50000, 100000, 200000};

        for (int size : sizes) {
            int[] bestCase = SortingUtils.generateSortedArray(size);
            int[] averageCase = SortingUtils.generateRandomArray(size);
            int[] worstCase = SortingUtils.generateInverseSortedArray(size);
            System.out.println("------------------------------------------");
            System.out.println("Array size: " + size);
            System.out.println("------------------------------------------");

            // Best Case
            BubbleSort.measureTime("Bubble Sort (Best Case)", Arrays.copyOf(bestCase, size));
            SelectionSort.measureTime("Selection Sort (Best Case)", Arrays.copyOf(bestCase, size));
            InsertionSort.measureTime("Insertion Sort (Best Case)", Arrays.copyOf(bestCase, size));

            System.out.println();

            // Average Case
            BubbleSort.measureTime("Bubble Sort (Average Case)", Arrays.copyOf(averageCase, size));
            SelectionSort.measureTime("Selection Sort (Average Case)", Arrays.copyOf(averageCase, size));
            InsertionSort.measureTime("Insertion Sort (Average Case)", Arrays.copyOf(averageCase, size));

            System.out.println();

            // Worst Case
            BubbleSort.measureTime("Bubble Sort (Worst Case)", Arrays.copyOf(worstCase, size));
            SelectionSort.measureTime("Selection Sort (Worst Case)", Arrays.copyOf(worstCase, size));
            InsertionSort.measureTime("Insertion Sort (Worst Case)", Arrays.copyOf(worstCase, size));

            System.out.println();
        }
    }
}
