package ca.cmpt213.as2;

import com.opencsv.CSVWriter;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class CSVGenerator {

    public void outputCsv (File file, ArrayList<String[]> tokiInfo) throws IOException {

        FileWriter CSVFile = new FileWriter(file);
        CSVWriter writer = new CSVWriter(CSVFile);
        writer.writeNext("Team#", "From Toki", "To Toki","","Score","Comment","","Extra");
        String[] teamNumber={"Team1"};
        writer.writeNext(teamNumber);
        for(String[] s: tokiInfo){
            writer.writeNext(s);
        }
        writer.close();
    }
}
