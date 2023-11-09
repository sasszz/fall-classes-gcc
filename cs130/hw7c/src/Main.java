import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        // Create an empty hashmap
        HashMap<String, String> morseCodeMap = new HashMap<>();

        // Read the contents of morse.txt and populate the hashmap
        try (BufferedReader br = new BufferedReader(new FileReader("morse.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\t");
                String key = parts[0];
                String value = parts[1];
                morseCodeMap.put(key, value);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Get user input
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

            // Read and process the contents of the specified file
            processFile(fileName, morseCodeMap);


            // Convert the user input to Morse code
            String translatedCode = convertFromMorseCode(fileName, morseCodeMap);

            // Print the result
            System.out.println(translatedCode + " ");

        }

        scanner.close();
    }

    private static void processFile(String fileName, HashMap<String, String> morseCodeMap) {
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                // Convert each line from Morse code to uppercase letters and print the result
                String translatedCode = convertFromMorseCode(line.trim(), morseCodeMap);
                System.out.println(translatedCode);
            }
            System.exit(0);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String convertFromMorseCode(String input, HashMap<String, String> morseCodeMap) {
        StringBuilder translatedCodeBuilder = new StringBuilder();

        // Split the input into Morse code tokens
        String[] morseTokens = input.split(" ");

        for (String morseToken : morseTokens) {
            // Check if the Morse code token is present in the hashmap
            if (morseCodeMap.containsValue(morseToken)) {
                // Find the corresponding key (character) for the Morse code token
                for (String key : morseCodeMap.keySet()) {
                    if (morseCodeMap.get(key).equals(morseToken)) {
                        translatedCodeBuilder.append(key);
                        break;
                    }
                }
            }
        }
        return translatedCodeBuilder.toString();
    }
}