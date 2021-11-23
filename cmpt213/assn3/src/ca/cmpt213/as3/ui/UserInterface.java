package ca.cmpt213.as3.ui;

/*
 * handles all input and output besides the printing of the game board
 */

import java.util.Scanner;

public class UserInterface {
    Scanner scan = new Scanner(System.in);

    //if too many args are entered
    public void invalidArgsLength() {
        System.out.println("Error: More than 3 arguments entered.");
    }

    //if too few toki in args
    public void invalidTokiNum() {
        System.out.println("The minimum number of Tokimons is 5, using default of 10 instead");
    }

    //if too few foki in args
    public void invalidFokiNum() {
        System.out.println("The minimum number of Fokimons is 5, using default of 5 instead");
    }

    //if too many foki in args
    public void tooManyFoki(int numFoki) {
        System.out.println("The maximum number of Fokimons is 20, using that instead of " + numFoki);
    }

    //if too many units total
    public void tooManyToki(int numToki) {
        System.out.println("There are not enough spaces for all the Tokimons and Fokimons. Reducing the number of Tokimon to " + numToki);
    }

    public void printGameInfo(int tilesPerNewSpell) {
        System.out.println("Welcome to Tokimon Hunt.\n" +
                           "The goal of this game is to find all the Tokimon without\n" +
                           "running into one of the evil Fokimon. Running into a Fokimon\n" +
                           "will cause you to lose the game. You can move around the\n" +
                           "board using the wasd keys and you also have access to 3\n" +
                           "spells. You will gain a random spell every " + tilesPerNewSpell + " new\n" +
                           "tiles you visit.");
    }

    //asks the user if they want to play again
    public boolean playAgain() {
        boolean playAgain = true;
        //asks user if they would like to play again with the same settings
        System.out.println("Would you like to play again? (y or n)");
        char again = scan.next().charAt(0);
        scan.nextLine();
        if (again >= 'a') {
            again = (char) (again - 32);
        }
        while (again != 'Y' && again != 'N') {
            System.out.println("y or n please");
            again = scan.next().charAt(0);
            scan.nextLine();
            if (again >= 'a') {
                again = (char) (again - 32);
            }
        }
        if (again == 'N') {
            playAgain = false;
        }
        return playAgain;
    }

    //get starting position of player
    public int[] getStartPos() {
        System.out.println("Please enter a starting row (A to J): ");
        char startRow = scan.next().charAt(0);
        scan.nextLine();
        if (startRow >= 'a') {
            startRow = (char) (startRow - 32);
        }
        while (!(startRow >= 'A' && startRow <= 'J')) {
            System.out.println("Please enter a valid row");
            startRow = scan.next().charAt(0);
            scan.nextLine();
            if (startRow >= 'a') {
                startRow = (char) (startRow - 32);
            }
        }
        System.out.println("Please enter a starting column (1 to 10): ");
        int startCol = scan.nextInt();
        scan.nextLine();
        while (!(startCol >= 1 && startCol <= 10)) {
            System.out.println("Please enter a valid column");
            startCol = scan.nextInt();
            scan.nextLine();
        }
        return new int[]{startCol, startRow};
    }

    //allows user to take time to read before making next move
    public void allowUserTimeToRead() {
        System.out.println("Press enter to continue");
        scan.nextLine();
    }

    //print tokimon collected
    public void showStats(int numToki, int numCollected, int[] spells) {
        System.out.println("You have found " + numCollected + " Tokimon(s). There are " + (numToki - numCollected) + " remaining");
        System.out.println("Your spells:");
        printSpells(spells);
    }

    //print spells remaining
    private void printSpells(int[] spells) {
        String[] spellDescriptions = {"Jump the player to another grid location",
                "Randomly reveal the location of one of the Tokimons",
                "Randomly kill off one of the Fokimons"};
        for (int i = 0; i < spells.length; i++) {
            System.out.println(spellDescriptions[i] + ": " + spells[i] + " remaining use(s).");
        }
    }

    //get the input move from user
    public String userMoveChoice() {
        System.out.println("What would you like to do? " +
                "(enter w, a, s, or d for movement, " +
                "enter spell to use a spell, " +
                "enter legend to view the legend," +
                "or quit to quit the game)");
        String input = scan.nextLine().toLowerCase().trim();
        if (!validateInput(input)) {
            System.out.println("Invalid choice, please try again");
            input = scan.nextLine().toLowerCase().trim();
        }
        return input;
    }

    //validate user input
    private boolean validateInput(String input) {
        return input.equals("w") || input.equals("a") || input.equals("s") || input.equals("d")
                || input.equals("spell") || input.equals("legend") || input.equals("quit");
    }

    //get spell choice from user
    public int userSpellChoice() {
        System.out.println("""
                Please select a spell:\s
                   1. Jump the player to another grid location
                   2. Randomly reveal the location of one of the Tokimons
                   3. Randomly kill off one of the Fokimons
                   Type any other number or the number of a used spell to exit""");
        int input = scan.nextInt();
        scan.nextLine();
        return input;
    }

    //gain spell message
    public void newSpellMessage() {
        System.out.println("You got another charge of a random spell!");
    }

    //spell use cancelled message
    public void spellCancelled() {
        System.out.println("Spell usage cancelled");
    }

    //get teleport location from user
    public int[] getTeleportLocation() {
        System.out.println("Teleporting User...");
        System.out.println("Please enter a row (A to J): ");
        char tpRow = scan.next().charAt(0);
        scan.nextLine();
        if (tpRow >= 'a') {
            tpRow = (char) (tpRow - 32);
        }
        while (!(tpRow >= 'A' && tpRow <= 'J')) {
            System.out.println("Please enter a valid row");
            tpRow = scan.next().charAt(0);
            scan.nextLine();
            if (tpRow >= 'a') {
                tpRow = (char) (tpRow - 32);
            }
        }
        System.out.println("Please enter a column (1 to 10): ");
        int tpCol = scan.nextInt();
        scan.nextLine();
        while (!(tpCol >= 1 && tpCol <= 10)) {
            System.out.println("Please enter a valid column");
            tpCol = scan.nextInt();
            scan.nextLine();
        }
        return new int[]{tpCol, tpRow};
    }

    //revealed toki message
    public void revealedTokiMessage() {
        System.out.println("Revealed Tokimon will be marked by an exclamation mark (!)");
    }

    //killed foki message
    public void killedFokiMessage() {
        System.out.println("A Fokimon has been randomly removed from the board");
    }

    //invalid movement (wasd) message
    public void invalidMove() {
        System.out.println("Cannot Move There");
    }

    //found foki message
    public void encounterFoki() {
        System.out.println("You ran into a Fokimon. Game Over");
    }

    //found toki message
    public void encounterToki() {
        System.out.println("Congrats! You found a Tokimon");
    }

    //found all toki message
    public void allTokiFound() {
        System.out.println("Congratulations! You found all the Tokimon! You win!");
    }
}
