public class main {
    public static void main(String[] args) {
        DynamicArray dynamicArray = new DynamicArray(5);

        dynamicArray.add("A");
        dynamicArray.add("B");
        dynamicArray.add("C");
        dynamicArray.add("D");
        dynamicArray.add("E");
        dynamicArray.add("F");

        dynamicArray.delete("A");
        dynamicArray.delete("B");
        // dynamicArray.delete("C");

        dynamicArray.Insert(0, "X");
        // dynamicArray.delete("B");
        System.out.println("Search for [X] is in index : " + dynamicArray.search("C"));

        System.out.println("Detail Data : " + dynamicArray);
        System.out.println("Size : " + dynamicArray.size);
        System.out.println("Capacity : " + dynamicArray.capacity);
        System.out.println("Empty : " + dynamicArray.isEmpty());
    }
}
