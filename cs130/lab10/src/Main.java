import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Please enter a string for reversal or type QUIT to exit:\n");
            String input = scanner.nextLine();

            if (input.equalsIgnoreCase("QUIT")) {
                break;
            }

            String reversedString = reverseString(input);
            System.out.println("Reversed string: " + reversedString);
        }

        scanner.close();
    }

    private static String reverseString(String str) {
        if (str.length() < 2) {
            return str;
        } else {
            return reverseString(str.substring(1)) + str.charAt(0);
        }
    }
}
