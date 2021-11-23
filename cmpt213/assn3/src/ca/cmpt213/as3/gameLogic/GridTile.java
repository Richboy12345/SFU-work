package ca.cmpt213.as3.gameLogic;

/*
 * class for the individual tiles of the game board
 */

public class GridTile {
    private String tile;
    private boolean visited;
    private boolean revealed;

    //constructor
    public GridTile() {
        tile = "  ";
        visited = false;
        revealed = false;
    }

    //set the value of the tile
    public void setTile(String value) {
        tile = value;
    }

    //get the value of the tile
    public String getTile() {
        return tile;
    }

    //reveal tile
    public void reveal() {
        revealed = true;
    }

    //visit and reveal tile
    public void visit() {
        reveal();
        visited = true;
    }

    //get whether a tile has been visited
    public boolean isVisited() {
        return visited;
    }

    //get whether a tile has been revealed
    public boolean isRevealed() {
        return revealed;
    }

    //reset all revealed tokimon tiles
    public void resetTokiTiles() {
        if (!visited) {
            tile = "$ ";
        }
    }

    //reset all killed fokimon tiles
    public void resetFokiTiles() {
        if (tile.isBlank()) {
            tile = "* ";
        }
    }
}
