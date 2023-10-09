import java.io.*;
import java.util.*;

public class Main {
    private static final String GIRL_NAMES_FILE = "GirlNames.txt";
    private static final String BOY_NAMES_FILE = "BoyNames.txt";

    public static void main(String[] args) {
        String[] girlNames = loadFileToArray(GIRL_NAMES_FILE);
        String[] boyNames = loadFileToArray(BOY_NAMES_FILE);

        if (girlNames == null && boyNames == null) {
            System.out.println("Both files are missing. Exiting the program.");
            return;
        } else if (girlNames == null) {
            System.out.println("Girl names file is missing. Exiting the program.");
            return;
        } else if (boyNames == null) {
            System.out.println("Boy names file is missing. Exiting the program.");
            return;
        }

        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter a name to search or type QUIT to exit:\n");
            String input = scanner.nextLine().trim();

            if (input.equalsIgnoreCase("QUIT")) {
                break;
            }

            String formattedName = input.substring(0, 1).toUpperCase() + input.substring(1).toLowerCase();

            int girlLine = searchAndDisplayResult(formattedName, girlNames, "girl names");
            int boyLine = searchAndDisplayResult(formattedName, boyNames, "boy names");

            if (girlLine == -1 && boyLine == -1) {
                System.out.println("The name '" + formattedName + "' was not found in either list.");
            } else {
                if (girlLine != -1 && boyLine != -1) {
                    System.out.println("The name '" + formattedName + "' was found in both lists: boy names (line " + boyLine + ") and girl names (line " + girlLine + ").");
                } else {
                    if (girlLine != -1) {
                        System.out.println("The name '" + formattedName + "' was found in popular girl names list (line " + girlLine + ").");
                    }
                    if (boyLine != -1) {
                        System.out.println("The name '" + formattedName + "' was found in popular boy names list (line " + boyLine + ").");
                    }
                }
            }
        }

        scanner.close();
    }

    private static String[] loadFileToArray(String fileName) {
        try {
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            List<String> namesList = new ArrayList<>();
            String line;

            while ((line = reader.readLine()) != null) {
                namesList.add(line);
            }

            reader.close();

            return namesList.toArray(new String[0]);
        } catch (IOException e) {
            return null;
        }
    }

    private static int searchAndDisplayResult(String name, String[] namesArray, String listType) {
        for (int i = 0; i < namesArray.length; i++) {
            if (namesArray[i].equalsIgnoreCase(name)) {
                return i + 1; // Adding 1 to make the line number 1-based instead of 0-based
            }
        }

        return -1; // Return -1 if not found
    }
}
