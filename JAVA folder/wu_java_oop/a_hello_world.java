public class a_hello_world {
    public static void arrayPrint(String[] name) {
        System.out.print("[");
        for (int i = 0; i < name.length; ++i) {
            System.out.print(name[i]);
            if (i < name.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.print("]");
    }
    public static void main(String[] args) {
        System.out.println("Hello, World! = 1");
        System.out.println("Hello, World! = 2");

        arrayPrint(new String[] {"Aa", "Bb", "Cc"});
    }
}

