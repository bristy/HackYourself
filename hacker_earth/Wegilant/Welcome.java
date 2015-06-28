public class Welcome {
    String title;
    int value;
    public Welcome() {
    title += " Planet";
    }
    public void Welcome() {
    System.out.println(title + " " + value);
    }
    public Welcome(int value) {
    this.value = value;
    title = "Welcome";
    Welcome();
    }
    public static void main(String args[]) {
    Welcome t = new Welcome(5);
    }
    }