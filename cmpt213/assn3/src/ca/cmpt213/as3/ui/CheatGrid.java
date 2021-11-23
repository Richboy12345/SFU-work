package ca.cmpt213.as3.ui;

/*
 * prints the unhidden cheat grid and its legend as well as the end game grid and its legend
 */

import ca.cmpt213.as3.gameLogic.GridTile;

public final class CheatGrid {
    private final GridTile[][] board;

    public CheatGrid(GridTile[][] board) {
        this.board = board;
    }

    //cheat grid board
    public void printCheatBoard() {
        System.out.println("Game Grid");
        System.out.println("   1  2  3  4  5  6  7  8  9  10");
        int rows = 10;
        for (int i = 0; i < rows; i++) {
            System.out.print((char)(i + 'A') + "  ");
            int cols = 10;
            for (int j = 0; j < cols; j++) {
                System.out.print(board[i][j].getTile()+ " ");
            }
            System.out.println();
        }
    }

    //cheat grid legend
    public void printCheatLegend() {
        System.out.println("Cheat mode legend:");
        System.out.println("@ represents the tile you currently occupy");
        System.out.println("! represents an unvisited Tokimon");
        System.out.println("$ represents a collected Tokimon");
        System.out.println("X represents a Fokimon");
        System.out.println("An empty space represents nothing");
    }

    //end of game grid
    public void printBoard() {
        System.out.println("Game Grid End State");
        System.out.println("   1  2  3  4  5  6  7  8  9  10");
        int rows = 10;
        for (int i = 0; i < rows; i++) {
            System.out.print((char)(i + 'A') + "  ");
            int cols = 10;
            for (int j = 0; j < cols; j++) {
                System.out.print(board[i][j].getTile()+ " ");
            }
            System.out.println();
        }
    }

    public void printLegend() {
        System.out.println("Legend:");
        System.out.println("@ represents the tile you currently occupy");
        System.out.println("$ represents a Tokimon");
        System.out.println("X represents a Fokimon");
        System.out.println("* represents a Fokimon that was removed");
        System.out.println("An empty space represents nothing");
    }
}
