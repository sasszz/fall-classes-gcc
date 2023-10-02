import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;

public class Main {

    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java ArrayOperations <filename>");
            return;
        }

        String fileName = args[0];

        double[] dataArray = readDataFromFile(fileName);

        if (dataArray != null) {
            DecimalFormat df = new DecimalFormat("#,##0.000");

            System.out.println("Total: " + df.format(getTotal(dataArray)));
            System.out.println("Average: " + df.format(getAverage(dataArray)));
            System.out.println("Highest: " + df.format(getHighest(dataArray)));
            System.out.println("Lowest: " + df.format(getLowest(dataArray)));
        }
    }

    public static double[] readDataFromFile(String fileName) {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            int count = 0;
            double[] dataArray;

            while ((line = reader.readLine()) != null) {
                count++;
            }

            dataArray = new double[count];

            // Reset the reader
            reader.close();

            // Create a new reader
            BufferedReader newReader = new BufferedReader(new FileReader(fileName));

            int index = 0;
            while ((line = newReader.readLine()) != null) {
                dataArray[index] = Double.parseDouble(line);
                index++;
            }

            return dataArray;
        } catch (IOException e) {
            System.out.printf("File: %s does not exist.%n", fileName);
            return null;
        } catch (NumberFormatException e) {
            System.out.println("Error: Invalid data format in the file.");
            return null;
        }
    }

    public static double getTotal(double[] arr) {
        double total = 0;
        for (double value : arr) {
            total += value;
        }
        return total;
    }

    public static double getAverage(double[] arr) {
        if (arr.length == 0) {
            return 0;
        }
        return getTotal(arr) / arr.length;
    }

    public static double getHighest(double[] arr) {
        if (arr.length == 0) {
            return 0;
        }
        double highest = arr[0];
        for (double value : arr) {
            if (value > highest) {
                highest = value;
            }
        }
        return highest;
    }

    public static double getLowest(double[] arr) {
        if (arr.length == 0) {
            return 0;
        }
        double lowest = arr[0];
        for (double value : arr) {
            if (value < lowest) {
                lowest = value;
            }
        }
        return lowest;
    }
}
