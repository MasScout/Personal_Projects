public class Changer {
    
    public void changeField(TestObj testObj) {
        testObj.setTestField(28);
    }
    
    public void changeObject(TestObj testObj) {
        testObj = new TestObj(83);
    }   
}