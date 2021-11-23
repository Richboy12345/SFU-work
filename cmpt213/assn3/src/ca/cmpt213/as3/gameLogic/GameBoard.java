package ca.cmpt213.as3.gameLogic;

/*
 * generates the game board as a 2d array of tiles
 */

import java.util.ArrayList;
import java.util.Random;

public final class GameBoard {
    private final int rows = 10;
    private final int cols = 10;
    private final ArrayList<GridTile> tokiTiles = new ArrayList<>();
    private final ArrayList<GridTile> fokiTiles = new ArrayList<>();
    private final GridTile[][] board = new GridTile[rows][cols];

    public GameBoard(int numToki, int numFoki, int initialX, int initialY) {
        Random random = new Random();

        //create each tile on board
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = new GridTile();
            }
        }

        //set initial position of player
        board[initialY][initialX].setTile("@ ");
        board[initialY][initialX].visit();

        //place Tokimon randomly
        for (int i = 0; i < numToki;) {
            int row = random.nextInt(rows);
            int col = random.nextInt(cols);
            if (board[row][col].getTile().isBlank()) {
                board[row][col].setTile("$ ");
                tokiTiles.add(board[row][col]);
                i++;
            }
        }

        //place Fokimon randomly
        for (int i = 0; i < numFoki;) {
            int row = random.nextInt(rows);
            int col = random.nextInt(cols);
            if (board[row][col].getTile().isBlank()) {
                board[row][col].setTile("X ");
                fokiTiles.add(board[row][col]);
                i++;
            }
        }
    }

    //get the list of tiles containing tokimon and fokimon as well as the board itself
    public ArrayList<GridTile> getFokiTiles() {
        return fokiTiles;
    }
    public ArrayList<GridTile> getTokiTiles() {
        return tokiTiles;
    }
    public GridTile[][] getBoard() {
        return board;
    }
}
