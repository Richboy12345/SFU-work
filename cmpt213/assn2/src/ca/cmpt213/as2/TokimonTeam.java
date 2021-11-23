package ca.cmpt213.as2;

/*
 * This class sorts the tokimon by team and verifies the tokimon in the teams
 */

import java.util.ArrayList;

public class TokimonTeam {

    //sort tokimon by team
    public ArrayList<String[]> sortByTeams(ArrayList<String[]> tokiInfo) {
        ArrayList<String[]> sorted = new ArrayList<String[]>();
        ArrayList<String> teams = new ArrayList<String>();
        int teamsCount = 0;

        //find all teams
        for (String[] toki : tokiInfo) {
            if (!teams.contains(toki[0])) {
                teams.add(toki[0]);
                teamsCount++;
            }
        }

        //sort into teams
        for (int i = 0; i < teamsCount; i++) {
            sorted.add(new String[] {"Team" + (i + 1), ""});
            ArrayList<String[]> tempTeams = new ArrayList<String[]>();
            String team = teams.get(i);
            for (String[] toki : tokiInfo) {
                if (toki[0].equals(team)) {
                    toki[0] = "";
                    sorted.add(toki);
                    tempTeams.add(toki);
                }
            }
            verifyTeam(tempTeams, team);
        }
        return sorted;
    }

    //verify that both to and from contain the same ids
    public void verifyTeam(ArrayList<String[]> team, String teamTag) {
        //get list of ids of both to and from tokimon
        ArrayList<String> from = verifyFrom(team, teamTag);
        ArrayList<String> to = verifyTo(team, teamTag);

        //verify that both lists of ids contain the same ids
        for (String id : from) {
            if (!to.contains(id)) {
                System.out.println("Error: There may be a tokimon that does not belong to the team in team " + teamTag);
                System.exit(-1);
            }
        }
    }

    //verify that all from tokimon appear in equal amounts and send the list of ids back to verifyTeam
    public ArrayList<String> verifyFrom(ArrayList<String[]> team, String teamTag) {
        //one array to store ids to be returned and one array to store their counts
        ArrayList<String> ids = new ArrayList<String>();
        ArrayList<Integer> count = new ArrayList<Integer>();
        //get all ids in from and their counts
        for (String[] toki : team) {
            String id = toki[1];
            if (!ids.contains(id)) {
                ids.add(id);
                count.add(1);
            }
            else {
                int index = ids.indexOf(id);
                count.set(index, count.get(index) + 1);
            }

        }
        //verify all ids appear the same amount
        int temp = count.get(0);
        for (Integer i : count) {
            if (i != temp) {
                System.out.println("Error: There may be a tokimon that does not belong to the team in team " + teamTag);
                System.exit(-1);
            }
        }
        return ids;
    }

    //verify that all to tokimon appear in equal amounts and send the list of ids back to verifyTeam
    public ArrayList<String> verifyTo(ArrayList<String[]> team, String teamTag) {
        //one array to store ids to be returned and one array to store their counts
        ArrayList<String> ids = new ArrayList<String>();
        ArrayList<Integer> count = new ArrayList<Integer>();
        //get all ids and their counts
        for (String[] toki : team) {
            String id = toki[2];
            if (id.equals("-")) {
                id = toki[1];
            }
            if (!ids.contains(id)) {
                ids.add(id);
                count.add(1);
            }
            else {
                int index = ids.indexOf(id);
                count.set(index, count.get(index) + 1);
            }

        }
        //verify all ids appear the same amount
        int temp = count.get(0);
        for (Integer i : count) {
            if (i != temp) {
                System.out.println("Error: There may be a tokimon that does not belong to the team in team " + teamTag);
                System.exit(-1);
            }
        }
        return ids;
    }
}
