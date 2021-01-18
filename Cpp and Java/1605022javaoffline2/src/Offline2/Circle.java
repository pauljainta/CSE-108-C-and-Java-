package Offline2;

public class Circle extends Shape{

	private double radius;
	private static int counter = 0;
	
	Circle(double radius)
	{
		this.setRadius(radius);
		setCounter(getCounter() + 1);
	}
	Circle(double radius, double n)
	{
		this.setRadius(radius);
	}
	public double getRadius() {
		return radius;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	public double getArea()
	{
		return Math.PI * getRadius() * getRadius();
	}
	
	public static int getCounter() {
		return counter;
	}
	public static void setCounter(int counter) {
		Circle.counter = counter;
	}
	public void printName()
	{
		System.out.println("Name: Circle" + getCounter());
	}
	
	
	
}
