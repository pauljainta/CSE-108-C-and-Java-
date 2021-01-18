package Offline2;

public class Square extends Shape{

	private double length;
	private static int counter =0;
	public Square(double length) {
		this.setLength(length);
		setCounter(getCounter() + 1);
	}
	public Square(double length, int i) {
		
	}
	public double getLength() {
		return length;
	}
	public void setLength(double length) {
		this.length = length;
	}
	public static int getCounter() {
		return counter;
	}
	public static void setCounter(int counter) {
		Square.counter = counter;
	}
	public double getArea()
	{
		return getLength() * getLength();
	}
	public void printName()
	{
		System.out.println("Name: Square" + getCounter());
	}
	

}
