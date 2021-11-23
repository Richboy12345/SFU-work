package ca.cmpt213.as2;

/*
 * this class writes to a CSV file
 */

import com.opencsv.CSVWriter;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class CSVGenerator {

    public void outputCsv (File file, ArrayList<String[]> tokiInfo) throws IOException {

        //initialize file writer
        FileWriter outputFile = new FileWriter(file);
        CSVWriter writer = new CSVWriter(outputFile);

        //header row
        String[] header = {"Team#", "From Toki", "To Toki", "","Score","Comment","","Extra Comment"};
        writer.writeNext(header);

        //write all teams to CSV file
        for(String[] s: tokiInfo){
            writer.writeNext(s);
        }
        writer.close();

    }
}
