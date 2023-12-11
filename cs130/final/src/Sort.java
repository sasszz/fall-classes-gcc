import java.util.ArrayList;

public class Sort {

    public static <E extends Comparable<? super E>> void insertionSort(E[] array) {
        for (int i = 1; i < array.length; i++) {
            for (int j = i; j > 0 && array[j].compareTo(array[j - 1]) < 0; j--) {
                swap(array, j, j - 1);
            }
        }
    }

    public static <E extends Comparable<? super E>> void insertionSort(ArrayList<E> arrayList) {
        for (int i = 1; i < arrayList.size(); i++) {
            for (int j = i; j > 0 && arrayList.get(j).compareTo(arrayList.get(j - 1)) < 0; j--) {
                swap(arrayList, j, j - 1);
            }
        }
    }

    public static <E extends Comparable<? super E>> void bubbleSort(E[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = array.length - 1; j > i; j--) {
                if (array[j].compareTo(array[j - 1]) < 0) {
                    swap(array, j, j - 1);
                }
            }
        }
    }

    public static <E extends Comparable<? super E>> void bubbleSort(ArrayList<E> arrayList) {
        for (int i = 0; i < arrayList.size() - 1; i++) {
            for (int j = arrayList.size() - 1; j > i; j--) {
                if (arrayList.get(j).compareTo(arrayList.get(j - 1)) < 0) {
                    swap(arrayList, j, j - 1);
                }
            }
        }
    }

    public static <E extends Comparable<? super E>> void selectionSort(E[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int lowindex = i;
            for (int j = array.length - 1; j > i; j--)
                if (array[j].compareTo(array[lowindex]) < 0)
                    lowindex = j;
            swap(array, i, lowindex);
        }
    }

    public static <E extends Comparable<? super E>> void selectionSort(ArrayList<E> arrayList) {
        for (int i = 0; i < arrayList.size() - 1; i++) {
            int lowindex = i;
            for (int j = arrayList.size() - 1; j > i; j--)
                if (arrayList.get(j).compareTo(arrayList.get(lowindex)) < 0)
                    lowindex = j;
            swap(arrayList, i, lowindex);
        }
    }

    private static <E> void swap(E[] array, int p1, int p2) {
        E temp = array[p1];
        array[p1] = array[p2];
        array[p2] = temp;
    }

    private static <E> void swap(ArrayList<E> arrayList, int p1, int p2) {
        E temp = arrayList.get(p1);
        arrayList.set(p1, arrayList.get(p2));
        arrayList.set(p2, temp);
    }
}
