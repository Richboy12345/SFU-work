package ca.cmpt213.as2;

/*
 * This class contains methods for reading JSON files and finding JSON files recursively
 */

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;

public class JSONReader {

    public void readJson(File file, ArrayList<String[]> tokiInfo) throws FileNotFoundException{

        //variable declaration
        String team, id, to, score, comment;

        //create parser and parse the objects to JSON array
        JsonParser parser = new JsonParser();
        JsonObject object = (JsonObject) parser.parse(new FileReader(file));
        JsonArray array = (JsonArray) object.get("team");

        //ensure initialization of from, read the extra comments, and initialize a boolean to track the first tokimon in the file
        String from = "";
        String extra_comments = object.get("extra_comments").getAsString();
        boolean isLead = true;

        //read each tokimon and add the info to the arraylist of string arrays containing the info for each tokimon
        for (Object obj : array) {
            JsonObject toki = (JsonObject) obj;
            id = toki.get("id").getAsString().trim();
            team = getTeam(id);
            if (isLead) {
                from = id;
                to = "-";
                isLead = false;
            }
            else {
                to = id;
                extra_comments="";
            }
            JsonObject compatibility = (JsonObject) toki.get("compatibility");
            score = compatibility.get("score").getAsString();
            double scoreAsDouble = Double.parseDouble(score);
            if (scoreAsDouble < 0) {
                System.out.println("Error: Compatibility Score is less than 0. Error file is: " + file);
                System.exit(-1);
            }
            comment = compatibility.get("comment").getAsString();
            tokiInfo.add(new String[] {team, from, to, "", score, comment, "", extra_comments});
        }
    }

    public String getTeam(String id) {
        int start = id.indexOf("-");
        String trim = id.substring(start + 1);
        //System.out.println(trim);
        String team = trim.substring(0, trim.indexOf("-"));
        //System.out.println(team);
        return team;

    }

    //find all JSON files in a directory recursively
    public void findJsonRecursively (File file, ArrayList<File> JSONFiles) {

        //base case, check file to see if it is JSON, and add to file list if it is
        if (!file.isDirectory()) {
            if(file.getAbsolutePath().toLowerCase().endsWith("json")) {
                JSONFiles.add(file);
            }
        }

        //else it is a directory, in which case, store all the files in the directory to a list
        else {
            File[] filesInDir = file.listFiles();
            assert filesInDir != null;
            //recursively find all JSON files
            for (File next : filesInDir) {
                findJsonRecursively(next, JSONFiles);
            }
        }
    }
}
