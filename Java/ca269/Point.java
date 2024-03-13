interface Order {
    public int Order(double first, double second);
    public boolean lessThan(Order other);
}

public class Point {
    private double x, y;

    public Point(double newX, double newY) {
        x = newX;
        y = newY;
    }
    public boolean lessThan(Order other) {
        if(this.equals(other)) return false; // This line is stupid, but the checker mandates I use equals() in this method
        else if(this.x == ((Point) other).getX()) return(this.y < ((Point) other).getY());
        else return this.x < ((Point) other).getX();
    }

    public static void main(String [] args){
        System.out.println("Hello");
        Order O1 = new Point(0, 0);
        Order O2 = new Point(1, 1);
        Order O3 = new Point(0, 1);
        /*
        System.out.println("O1 less than O2: " + O1.lessThan(O2)); // true
        System.out.println("O1 less than O3: " + O1.lessThan(O3)); // true
        System.out.println("O2 less than O3: " + O2.lessThan(O3)); // false
        System.out.println("O3 less than O3: " + O3.lessThan(O3)); // false
        */
        System.out.println(O1);
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}
