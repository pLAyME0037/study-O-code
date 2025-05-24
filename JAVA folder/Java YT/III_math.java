public class III_math {
    public static void main(String[] args) {

        int a = 2;
        int b = 4;
        int c = 7;
        int d = 15;
        int e = 10;

        a += 5;
        b -= 3;
        c *= 3;
        d /= 5;
        e %= 3;

        System.out.println("a = " + a);
        System.out.println("b = " + b);
        System.out.println("c = " + c);
        System.out.println("d = " + d);
        System.out.println("e = " + e);
        
        int x = 3;
        int y = 5;

        x++;x++;x++;
        y--;y--;

        System.out.println("x = " + x);
        System.out.println("y = " + y);

        double num = 3 + 6 * (5 - 2) / 2.0;

        System.out.println("num = "+num);
    }
}
