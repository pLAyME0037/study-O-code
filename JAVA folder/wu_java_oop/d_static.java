class d_static {
    public static void main(String[] args) {
        System.out.println("Hello, World");

        while (counter < 10) { counter(); }
        System.out.println("number: " + counter);

        d_static.outer_class display_nested_method = new d_static.outer_class();
        display_nested_method.display();
    }

    static {
        System.out.println("foo");
    }

    static class outer_class {
        void display() {
            System.out.println("from nested class");
        }
    }

    public static int counter = 0;
    public static void counter() { counter++; }
}

// class two {
//     public static void main(String[] args) {
//         d_static.counter();
//         System.out.println("class tow: " + d_static.counter);
//     }
// }
