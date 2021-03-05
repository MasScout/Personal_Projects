public class TestObj {
    
    public TestObj(int testField) {
        this.testField = testField;
    }
    
    public void setTestField(int newVal) {
        testField = newVal;
    }
    
    public int getTestField() {
        return testField;
    }
    
    private int testField = 0;
    
}