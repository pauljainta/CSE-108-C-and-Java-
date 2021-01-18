package Offline2;

public class Sphere extends Shape {

	private double radius;
	private static int counter = 0;
	private Circle circle;
	
	Sphere(double radius)
	{
		this.radius = radius;
		setCounter(getCounter() + 1);
		circle = new Circle(radius, 0);
	}
	public double getRadius() {
		return radius;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	public static int getCounter() {
		return counter;
	}
	public static void setCounter(int counter) {
		Sphere.counter = counter;
	}
	public double getBaseArea()
	{
		return circle.getArea();
	}
	public double getArea()
	{
		return 4 *circle.getArea();
	}
	public double getVolume()
	{
		return (4 / 3.0 * Math.PI * getRadius() * getRadius() * getRadius()) ;
	}
	public void printName()
	{
		System.out.println("Name: Sphere" + getCounter());
	}
}
