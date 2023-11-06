import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter the file name or type QUIT to exit:\n");
        String fileName = scanner.nextLine();

        while (true) {


            if (fileName.equalsIgnoreCase("QUIT")) {
                break;
            }

            File file = new File(fileName);

            if (!file.exists()) {
                System.out.println("File '" + fileName + "' is not found.");
                System.out.print("Please re-enter the file name or type QUIT to exit:\n");
                fileName = scanner.nextLine();
                continue;
            }

            try {
                Scanner fileScanner = new Scanner(file);

                while (fileScanner.hasNextLine()) {
                    String line = fileScanner.nextLine();
                        String modifiedSentence = convertText(line);
                        String capitalizedSentence = capitalizeFirstWord(modifiedSentence.trim());
                        System.out.println(capitalizedSentence);
                }

                fileScanner.close();
                break;
            } catch (FileNotFoundException e) {
                System.out.println("Error reading the file: " + e.getMessage());
            }
        }

        scanner.close(); // Close the console input scanner
    }

    public static String convertText(String inputText) {
        StringBuilder outputText = new StringBuilder();
        boolean lastCharWasSpace = false;
        boolean lastCharWasPunctuation = false;

        for (int i = 0; i < inputText.length(); i++) {
            char c = inputText.charAt(i);

            if(c == '!' || c == '.' || c == '?') {
                lastCharWasPunctuation = true;
            }

            if (Character.isUpperCase(c)) {
                if(lastCharWasPunctuation == false) {
                    outputText.append(' ');
                    outputText.append(Character.toLowerCase(c));
                }
                else {
                    outputText.append(' ');
                    outputText.append(Character.toUpperCase(c));
                    lastCharWasPunctuation = false;
                }
            } else {
                outputText.append(c);
                lastCharWasSpace = Character.isWhitespace(c);
            }
        }

        return outputText.toString();
    }


    public static String capitalizeFirstWord(String input) {
        if (input == null || input.isEmpty()) {
            return input; // Return the input as is if it's null or empty.
        }

        // Convert the first character to uppercase and concatenate the rest of the string.
        return Character.toUpperCase(input.charAt(0)) + input.substring(1);
    }

}
