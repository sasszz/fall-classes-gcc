import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Please enter the file name or type QUIT to exit:\n");
            String userInput = scanner.nextLine();

            if (userInput.equalsIgnoreCase("QUIT")) {
                break;
            }

            File file = new File(userInput);

            if (file.exists()) {
                printFileContents(userInput);
                break;
            } else {
                System.out.println("File: " + userInput + " does not exist.");
                while (true) {
                    System.out.print("Please enter the file name again or type QUIT to exit:\n");
                    String retryInput = scanner.nextLine();
                    if (retryInput.equalsIgnoreCase("QUIT")) {
                        System.exit(0);
                    }
                    File retryFile = new File(retryInput);
                    if (retryFile.exists()) {
                        System.out.println("File: " + retryInput + " exists.");
                        printFileContents(userInput);
                        break;
                    } else {
                        System.out.println("File: " + retryInput + " does not exist.");
                    }
                }
            }
        }
        scanner.close();
    }

    private static void printFileContents(String fileName) {
        int count = 0;
        try (Scanner fileScanner = new Scanner(new File(fileName))) {
            while (fileScanner.hasNextLine()) {
                count++;
                String line = fileScanner.nextLine();
                System.out.println(count + ": " + line);
            }
        } catch (FileNotFoundException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        }
    }

}