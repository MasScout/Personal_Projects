/**
 * Name:        Mason Barrow
 * Class:       CS 321-02
 * Date:        03/07/2021
 * Description: A class for saying Hello, [Name]! as defined by Programming Assignment 1
 */

import java.util.Random;

public class Greeter {
    
    /**
     * Default Constructor
     * @param aName
     */
    public Greeter (String aName) {
        name = aName;
    }

    /**
     * Method to create a string that says Hello, [the object's name]!
     * @return
     */
    public String sayHello() {
        return "Hello, " + name + "!";
    }
    /**
     * Setter Method for the object's name
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Method to swap names with another object
     * @param other
     */
    public void swapNames(Greeter other) {
        String otherName = other.name;
        other.name = this.name;
        this.name = otherName;
    }

    /**
     * Factory Method to get a random instance of Greeter, either Venus or Mars
     * @return
     */
    public static Greeter getRandomInstance() {
        if (generator.nextBoolean()) {
            return venusGreeter;
        }
        else {
            return marsGreeter;
        }
    }

    private String name;

    private static Random generator = new Random();

    private static Greeter venusGreeter = new Greeter("Venus");
    private static Greeter marsGreeter = new Greeter("Mars");

}