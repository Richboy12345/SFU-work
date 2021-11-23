package ca.cmpt213.as3.ui;

/*
 * prints the hidden user grid and its legend
 */

import ca.cmpt213.as3.gameLogic.GridTile;

public final class UserGrid {
    private final GridTile[][] board;

    public UserGrid(GridTile[][] board) {
        this.board = board;
    }

    //print hidden board for user
    public void printUserBoard() {
        System.out.println("Game Grid");
        System.out.println("   1  2  3  4  5  6  7  8  9  10");
        int rows = 10;
        for (int i = 0; i < rows; i++) {
            System.out.print((char)(i + 'A') + "  ");
            int cols = 10;
            for (int j = 0; j < cols; j++) {
                GridTile tile = board[i][j];
                if (tile.isRevealed()) {
                    System.out.print(tile.getTile() + " ");
                }
                else {
                    System.out.print("?  ");
                }
            }
            System.out.println();
        }
    }

    //print legend for user
    public void printLegend() {
        System.out.println("Legend:");
        System.out.println("@ represents the tile you currently occupy");
        System.out.println("? represents an unvisited and unrevealed tile");
        System.out.println("! represents an unvisited but revealed Tokimon");
        System.out.println("$ represents a collected Tokimon");
        System.out.println("X represents a Fokimon");
        System.out.println("An empty space represents a spot that has been visited but contains nothing");
    }
}
