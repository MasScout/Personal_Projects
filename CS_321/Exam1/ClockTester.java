public class ClockTester {
    
    public static void main(String[] args) {
        Clock firstClock = new Clock();
        Clock secondClock = new Clock();
        Clock thirdClock = new Clock();
        
        secondClock.setHours(11);
        secondClock.setMinutes(57);
        secondClock.setAmPm(Clock.PM);

        thirdClock.setHours(8);
        thirdClock.setMinutes(15);
        thirdClock.setAmPm(Clock.AM);

        firstClock.getTime();
        secondClock.getTime();
        thirdClock.getTime();
    }
}
