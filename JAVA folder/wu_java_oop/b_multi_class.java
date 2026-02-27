class b_multi_class {
    public static void main(String[] args) {
        System.out.println("Hello, World");

        Print print = new Print("Mean");
        System.out.println(print);
    }
}

class Print {
    String name;

    public Print(String name) {
        this.name = name;
        System.out.println("Hello, " + name);
    }

    @Override
    public String toString() {
        return "Hello, To String is " + this.name;
    }
}
