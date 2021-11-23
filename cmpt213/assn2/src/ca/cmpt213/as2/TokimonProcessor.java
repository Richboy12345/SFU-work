package ca.cmpt213.as2;

/*
 * Main method for processing Tokimon Compatibility JSON files
 * This file does the following
 * Verifies that all arguments are valid
 * Verifies input and output directories
 * Using other classes and their functions, reads JSON files and outputs the results to a CSV file
 */

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class TokimonProcessor {

    public static void main(String[] args) throws IOException {

        //verifies that 2 arguments are passed through
        if(args.length != 2){
            System.out.println("Error: The main class accepts only two arguments: \n" +
                    "    1: The path to the directory containing the input .JSON files \n" +
                    "    2: The path to the output directory where the generated .csv will be placed.");
            System.exit(-1);
        }

        //variable initialization for file directories
        File jsonInputDir = new File(args[0]);
        File csvOutputDir = new File(args[1]);

        //verify both directories exist
        if (!jsonInputDir.isDirectory()){
            System.out.println("Error: Input directory does not exist.");
            System.exit(-1);
        }
        if (!csvOutputDir.isDirectory()){
            System.out.println("Error: Output directory does not exist.");
            System.exit(-1);
        }

        //Arraylist of all JSON files
        ArrayList<File> jsonFiles = new ArrayList<File>();

        //call on JSONReader to find all JSON files in the input directory
        JSONReader reader = new JSONReader();
        reader.findJsonRecursively(jsonInputDir, jsonFiles);

        //checks to see if files were actually found
        if (jsonFiles.size() == 0) {
            System.out.println("Error: No Json files were found.");
            System.exit(-1);
        }

        //Arraylist of all the info for the tokimon
        ArrayList<String[]> tokiInfo = new ArrayList<String[]>();

        //reads each JSON file and then converts it into a string
        for (File file : jsonFiles) {
            //System.out.println(file.getName());
            reader.readJson(file, tokiInfo);
        }

        //call on team maker to sort teams
        TokimonTeam makeTeam = new TokimonTeam();
        ArrayList<String[]> sorted = makeTeam.sortByTeams(tokiInfo);

        //initialize the CSV file
        File csvFile = new File(csvOutputDir + "/team_info.csv");

        //call on CSVGenerator to write to the CSV file
        CSVGenerator generator = new CSVGenerator();
        generator.outputCsv(csvFile, sorted);
    }


}
