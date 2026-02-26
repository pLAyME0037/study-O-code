public class a_hello_world {
    public static void nameList(String[] names) {
        System.out.print("[");
        for (int i = 0; i < names.length; i++) {
            System.out.print(names[i]);
            if (i < names.length -1) {
                System.out.print(", ");
            }
        }
        System.out.print("]");
    }

    public static void main(String[] args) {
        System.out.println("Hello, World!");
        System.out.println("Hello, World!");

        nameList(new String[] {"lina", "jone", "gita"});
    }
}

