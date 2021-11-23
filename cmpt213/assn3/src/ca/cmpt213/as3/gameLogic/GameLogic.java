package ca.cmpt213.as3.gameLogic;

/*
 * contains all the logic needed to run the game
 */

import ca.cmpt213.as3.ui.CheatGrid;
import ca.cmpt213.as3.ui.UserGrid;
import ca.cmpt213.as3.ui.UserInterface;

import java.util.ArrayList;
import java.util.Random;

public class GameLogic {
    private final int numToki;
    private final int numFoki;
    private int posX;
    private int posY;
    private int newTilesVisited = 0;
    private int numCollected = 0;
    private final int tilesPerNewSpell = 10;
    private final boolean cheat;
    private final int[] spells = {1, 1, 1};
    private final int[] maxSpells;
    private final int[] usedSpells = {0, 0, 0};
    private GridTile[][] board;
    private CheatGrid cheatGrid;
    private UserGrid userGrid;
    private ArrayList<GridTile> tokiTiles;
    private ArrayList<GridTile> fokiTiles;
    private GridTile currentPos, previousPos;
    private final UserInterface userInterface = new UserInterface();

    public GameLogic(int numToki, int numFoki, boolean cheat) {
        this.numToki = numToki;
        this.numFoki = numFoki;
        this.cheat = cheat;
        maxSpells = new int[]{100, numToki, numFoki};
    }

    //start the game and acquire variables
    public void start() {

        //print game info
        userInterface.printGameInfo(tilesPerNewSpell);

        //get starting position
        int[] startPos = userInterface.getStartPos();
        setPos(startPos[0] - 1, startPos[1] - 'A');
        newTilesVisited++;

        //acquire gameBoard variables
        GameBoard gameBoard = new GameBoard(numToki, numFoki, posX, posY);
        board = gameBoard.getBoard();
        tokiTiles = gameBoard.getTokiTiles();
        fokiTiles = gameBoard.getFokiTiles();
        cheatGrid = new CheatGrid(board);
        userGrid = new UserGrid(board);

        //print legend for board and allow user to start making moves
        printLegend();
    }

    //user chooses what move to make
    private void userMove() {
        if (newTilesVisited >= tilesPerNewSpell) {
            newTilesVisited -= tilesPerNewSpell;
            addSpell();
        }
        currentPos = board[posY][posX];
        previousPos = currentPos;
        printBoard();
        userInterface.showStats(numToki, numCollected, spells);
        String input = userInterface.userMoveChoice();
        switch (input) {
            case "spell" -> useSpell();
            case "w" -> up();
            case "a" -> left();
            case "s" -> down();
            case "d" -> right();
            case "legend" -> printLegend();
            case "quit" -> gameEnd();
        }
    }

    //print different versions of the game board depending on if cheat was enabled
    private void printBoard() {
        if (cheat) {
            cheatGrid.printCheatBoard();
        } else {
            userGrid.printUserBoard();
        }
    }

    //print different versions of the legend depending on if cheat was enabled
    private void printLegend() {
        if (cheat) {
            cheatGrid.printCheatLegend();
        }
        else {
            userGrid.printLegend();
        }
        userMove();
    }

    //use spell
    private void useSpell() {
        int input = userInterface.userSpellChoice();
        if (input == 1 && spells[0] > 0) {
            spells[0]--;
            usedSpells[0]++;
            teleportUser();
        }
        else if (input == 2 && spells[1] > 0) {
            spells[1]--;
            usedSpells[1]++;
            revealRandomToki();
        }
        else if (input == 3 && spells[2] > 0) {
            spells[2]--;
            usedSpells[2]++;
            killRandomFoki();
        }
        else {
            userInterface.spellCancelled();
            userInterface.allowUserTimeToRead();
            userMove();
        }
    }

    private void addSpell() {
        boolean executed = false;
        Random random = new Random();
        while (!executed) {
            int index = random.nextInt(3);
            if (spells[index] + usedSpells[index] < maxSpells[index]) {
                spells[index]++;
                executed = true;
                userInterface.newSpellMessage();
            }
        }
    }
    //spells

    //teleport user to a position of their choosing
    private void teleportUser() {
        int[] tpTile = userInterface.getTeleportLocation();
        setPos(tpTile[0] - 1, tpTile[1] - 'A');
        tileCheck();
    }

    //reveal a random tokimon
    private void revealRandomToki() {
        boolean executed = false;
        Random random = new Random();
        while (!executed) {
            int index = random.nextInt(numToki);
            if (!(tokiTiles.get(index).isRevealed())) {
                GridTile tile = tokiTiles.get(index);
                tile.reveal();
                tile.setTile("! ");
                executed = true;
            }
        }
        userInterface.revealedTokiMessage();
        userInterface.allowUserTimeToRead();
        userMove();
    }

    //kill a random fokimon
    private void killRandomFoki() {
        boolean executed = false;
        Random random = new Random();
        while (!executed) {
            int index = random.nextInt(numFoki);
            if (!(fokiTiles.get(index).getTile().isBlank())) {
                fokiTiles.get(index).setTile("  ");
                executed = true;
            }
        }
        userInterface.killedFokiMessage();
        userInterface.allowUserTimeToRead();
        userMove();
    }

    //movement methods
    private void up() {
        if (posY > 0) {
            posY--;
            tileCheck();
        } else {
            userInterface.invalidMove();
            userInterface.allowUserTimeToRead();
            userMove();
        }
    }
    private void down() {
        if (posY < 9) {
            posY++;
            tileCheck();
        } else {
            userInterface.invalidMove();
            userInterface.allowUserTimeToRead();
            userMove();
        }
    }
    private void left() {
        if (posX > 0) {
            posX--;
            tileCheck();
        } else {
            userInterface.invalidMove();
            userInterface.allowUserTimeToRead();
            userMove();
        }
    }
    private void right() {
        if (posX < 9) {
            posX++;
            tileCheck();
        } else {
            userInterface.invalidMove();
            userInterface.allowUserTimeToRead();
            userMove();
        }
    }

    //methods set position
    private void setPos(int x, int y) {
        setPosX(x);
        setPosY(y);
    }
    private void setPosX(int x) {
        posX = x;
    }
    private void setPosY(int y) {
        posY = y;
    }

    //check current position
    private void tileCheck() {
        boolean gameFinished = false;
        boolean newTile = false;
        currentPos = board[posY][posX];
        previousPos.setTile(previousPos.getTile().charAt(1) + " ");
        String tileValue = currentPos.getTile().trim();
        if (tileValue.equals("X")) {
            currentPos.setTile("@X");
            currentPos.visit();
            newTile = true;
            userInterface.encounterFoki();
            gameFinished = true;
        }
        else if (tileValue.equals("$") || tileValue.equals("!")) {
            currentPos.setTile("@$");
            if (!(currentPos.isVisited())) {
                currentPos.visit();
                newTile = true;
                numCollected++;
                userInterface.encounterToki();
                printBoard();
                userInterface.allowUserTimeToRead();
            }
            if (numCollected == numToki) {
                gameFinished = true;
                userInterface.allTokiFound();
            }
        }
        else  {
            currentPos.setTile("@ ");
            if (!(currentPos.isVisited())) {
                currentPos.visit();
                newTile = true;
            }
        }
        if (newTile) {
            newTilesVisited++;
        }
        if (!gameFinished) {
            userMove();
        }
        else {
            gameEnd();
        }
    }

    //reset any spell-edited tiles before game ends and print the board
    private void gameEnd() {
        for (GridTile tile : tokiTiles) {
            tile.resetTokiTiles();
        }
        for (GridTile tile : fokiTiles) {
            tile.resetFokiTiles();
        }
        cheatGrid.printBoard();
        cheatGrid.printLegend();
    }

}
