import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.DataOutputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.BufferedInputStream;

class iostream {
    static FileInputStream in = null;
    static FileOutputStream out = null;

    public static void main(String[] args) throws IOException {
        // byteStream();
        // charStream();
        // readCharStream();
        scanRead();
        double n = 4000 - 40100;
        System.out.format("%f, %2$+020.10f %n", Math.PI, n);
        // dataStream();
        // readDataStream();
    }

    public static void byteStream() throws IOException {
        try {
            in = new FileInputStream("./data_files/input_text.txt");
            out = new FileOutputStream("./data_files/output_text.txt");
            String message = "message: Hello, World.\n";
            out.write(message.getBytes());
            int c;
            while ((c = in.read()) != -1) { out.write(c); }
        } finally {
            if (in != null) in.close();
            if (out != null) out.close();
        }
    }

    public static void charStream() throws IOException {
        FileWriter fw = null;
        FileReader fr = null;

        try {
            fr = new FileReader("./data_files/input_text.txt");
            fw = new FileWriter("./data_files/output_text.txt");

            String message = "Message: Hello, World.\n";
            fw.write(message);
            int c;
            while ((c = fr.read()) != -1) { fw.write(c); }
        } finally {
            if (fr != null) fr.close();
            if (fw != null) fw.close();
        }
    }

    public static void readCharStream() throws IOException {
        BufferedReader is = null;
        PrintWriter    os = null;

        try {
            is = new BufferedReader(new FileReader("./data_files/input_text.txt"));
            os = new PrintWriter(new FileWriter("./data_files/output_text.txt"));

            String l;
            while ((l = is.readLine()) != null) {
                System.out.println(l);
                // os.write(l);
                os.println(l);
            }
        } finally {
            if (is != null) is.close();
            if (os != null) os.close();
        }
    }

    static final String dataFile = "./data_files/invoicedata";
    static final double[] prices = { 19.99, 9.99, 15.99, 3.99, 4.99 };
    static final int[] units = { 12, 8, 13, 29, 50 };
    static final String[] descs = {
        "Java T-shirt",
        "Java Mug",
        "java Duke Juggling Dolls",
        "Java Pin",
        "Java Key Chain"
    };

    public static void dataStream() throws IOException {
        try (DataOutputStream out = new DataOutputStream(
                                    new BufferedOutputStream(
                                    new FileOutputStream(dataFile)))) {
            for (int i = 0; i < prices.length; ++i) {
                out.writeDouble(prices[i]);
                out.writeInt(units[i]);
                out.writeUTF(descs[i]);
            }
        }
    }

    public static void readDataStream() {
        double total = 0.0;

        try (DataInputStream in = new DataInputStream(
                                  new BufferedInputStream(
                                  new FileInputStream(dataFile)))) {
            double price;
            int unit;
            String desc;

            while (true) {
                price = in.readDouble();
                unit = in.readInt();
                desc = in.readUTF();
                System.out.format("You ordered %d units of %s at $%.2f%n",
                                  unit, desc, price);
                total += unit * price;
            }
        } catch (EOFException e) {
            System.out.printf("Total: $%.2f", total);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void scanRead() throws IOException {
        Scanner s = null;
        double number = 0;

        try {
            s = new Scanner(
                new BufferedReader(
                new FileReader("./data_files/input_text.txt")));
            // s.useDelimiter(",\\s*"); // comma & optional space
            while (s.hasNext()) { System.out.println(s.next()); }
        } finally {
            if (s != null) s.close();
        }

        System.out.println("----------------------------");

        try {
            s = new Scanner(
                new BufferedReader(
                new FileReader("./data_files/number.txt")));
            s.useLocale(Locale.US);
            while (s.hasNext()) {
                if (s.hasNextDouble()) { number += s.nextDouble(); } 
                else { s.next(); }
            }
        } finally {
            if (s != null) s.close();
        }
        System.out.printf("Sum: %.2f%n", number);
    }
}
