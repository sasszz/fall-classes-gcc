import java.util.Scanner;

public class Sort {
     public static void bubbleSort(int[] array) {
            int n = array.length;
            boolean swapped;
            do {
                swapped = false;
                for (int i = 1; i < n; i++) {
                    if (array[i - 1] > array[i]) {
                        // swap array[i-1] and array[i]
                        int temp = array[i - 1];
                        array[i - 1] = array[i];
                        array[i] = temp;
                        swapped = true;
                    }
                }
            } while (swapped);
        }

        public static void insertionSort(int[] array) {
            int n = array.length;
            for (int i = 1; i < n; ++i) {
                int key = array[i];
                int j = i - 1;

            /* Move elements of array[0..i-1] that are greater than key
               to one position ahead of their current position */
                while (j >= 0 && array[j] > key) {
                    array[j + 1] = array[j];
                    j = j - 1;
                }
                array[j + 1] = key;
            }
        }

        public static void selectionSort(int[] array) {
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

        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            while (true) {
                System.out.println("Please enter a space separated list of numbers to sort or type QUIT to exit:");
                String input = scanner.nextLine().trim();
                if (input.equalsIgnoreCase("QUIT")) {
                    break;
                }

                if (input.isEmpty()) {
                    System.out.println("Invalid input. Please enter at least one number.");
                    continue;
                }

                // Parse input string to an array of integers
                String[] numbers = input.split(" ");
                int[] array = new int[numbers.length];
                for (int i = 0; i < numbers.length; i++) {
                    array[i] = Integer.parseInt(numbers[i]);
                }

                // Perform sorting using each algorithm
                int[] bubbleSortArray = array.clone();
                bubbleSort(bubbleSortArray);

                int[] insertionSortArray = array.clone();
                insertionSort(insertionSortArray);

                int[] selectionSortArray = array.clone();
                selectionSort(selectionSortArray);

                // Display sorted arrays
                System.out.println("Sorted array using Bubble Sort algorithm:");
                for (int num : bubbleSortArray) {
                    System.out.print(num + " ");
                }
                System.out.println();

                System.out.println("Sorted array using Insertion Sort algorithm:");
                for (int num : insertionSortArray) {
                    System.out.print(num + " ");
                }
                System.out.println();

                System.out.println("Sorted array using Selection Sort algorithm:");
                for (int num : selectionSortArray) {
                    System.out.print(num + " ");
                }
                System.out.println();
            }

            System.out.println("Exiting the program. Goodbye!");
            scanner.close();
        }
    }