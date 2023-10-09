import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        if (args.length < 1) {
            return;
        }

        String fileName = args[0];
        double[][] array = readArrayFromFile(fileName);

        if (array != null) {
            printRowSubtotals(array);
            printColumnSubtotals(array);
            System.out.printf("Array Total: %.3f%n", getTotal(array));        }
    }

    public static double[][] readArrayFromFile(String fileName) {
        double[][] array = null;
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            int rows = 0;
            int cols = 0;

            while ((line = reader.readLine()) != null) {
                rows++;
                String[] values = line.split("\\s+");
                cols = values.length;
            }

            array = new double[rows][cols];

            try (BufferedReader secondReader = new BufferedReader(new FileReader(fileName))) {
                int rowIndex = 0;
                while ((line = secondReader.readLine()) != null) {
                    String[] values = line.split("\\s+");
                    for (int colIndex = 0; colIndex < cols; colIndex++) {
                        array[rowIndex][colIndex] = Double.parseDouble(values[colIndex]);
                    }
                    rowIndex++;
                }
            } catch (IOException e) {
                System.err.println("Error reading the file: " + e.getMessage());
            }
        } catch (IOException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
        return array;
    }

    public static double getTotal(double[][] array) {
        double total = 0;
        for (double[] row : array) {
            for (double value : row) {
                total += value;
            }
        }
        return total;
    }

    public static void printRowSubtotals(double[][] array) {
        for (int i = 0; i < array.length; i++) {
            double subtotal = getRowTotal(array, i);
            System.out.printf("Row %d Subtotal: %.3f%n", i, subtotal);
        }
    }

    public static void printColumnSubtotals(double[][] array) {
        for (int j = 0; j < array[0].length; j++) {
            double subtotal = getColumnTotal(array, j);
            System.out.printf("Column %d Subtotal: %.3f%n", j, subtotal);
        }
    }

    public static double getRowTotal(double[][] array, int rowIndex) {
        double total = 0;
        for (double value : array[rowIndex]) {
            total += value;
        }
        return total;
    }

    public static double getColumnTotal(double[][] array, int colIndex) {
        double total = 0;
        for (double[] row : array) {
            total += row[colIndex];
        }
        return total;
    }
}
