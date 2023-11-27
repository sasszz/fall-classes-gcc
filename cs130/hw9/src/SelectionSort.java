public class SelectionSort {

    public static void measureTime(String algorithm, int[] array) {
        long startTime = System.currentTimeMillis();

        // Run selection sort
        selectionSort(array);

        long endTime = System.currentTimeMillis();
        System.out.println(algorithm + ": " + (endTime - startTime) + " ms");
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
            // swap array[minIndex] and array[i]
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
}
