public class TestChanger {

    public static void main(String[] args) {
        Changer c = new Changer();
        TestObj t = new TestObj(10);

        System.out.println(t.getTestField());             


        
        c.changeObject(t);
        System.out.println(t.getTestField());             


        
        c.changeField(t);
        System.out.println(t.getTestField());             


    }
}
