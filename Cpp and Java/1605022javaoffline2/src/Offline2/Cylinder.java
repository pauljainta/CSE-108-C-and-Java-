package Offline2;

public class Cylinder extends Shape{
	
	private double radius;
	private double height;
	private static int counter = 0;
	private Circle circle;
	
	
	Cylinder (double radius, double height)
	{
		this.radius = radius;
		this.height = height;
		circle = new Circle(radius, 0);
		setCounter(getCounter() + 1);
	}
	public double getRadius() {
		return radius;
	}
	public void setRadius(double radius) {
		this.radius = radius;
	}
	public double getHeight() {
		return height;
	}
	public void setHeight(double height) {
		this.height = height;
	}
	public static int getCounter() {
		return counter;
	}
	public static void setCounter(int counter) {
		Cylinder.counter = counter;
	}
	
	public double getBaseArea()
	{
		return circle.getArea(); 
	}
	public double getSurfaceArea()
	{
		return (2 * Math.PI * getRadius() * getHeight());
	}
	public double getVolume()
	{
		return (Math.PI * getRadius() * getRadius() * getHeight()) ;
				
	}
	
	public void printName()
	{
		System.out.println("Name: Cylinder" + getCounter());
	}
	
}
