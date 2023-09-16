import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    public static void calculateAverageFromFile(File file) {
        try {
            // Open the file for reading
            FileReader fileReader = new FileReader(file);
            BufferedReader bufferedReader = new BufferedReader(fileReader);

            String line;
            double total = 0;
            int count = 0;

            // Read numbers from the file and calculate the total
            while ((line = bufferedReader.readLine()) != null) {
                try {
                    double number = Double.parseDouble(line);
                    total += number;
                    count++;
                } catch (NumberFormatException e) {
                    // Ignore lines that are not valid numbers
                    System.err.println("Ignoring invalid number: " + line);
                }
            }

            // Close the file
            bufferedReader.close();

            if (count == 0) {
                System.out.println("File " + file.getName() + " is empty.");
            } else {
                // Calculate the average (even if the file is empty)
                double average = total / count;

                // Display the total and average with three decimal digits
                System.out.printf("Total: %.3f%n", total);
                System.out.printf("Average: %.3f%n", average);
            }

        } catch (IOException e) {
            System.err.println("Error reading the file: " + e.getMessage());
        }
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {

            // Ask the user for the file name
            System.out.print("Please enter the file name or type QUIT to exit:\n");
            String fileName = scanner.nextLine();

            if (fileName.equalsIgnoreCase("QUIT")) {
                break;
            }

            File file = new File(fileName);

            if (!file.exists()) {
                System.out.println("File: " + fileName + " does not exist.");
                System.out.print("Please enter the file name again or type QUIT to exit:\n");
                String retryInput = scanner.nextLine();
                if (retryInput.equalsIgnoreCase("QUIT")) {
                    System.exit(0);
                }
                File retryFile = new File(retryInput);
                if (retryFile.exists()) {
                    file = new File(retryInput);
                    calculateAverageFromFile(file);
                    break;
                } else {
                    System.out.println("File: " + retryInput + " does not exist.");
                }
            }

            calculateAverageFromFile(file);
            break;
        }
    }
}
