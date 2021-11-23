/*
 * Tokimon main file by Richard Zhang, 301402349
 *
 * Main class
 * contains main function, as well as other functions for editing the tokimon arraylist
 *
 */

//main class, initiates a game
public class Main {
    public static void main(String[] args) {
        System.out.println("***********************************************\n" +
                "* Tokimon Tracker by Richard Zhang, 301402349 *\n" +
                "***********************************************");
        Game newGame = new Game();
        newGame.displayMainMenu();
    }
}
