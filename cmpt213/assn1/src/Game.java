/*
 * Game Class by Richard Zhang
 *
 * contains the main menu and all functions for modifying tokimon objects and the list of tokimon
 *
 */

import java.util.ArrayList;
import java.util.Scanner;

public class Game {
    //variable declarations
    Scanner scan = new Scanner(System.in);
    ArrayList<Tokimon> tokimons = new ArrayList<Tokimon>();

    //displays the main menu and allows the user to pick an operation
    public void displayMainMenu() {
        System.out.print("*************\n" +
                "* Main Menu*\n" +
                "*************\n" +
                "1. List Tokimons\n" +
                "2. Add a new Tokimon\n" +
                "3. Remove a Tokimon\n" +
                "4. Change Tokimon strength\n" +
                "5. DEBUG: Dump objects toString\n" +
                "6. Exit\n" +
                "Which operation should be performed? ");
        //asks user for choice
        int choice = scan.nextInt();
        while (choice < 1 || 6 < choice) {
            System.out.print("User entry was invalid, please try again: ");
            choice = scan.nextInt();
        }
        scan.nextLine();
        //executes operation based on user choice
        switch(choice) {
            case 1:
                displayAllTokis();
                System.out.print("Press enter to return to the main menu...");
                scan.nextLine();
                displayMainMenu();
                break;
            case 2:
                addNewToki();
                break;
            case 3:
                deleteToki();
                break;
            case 4:
                alterToki();
                break;
            case 5:
                debug();
                break;
            case 6:
                return;
        }
    }

    //displays a list of all tokimon
    public void displayAllTokis() {
        System.out.println("*********************\n" +
                "* List of Tokimons: *\n" +
                "*********************");
        for (int i = 0; i < tokimons.size(); i++) {
            System.out.println((i + 1) + ". " + tokimons.get(i).getName() + "; Type: " + tokimons.get(i).getType() + ", Size: " + tokimons.get(i).getSize() + "m, Strength: " + tokimons.get(i).getStrength() + ".");
        }
    }

    //add a new tokimon to the database
    public void addNewToki() {
        System.out.println("Adding new Tokimon to the database.");
        System.out.print("Enter its name: ");
        String name = scan.nextLine();
        System.out.print("Enter its type: ");
        String type = scan.nextLine();
        System.out.print("Enter its size: ");
        double size = scan.nextDouble();
        scan.nextLine();
        Tokimon toki = new Tokimon(name, type, size);
        tokimons.add(toki);
        displayMainMenu();
    }

    //remove a tokimon from the database
    public void deleteToki() {
        displayAllTokis();
        System.out.print("Which entry should be removed? Enter 0 to cancel: ");
        int choice = scan.nextInt();
        while (choice < 0 || tokimons.size() < choice) {
            System.out.print("User entry was invalid, please try again: ");
            choice = scan.nextInt();
        }
        scan.nextLine();
        if (choice == 0) {
            System.out.println("Operation cancelled, returning to menu.");
        }
        else {
            String name = tokimons.get(choice - 1).getName();
            tokimons.remove(choice - 1);
            System.out.println(name + "was removed from the list, returning to menu.");
        }
        displayMainMenu();
    }

    //alter the strength of a tokimon
    public void alterToki() {
        displayAllTokis();
        System.out.print("Which entry should be changed? Enter 0 to cancel: ");
        int choice = scan.nextInt();
        while (choice < 0 || tokimons.size() < choice) {
            System.out.print("User entry was invalid, please try again: ");
            choice = scan.nextInt();
        }
        scan.nextLine();
        if (choice == 0) {
            System.out.println("Operation cancelled, returning to menu.");
        }
        else {
            String name = tokimons.get(choice - 1).getName();
            int strength = tokimons.get(choice - 1).getStrength();
            System.out.print(name + " currently has a strength of " + strength + ". By how much should it change? ");
            int change = scan.nextInt();
            change += strength;
            while (change < 0 || change > 100) {
                System.out.print("User entry was invalid, strength value must be between 0 and 100, " +
                        "requested change would make it " + change + ", please try again: ");
                change = scan.nextInt();
                change += strength;
            }
            scan.nextLine();
            tokimons.get(choice - 1).setStrength(change);
            System.out.println(name + " had their strength changed from " + strength + " to " +
                    change + ", returning to menu.");
        }
        displayMainMenu();
    }

    //print out all tokimon and their attributes
    public void debug() {
        for (Tokimon toki: tokimons) {
            System.out.println(toki.toString());
        }
        System.out.print("Press enter to return to the main menu...");
        scan.nextLine();
        displayMainMenu();
    }
}
