import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class FileSorting {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean validInput = false;
        System.out.print("Please enter the file name or type QUIT to exit:\n");
        while (!validInput) {
            String fileName = scanner.nextLine();

            if (fileName.equalsIgnoreCase("quit")) {
                break;
            }

            try {
                ArrayList<ArrayList<Integer>> numbers = processFile(fileName);

                for (ArrayList<Integer> line : numbers) {
                    Sort.selectionSort(line);
                    System.out.println(arrayListToString(line));
                }

                validInput = true;
            } catch (IOException e) {
                System.out.println("File " + fileName + " is not found.\nPlease re-enter the file name or type QUIT to exit:");
            }
        }

        scanner.close();
    }

    private static ArrayList<ArrayList<Integer>> processFile(String fileName) throws IOException {
        ArrayList<ArrayList<Integer>> lines = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = br.readLine()) != null) {
                ArrayList<Integer> numbers = processLine(line);
                lines.add(numbers);
            }
        } catch (IOException e) {
            throw e;
        }

        if (lines.isEmpty()) {
            System.out.println("File " + fileName + " is empty.");
            System.exit(0);
        }

        return lines;
    }

    private static ArrayList<Integer> processLine(String line) {
        ArrayList<Integer> numbers = new ArrayList<>();

        if (line.isEmpty()) {
            System.out.println("Line is empty.");
            System.exit(0);
        }

        String[] tokens = line.split(",");
        for (String token : tokens) {
            try {
                numbers.add(Integer.parseInt(token.trim()));
            } catch (NumberFormatException e) {
                System.out.println("Invalid number format in line - " + line);
                System.exit(0);
            }
        }

        return numbers;
    }

    private static String arrayListToString(ArrayList<Integer> list) {
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < list.size(); i++) {
            result.append(list.get(i));

            if (i < list.size() - 1) {
                result.append(",");
            }
        }

        return result.toString();
    }
}
