import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter the file name or type QUIT to exit:\n");
        String fileName = scanner.nextLine().trim();
        while (true) {
            if (fileName.equalsIgnoreCase("QUIT")) {
                break;
            }

            File file = new File(fileName);

            if (file.exists() && file.isFile()) {
                int wordCount = countWordsInFile(file);
                System.out.println("Total number of words: " + wordCount);
                break;
            } else {
                System.out.println("File: " + fileName + " does not exist.");
                System.out.print("Please enter the file name again or type QUIT to exit:\n");
                fileName = scanner.nextLine().trim();
            }
        }

        scanner.close();
    }

    public static int countWordsInFile(File file) {
        int wordCount = 0;
        try (Scanner fileScanner = new Scanner(file)) {
            while (fileScanner.hasNext()) {
                fileScanner.next();
                wordCount++;
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return wordCount;
    }
}
