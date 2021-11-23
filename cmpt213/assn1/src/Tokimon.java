/*
 * Tokimon class file by Richard Zhang
 *
 * Contains a constructor for a Tokimon object, as well as getters, setters and an override for the toString function
 */

public class Tokimon {

    //Tokimon attributes variable declarations
    private String name;
    private String type;
    private double size;
    private int strength;

    //Tokimon object constructor
    Tokimon(String name, String type, double size){
        this.name = name;
        this.type = type;
        this.size = size;
        this.strength = 0;
    }

    //Tokimon to string override for debug purposes
    public String toString() {
        return "Tokimon{ Name: " + this.name +
                "; Type: " + this.type +
                ", Size: " + this.size +
                ", Strength: " + this.strength + "}";
    }

    //getters and setters for all attributes
    public String getName() {
        return this.name;
    }
    public String getType() {
        return this.type;
    }
    public double getSize() {
        return this.size;
    }
    public int getStrength() {
        return this.strength;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setType(String type) {
        this.type = type;
    }
    public void setSize(double size) {
        this.size = size;
    }
    public void setStrength(int strength) {
        this.strength = strength;
    }
}
