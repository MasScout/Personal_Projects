/**
 * Name:        Mason Barrow
 * Class:       CS 321-02
 * Date:        03/07/2021
 * Description: Tests the Greeter class as outlined in Programming Assignment 1
 */

import java.util.Scanner;

public class GreeterTester {
    public static void main (String[] args) {
        String greeting;
        
        Greeter firstGreeter = new Greeter("First Name");
        Greeter secondGreeter = new Greeter("Second Name");
        greeting = firstGreeter.sayHello();
        System.out.print(greeting + "\t");
        greeting = secondGreeter.sayHello();
        System.out.println(greeting);

        firstGreeter.setName("New First Name");
        secondGreeter.setName("New Second Name");
        greeting = firstGreeter.sayHello();
        System.out.print(greeting + "\t");
        greeting = secondGreeter.sayHello();
        System.out.println(greeting);
        
        firstGreeter.swapNames(secondGreeter);
        greeting = firstGreeter.sayHello();
        System.out.print(greeting + "\t");
        greeting = secondGreeter.sayHello();
        System.out.println(greeting);



        Greeter randomGreeter = Greeter.getRandomInstance();
        greeting = randomGreeter.sayHello();
        System.out.println(greeting);



        Greeter same1 = new Greeter("TheSame");
        Greeter same2 = same1;
        same1.setName("New Same");
        greeting = same2.sayHello();
        System.out.println(greeting);



        Scanner nameScanner = new Scanner(System.in);
        System.out.print("What is your name? ");
        String inputName = nameScanner.nextLine();
        nameScanner.close();
        Greeter userGreeter = new Greeter(inputName);
        greeting = userGreeter.sayHello();
        System.out.println(greeting);
    }
}
