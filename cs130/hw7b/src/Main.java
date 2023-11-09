import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
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
        System.out.print("Please enter a string to convert to Morse code:\n");
        String userInput = scanner.nextLine().toUpperCase();

        // Convert the user input to Morse code
        String morseCode = convertToMorseCode(userInput, morseCodeMap);

        if (userInput.isEmpty()) {
            System.out.println("");
            return;
        }

        // Print the result
        System.out.println(morseCode + " ");

        scanner.close();
    }

    private static String convertToMorseCode(String input, HashMap<String, String> morseCodeMap) {
        StringBuilder morseCodeBuilder = new StringBuilder();

        for (char ch : input.toCharArray()) {
            String character = String.valueOf(ch);

            // Check if the character is present in the hashmap
            if (morseCodeMap.containsKey(character)) {
                morseCodeBuilder.append(morseCodeMap.get(character)).append(" ");
            } else {
                // If the character is not in the hashmap, consider it as a space
                morseCodeBuilder.append(" ");
            }
        }

        return morseCodeBuilder.toString().trim(); // Remove trailing space
    }
}
