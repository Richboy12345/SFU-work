package ca.cmpt213.as2;

import java.io.File;

public class TokimonProcessor {

    public static void main(String[] args) {
        if(args.length != 2){
            System.out.println("Error: The main class accepts only two arguments: \n" +
                    "    1: The path to the directory containing the input .JSON files \n" +
                    "    2: The path to the output directory where the generated .csv will be placed.");
            System.exit(0);
        }

        File jsonInputDir = new File(args[0]);
        File csvOutputDir = new File(args[1]);

        if (!jsonInputDir.isDirectory()){
            System.out.println("Error: Input directory does not exist.");
            System.exit(0);
        }
        if (!csvOutputDir.isDirectory()){
            System.out.println("Error: Output directory does not exist.");
            System.exit(0);
        }

        File csvFile = new File (csvOutputDir + "team_info.csv")
    }


}
