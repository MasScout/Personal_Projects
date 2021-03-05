public class HogwartsHouse {
    public HogwartsHouse() {
        name = null;
        housePoints = 0;
    }

    public HogwartsHouse(String name, int housePoints) {
        this.name = name;
        this.housePoints = housePoints;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void addPoints(int newPoints) {
        housePoints += newPoints;
    }

    public void movePointsTo(HogwartsHouse house) {
        house.housePoints += 10;
        this.housePoints -= 10;
    }
 
    public void stealAllPoints(int housePoints) {
        this.housePoints += housePoints;
        housePoints = 0;
    }

    public int getPoints() {
        return housePoints;
    }

    public String getHouseInfo() {
        return name + ": " + housePoints;
    }

    private String name;
    private int housePoints;
}
