public class Solution {

    private double radius;
    private double x_center;
    private double y_center;
    private Random rand;

    public Solution(double radius, double x_center, double y_center) {
        this.radius = radius;
        this.x_center = x_center;
        this.y_center = y_center;
        this.rand = new Random();
    }
    
    public double[] RandPoint() {
        // random angle
        double theta = rand.NextDouble() * 2 * Math.PI;

        // random radius (IMPORTANT: sqrt for uniform distribution)
        double r = Math.Sqrt(rand.NextDouble()) * radius;

        double x = x_center + r * Math.Cos(theta);
        double y = y_center + r * Math.Sin(theta);

        return new double[] { x, y };
    }
}
