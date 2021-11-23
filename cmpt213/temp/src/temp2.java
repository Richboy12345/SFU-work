package ca.cmpt213.as2;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import java.io.File;
import java.io.FileReader;

import java.util.ArrayList;

public class JSONReader {

    public void readJSON(File file, ArrayList<String[]> tokiCompatabilityInfo) {
        String name, from, to, score, comment, extraComments, leader, id;
        JsonParser parser = new JsonParser();
        JsonObject object = (JsonObject) parser.parse(new FileReader(file));
        JsonArray array = (JsonArray) object.get("team");
        boolean isLead = true;
        extraComments = object.get("extra_comments").getAsString();
        for (JsonObject toki : array) {
            name = toki.get("name").getAsString();
            id = toki.get("id").getAsString();
            if (isLead) {
                from = id;
                leader = id;
                to = "-";
                isLead = false;
            }
            else {
                from = leader;
                to = id;
            }
            JsonObject compatibility = (JsonObject) toki.get("compatibility");
            score = compatibility.get("score").getAsString();
            comment = compatibility.get("comment").getAsString();
            tokiCompatabilityInfo.add(new String[]{"", from, to, score, comment, "", extraComments})
        }
    }

    public File findJsonRecursively (File file, ArrayList<File> jsonFiles) {
        if (file.isDirectory()) {
            File[] newFiles = file.listFiles();
            for (File test : newFiles) {
                File found = findJsonRecursively(test, jsonFiles);
                if (test.getAbsolutePath().toLowerCase().endsWith("json")) {
                    jsonFiles.add(found);
                    return found;
                }
            }
        }
        else {
            if(file.getAbsolutePath().toLowerCase().endsWith("json")){
                return file;
            }
        }
        return null;
    }
}
