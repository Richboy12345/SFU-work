package ca.cmpt213.as3.main;

/*
 * contains main method
 * used to validate command line arguments
 */

import ca.cmpt213.as3.gameLogic.GameLogic;
import ca.cmpt213.as3.ui.UserInterface;

public class TokimonFinder {

    public static void main(String[] args) {

        //variable declaration
        UserInterface userInterface = new UserInterface();
        int numToki = 10;
        int numFoki = 5;
        boolean cheat = false;
        int numArgs = args.length;

        //validate number of args
        if(numArgs > 3){
            userInterface.invalidArgsLength();
            System.exit(-1);
        }

        //getting values from args
        if (numArgs > 0) {
            if (args[0].matches("--numToki=\\d+")) {
                args[0] = args[0].replace("--numToki=", "");
                numToki = Integer.parseInt(args[0]);
            }
        }
        if (numArgs > 1) {
            if (args[1].matches("--numFoki=\\d+")) {
                args[1] = args[1].replace("--numFoki=", "");
                numFoki = Integer.parseInt(args[1]);
            }
        }
        if (numArgs > 2) {
            if (args[2].matches("--cheat")) {
                cheat = true;
            }
        }

        //use default if args values are invalid
        if (numToki < 5) {
            userInterface.invalidTokiNum();
            numToki = 10;
        }
        if (numFoki < 5) {
            userInterface.invalidFokiNum();
            numFoki = 5;
        }
        //cap number of fokimons to increase enjoyability of the game
        if (numFoki > 20) {
            userInterface.tooManyFoki(numFoki);
            numFoki = 20;
        }
        //cap number of tokimons and fokimons to the number of board spaces minus 1
        if (numToki + numFoki > 99) {
            numToki = 99 - numFoki;
            userInterface.tooManyToki(numToki);
        }

        //added for replayability
        boolean playAgain = true;
        while (playAgain) {

            //start a game
            GameLogic game = new GameLogic(numToki, numFoki, cheat);
            game.start();

            //would user like to play again
            playAgain = userInterface.playAgain();
        }
    }
}