public class Sort {

    public static void selectionSort(int[] array, int left, int right) {
        // Selection Sort algorithm implementation
        for (int i = left; i < right - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < right; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap array[i] and array[minIndex]
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }

    public static void insertionSort(int[] array, int left, int right) {
        // Insertion Sort algorithm implementation
        for (int i = left + 1; i < right; i++) {
            int key = array[i];
            int j = i - 1;

            while (j >= left && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }

            array[j + 1] = key;
        }
    }


    public static void bubbleSort(int[] array, int left, int right) {
        int n = right - left;
        int temp = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = left; j < right - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    // Swap elements
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}
