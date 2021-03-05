public class Clock {
    private int hours;
    private int minutes;

    public static final int AM = 1;
    public static final int PM = 2;

    private String am_pm;

    public String getTime() {
        String hourString = String.valueOf(hours);
        String minuteString;
        if (minutes < 10) {
            minuteString = "0" + String.valueOf(minutes);
        }
        else {
            minuteString = String.valueOf(minutes);
        }
        String currentTime = hourString.concat(":").concat(minuteString).concat(" ").concat(am_pm);
        System.out.println(currentTime);
        return currentTime;
    }

    public void setHours(int newHour) {
        hours = newHour;
    }

    public void setMinutes(int newMinute) {
        minutes = newMinute;
    }

    public void setAmPm(int ampm) {
        am_pm = (ampm == 1) ? "a.m." : "p.m.";
    }

    public int getHours() {
        return hours;
    }

    public int getMinutes() {
        return minutes;
    }

    public String getAmPm() {
        return am_pm;
    }

    public Clock() {
        hours = 6;
        minutes = 0;
        setAmPm(AM);
    }
}