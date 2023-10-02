import java.io.*;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter the file name: \n");
        String fileName = scanner.nextLine();

        while (true) {

            try {
                double total = 0;
                int count = 0;

                // Open the file
                File file = new File(fileName);
                Scanner fileScanner = new Scanner(file);

                // Read and sum the numbers in the file
                while (fileScanner.hasNextDouble()) {
                    double number = fileScanner.nextDouble();
                    total += number;
                    count++;
                }

                // Calculate the average
                double average = total / count;

                // Create a number format with commas for thousands separators
                NumberFormat nf = NumberFormat.getNumberInstance(Locale.US);

                // Format the results
                String formattedTotal = nf.format(total);
                String formattedAverage = nf.format(average);

                // Display the results
                System.out.println("Total: " + formattedTotal);
                System.out.println("Average: " + formattedAverage);

                // Close the file scanner
                fileScanner.close();
                break; // Exit the loop if successful
            } catch (FileNotFoundException e) {
                System.out.println("File '" + fileName + "' does not exist.");
                System.out.print("Please enter the file name again: \n");
                fileName = scanner.nextLine();

            } catch (Exception e) {
                System.out.println("An error occurred: " + e.getMessage());
            }
        }

        scanner.close();
    }
}
