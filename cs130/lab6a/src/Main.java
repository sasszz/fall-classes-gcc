import java.util.Scanner;

public class Main {

        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.print("Please enter a string or type QUIT to exit:\n");
                String input = scanner.nextLine();

                if (input.equalsIgnoreCase("QUIT")) {
                    break;
                }

                int wordCount = countWords(input);
                System.out.println("There are " + wordCount + " words in that string.");
            }

            scanner.close();
        }

        public static int countWords(String input) {
            String[] words = input.split(" ");
            return words.length;
        }
    }