import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        ArrayList<ArrayList<Double>> data = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        boolean exitRequested = false;
        System.out.print("Please enter the file name or type QUIT to exit:\n");

        while (!exitRequested) {
            String input = scanner.nextLine().trim();

            if (input.equalsIgnoreCase("QUIT")) {
                break;
            }

            try {
                BufferedReader reader = new BufferedReader(new FileReader(input));
                String line;

                while ((line = reader.readLine()) != null) {
                    String[] values = line.split("[,\\s]+"); // Split by commas or spaces
                    ArrayList<Double> row = new ArrayList<>();

                    for (String value : values) {
                        row.add(Double.parseDouble(value.trim()));
                    }

                    data.add(row);
                }

                reader.close();
            } catch (FileNotFoundException e) {
                System.out.println("File: " + input + " does not exist.");
                System.out.print("Please enter the file name again or type QUIT to exit:\n");
                continue; // Continue to the next iteration
            } catch (IOException e) {
                System.out.println("Error reading the file.");
            }

            int maxColumns = getMaxColumnCount(data);

            // Print Row information
            for (int i = 0; i < data.size(); i++) {
                ArrayList<Double> row = data.get(i);
                double rowSubtotal = getRowSubtotal(row);
                System.out.printf("Row %d Length: %d, Subtotal: %.3f%n", i, row.size(), rowSubtotal);
            }

            // Print Column information
            for (int j = 0; j < maxColumns; j++) {
                ArrayList<Double> column = getColumn(data, j);
                double columnSubtotal = getColumnSubtotal(column);
                System.out.printf("Column %d Height: %d, Subtotal: %.3f%n", j, column.size(), columnSubtotal);
            }

            // Print Total information
            double total = getTotal(data);
            System.out.printf("Array Elements: %d, Total: %.3f%n", getTotalElementCount(data), total);

            // Clear the data for the next file
            data.clear();
            break;
        }
    }

    public static double getRowSubtotal(ArrayList<Double> row) {
        double subtotal = 0.0;

        for (Double value : row) {
            subtotal += value;
        }

        return subtotal;
    }

    public static ArrayList<Double> getColumn(ArrayList<ArrayList<Double>> data, int colIndex) {
        ArrayList<Double> column = new ArrayList<>();

        for (ArrayList<Double> row : data) {
            if (colIndex < row.size()) {
                column.add(row.get(colIndex));
            }
        }

        return column;
    }

    public static double getColumnSubtotal(ArrayList<Double> column) {
        double subtotal = 0.0;

        for (Double value : column) {
            subtotal += value;
        }

        return subtotal;
    }

    public static double getTotal(ArrayList<ArrayList<Double>> data) {
        double total = 0.0;

        for (ArrayList<Double> row : data) {
            for (Double value : row) {
                total += value;
            }
        }

        return total;
    }

    public static int getMaxColumnCount(ArrayList<ArrayList<Double>> data) {
        int maxColumns = 0;

        for (ArrayList<Double> row : data) {
            maxColumns = Math.max(maxColumns, row.size());
        }

        return maxColumns;
    }

    public static int getTotalElementCount(ArrayList<ArrayList<Double>> data) {
        int count = 0;

        for (ArrayList<Double> row : data) {
            count += row.size();
        }

        return count;
    }
}
