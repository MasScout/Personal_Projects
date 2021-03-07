/**
 * Name:        Mason Barrow
 * Class:       CS 321-02
 * Date:        03/07/2021
 * Description: Intentionally creates a null Greeter object as outlined in Programming Assignment 1
 */

public class NullGreeter {
    public static void main (String[] args) {
        Greeter aNullGreeter = new Greeter("Ull Null");
        aNullGreeter = null;
        String greeter = aNullGreeter.sayHello();
        System.out.println(greeter);
    }

    // Error Code:
    // Exception in thread "main" java.lang.NullPointerException
    //     at NullGreeter.main(NullGreeter.java:5)

    // aNullGreeter attempted to use null as an object, so java threw an unchecked runtime exception
    // The :5 indicates the line number where the exception was thrown
}
