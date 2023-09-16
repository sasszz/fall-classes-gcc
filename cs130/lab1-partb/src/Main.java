import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
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

            if (!file.exists()) {
                System.out.println("File: " + userInput + " does not exist.");
                System.out.print("Please enter the file name again or type QUIT to exit:\n");
                String retryInput = scanner.nextLine();
                if (retryInput.equalsIgnoreCase("QUIT")) {
                    System.exit(0);
                }
                File retryFile = new File(retryInput);
                if (retryFile.exists()) {
                    System.out.println("File: " + retryInput + " exists.");
                    break;
                } else {
                    System.out.println("File: " + retryInput + " does not exist.");
                }
            }

            try {
                FileReader fileReader = new FileReader(userInput);
                BufferedReader bufferedReader = new BufferedReader(fileReader);

                System.out.print("Please enter a character: \n");
                char userCharInput = scanner.nextLine().charAt(0);
                int count = 0;
                String line;

                while ((line = bufferedReader.readLine()) != null) {
                    for (int i = 0; i < line.length(); i++) {
                        char fileChar = line.charAt(i);
                        if (fileChar == userCharInput) {
                            count++;
                        }
                    }
                }

                System.out.print("Letter '" + userCharInput + "' occurs " + count + " times in the file '" + userInput + "'.\n");

                if (userInput.equalsIgnoreCase("QUIT")) {
                    break;
                }

                bufferedReader.close();
                fileReader.close();
                break;

            } catch (IOException e) {
                System.out.println("File: " + userInput + " does not exist.");
            }

        }

        scanner.close();
    }
}