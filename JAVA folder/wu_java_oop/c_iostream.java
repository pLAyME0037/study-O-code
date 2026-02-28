import java.io.IOException;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.DataOutputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.BufferedInputStream;

class c_iostream {
    static FileInputStream in = null;
    static FileOutputStream out = null;
    static final String dataFile = "invoicedata";
    static final double[] prices = { 19.99, 9.99, 15.99, 3.99, 4.99 };
    static final int[] units = { 12, 8, 13, 29, 50 };
    static final String[] descs = {
        "Java T-shirt",
        "Java Mug",
        "Duke Juggling Dolls",
        "Java Pin",
        "Java Key Chain"
    };

    public static void main(String[] args) throws IOException {
        byteStream();
        dataStream();
        readDataStream();
    }

    public static void byteStream() throws IOException {
        try {
            in = new FileInputStream("./temp/input_text.txt");
            out = new FileOutputStream("./temp/output_text.txt");
            String message = "message: Hello, World.";
            in.read(message.getBytes());
            out.write(message.getBytes());
            int c;
            while ((c = in.read()) != -1) { out.write(c); }
        } finally {
            if (in != null) in.close();
            if (out != null) in.close();
        }
    }

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
            System.out.println("Total: $" + total);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
