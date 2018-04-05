import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.*;

public class Ratatouille {

    private static class Range implements Comparable<Range>{
        int lowerBound;
        int higherBound;

        Range(int lowerBound, int higherBound) {
            this.lowerBound = lowerBound;
            this.higherBound = higherBound;
        }

        @Override
        public int compareTo(Range that) {
            if (this.lowerBound < that.lowerBound) {
                return -1;
            } else if (this.lowerBound > that.lowerBound) {
                return 1;
            } else {
                return this.higherBound - that.higherBound;
            }
        }
    }

    private static final String PATH = "/Users/Alex/Desktop/Algorithms";
    private static final String FILE_INPUT_PATH = PATH + "ratatouille_large_input.txt";
    private static final String FILE_OUTPUT_PATH = PATH + "ratatouille_large_output.txt";

    public static void main(String[] args) {

        test();
        //compete();
    }

    private static void compete() {
        List<String> recipeInformation = readFileInput(FILE_INPUT_PATH);

        List<String> output = new ArrayList<>();

        int caseIndex = 1;
        for(int i = 0; i < recipeInformation.size(); i++) {

            String[] values = recipeInformation.get(i).split(" ");
            int numberOfIngredients = Integer.parseInt(values[0]);
            int numberOfPackages = Integer.parseInt(values[1]);

            i++;
            String[] ingredientsValues = recipeInformation.get(i).split(" ");
            int[] ingredients = new int[numberOfIngredients];
            for(int j = 0; j < ingredients.length; j++) {
                ingredients[j] = Integer.parseInt(ingredientsValues[j]);
            }

            List<Integer[]> packages = new ArrayList<>();
            for(int j = 0; j < numberOfIngredients; j++) {
                i++;
                String[] packageValues = recipeInformation.get(i).split(" ");
                Integer[] currentPackage = new Integer[numberOfPackages];

                for(int k = 0; k < numberOfPackages; k++) {
                    currentPackage[k] = Integer.parseInt(packageValues[k]);
                }

                packages.add(currentPackage);
            }

            int numberOfKits = getNumberOfKits(ingredients, packages);

            output.add("Case #" + caseIndex + ": " + numberOfKits);
            caseIndex++;
        }

        writeDataOnFile(FILE_OUTPUT_PATH, output);
    }

    private static void test() {
        int[] ingredients1 = {500, 300};
        Integer[] gramsNeeded10 = {900};
        Integer[] gramsNeeded11 = {600};

        List<Integer[]> grams1 = new ArrayList<>();
        grams1.add(gramsNeeded10);
        grams1.add(gramsNeeded11);
        int numberOfKits1 = getNumberOfKits(ingredients1, grams1);

        int[] ingredients2 = {500, 300};
        Integer[] gramsNeeded20 = {1500};
        Integer[] gramsNeeded21 = {809};

        List<Integer[]> grams2 = new ArrayList<>();
        grams2.add(gramsNeeded20);
        grams2.add(gramsNeeded21);
        int numberOfKits2 = getNumberOfKits(ingredients2, grams2);

        int[] ingredients3 = {50, 100};
        Integer[] gramsNeeded30 = {450, 449};
        Integer[] gramsNeeded31 = {1100, 1101};

        List<Integer[]> grams3 = new ArrayList<>();
        grams3.add(gramsNeeded30);
        grams3.add(gramsNeeded31);
        int numberOfKits3 = getNumberOfKits(ingredients3, grams3);

        int[] ingredients4 = {500, 300};
        Integer[] gramsNeeded40 = {300};
        Integer[] gramsNeeded41 = {500};

        List<Integer[]> grams4 = new ArrayList<>();
        grams4.add(gramsNeeded40);
        grams4.add(gramsNeeded41);
        int numberOfKits4 = getNumberOfKits(ingredients4, grams4);

        int[] ingredients5 = {10};
        Integer[] gramsNeeded50 = {11, 13, 17, 11, 16, 14, 12, 18};

        List<Integer[]> grams5 = new ArrayList<>();
        grams5.add(gramsNeeded50);
        int numberOfKits5 = getNumberOfKits(ingredients5, grams5);

        int[] ingredients6 = {70, 80, 90};
        Integer[] gramsNeeded60 = {1260, 1500, 700};
        Integer[] gramsNeeded61 = {800, 1440, 1600};
        Integer[] gramsNeeded62 = {1700, 1620, 900};

        List<Integer[]> grams6 = new ArrayList<>();
        grams6.add(gramsNeeded60);
        grams6.add(gramsNeeded61);
        grams6.add(gramsNeeded62);
        int numberOfKits6 = getNumberOfKits(ingredients6, grams6);

        System.out.println(numberOfKits1 + " Expected: 1");
        System.out.println(numberOfKits2 + " Expected: 0");
        System.out.println(numberOfKits3 + " Expected: 1");
        System.out.println(numberOfKits4 + " Expected: 0");
        System.out.println(numberOfKits5 + " Expected: 3");
        System.out.println(numberOfKits6 + " Expected: 3");
    }

    private static int getNumberOfKits(int[] ingredients, List<Integer[]> grams) {

        if (ingredients.length == 0) {
            return 0;
        }

        Map<Integer, List<Range>> servingsCount = new HashMap<>();

        for(int i = 0; i < grams.size(); i++) {

            Integer[] grams1 = grams.get(i);
            for(int j = 0; j < grams1.length; j++) {

                // Lower bound: 0.9 * R * M < Q
                // Upper bound: 1.1 * R * M > Q
                //Simplifying
                // Lower bound:  0.9 * (Q/R) < M
                // Upper bound: 1.1 * (Q/R) > M
                double lowerBound = (10.0/11.0) * grams1[j] / ingredients[i];
                double upperBound = (10.0/9.0) * grams1[j] / ingredients[i];

                int lowerBoundInt = (int) Math.ceil(lowerBound);
                int upperBoundInt = (int) Math.floor(upperBound);

                Range newRange = new Range(lowerBoundInt, upperBoundInt);
                List<Range> servingsList;

                if ( servingsCount.containsKey(i)) {
                    servingsList = servingsCount.get(i);
                } else {
                    servingsList = new ArrayList<>();
                }
                servingsList.add(newRange);

                servingsCount.put(i, servingsList);
            }
        }

        int kits = 0;

        //Sort all ranges
        for(int key : servingsCount.keySet()) {
            List<Range> servingsCountList = servingsCount.get(key);
            Collections.sort(servingsCountList);
        }

        if (servingsCount.size() == 1) {
            List<Range> servingsCountList = servingsCount.get(0);
            for(Range range : servingsCountList) {
                if (range.lowerBound <= range.higherBound) {
                    kits++;
                }
            }
        } else {
            for(int pack = 0; pack < grams.get(0).length; pack++) {
                for(int key : servingsCount.keySet()) {
                    List<Range> servingsCountList = servingsCount.get(key);

                    if (servingsCountList.isEmpty()) {
                        break;
                    }
                    Range servingsCount1 = servingsCountList.get(0);

                    boolean canMakeKit = false;

                    for(int key2 : servingsCount.keySet()) {
                        if (key != key2) {
                            canMakeKit = false;

                            List<Range> servingsCountList2 = servingsCount.get(key2);

                            for(Range servingsCount2 : servingsCountList2) {
                                if (isInRange(servingsCount1, servingsCount2)) {
                                    canMakeKit = true;
                                    break;
                                }
                            }

                            if (!canMakeKit) {
                                break;
                            }
                        }
                    }

                    if (canMakeKit) {
                        kits++;

                        for(int key2 : servingsCount.keySet()) {
                            List<Range> servingsCountList2 = servingsCount.get(key2);
                            if (servingsCountList2 != null && servingsCountList2.size() > 0) {
                                servingsCountList2.remove(0);
                            }
                        }
                    }
                }
            }
        }

        return kits;
    }

    private static boolean isInRange(Range range1, Range range2) {
        if (range1.higherBound < range2.lowerBound) {
            return false;
        }
        if (range1.lowerBound > range2.higherBound) {
            return false;
        }
        if (range2.higherBound < range1.lowerBound) {
            return false;
        }
        if (range2.lowerBound > range1.higherBound) {
            return false;
        }

        return true;
    }

    private static List<String> readFileInput(String filePath) {
        Path path = Paths.get(filePath);
        List<String> valuesList = new ArrayList<>();

        try {
            List<String> lines = Files.readAllLines(path);

            for (int i = 1; i < lines.size(); i++) {
                valuesList.add(lines.get(i));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return valuesList;
    }

    private static void writeDataOnFile(String file, List<String> data){
        for(String line : data) {
            writeFileOutput(file, line + "\n");
        }
    }

    private static void writeFileOutput(String file, String data){
        byte[] dataBytes = data.getBytes();

        try {
            Files.write(Paths.get(file), dataBytes, StandardOpenOption.CREATE, StandardOpenOption.APPEND);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
