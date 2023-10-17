import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        System.out.print("Please enter the file name or type QUIT to exit:\n");
        while (true) {
            String filename = getInputFileName();
            if (filename == null) {
                break;
            }
            processFile(filename);
        }
    }

    private static String getInputFileName() {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            String input = reader.readLine().trim();
            if (input.equalsIgnoreCase("QUIT")) {
                System.exit(0);
            }
            return input;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    private static void processFile(String filename) {
        boolean fileNotFound = false;
        do {
            try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
                String[] lines = reader.lines().toArray(String[]::new);

                if (lines.length == 0) {
                    System.out.println("File '" + filename + "' is empty.");
                    System.exit(0);
                } else {
                    int totalLines = lines.length;
                    int matches = 0;

                    for (int i = 0; i < totalLines / 2; i++) {
                        if (lines[i].equals(lines[totalLines - 1 - i])) {
                            System.out.println("Match found: '" + lines[i] + "' on lines " + (i + 1) + " and " + (totalLines - i) + ".");
                            matches++;
                        }
                    }

                    if (matches == 0) {
                        System.out.println("No matches found.");
                        System.exit(0);
                    } else {
                        System.out.println("Total of " + matches + " matches found.");
                        System.exit(0);
                    }
                }
                fileNotFound = false;
            } catch (IOException e) {
                System.out.println("File '" + filename + "' is not found.");
                System.out.println("Please re-enter the file name or type QUIT to exit:");
                filename = getInputFileName();
                if (filename == null) {
                    break;
                }
                fileNotFound = true;
            }
        } while (fileNotFound);
    }
}
