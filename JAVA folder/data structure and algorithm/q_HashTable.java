import java.util.Hashtable;

public class q_HashTable {
    public static void main(String[] args) {
        Hashtable<Integer, String> table = new Hashtable<>(11);

        table.put(100, "SpongeBob");
        table.put(123, "Partick");
        table.put(143, "Sanddy");
        table.put(456, "Squidward");
        table.put(987, "Gary");

        // table.remove(456);

        for (Integer key : table.keySet()) {
            // System.out.println(key + "\t" + table.get(key));
            System.out.println(key.hashCode() % 11 + "\t" + key + "\t" + table.get(key));
        }
    }
}
