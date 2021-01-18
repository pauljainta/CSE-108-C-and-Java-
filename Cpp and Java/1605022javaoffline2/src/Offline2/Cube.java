package Offline2;

public class Cube extends Shape{

	private double length;
	private static int counter = 0;
	private Square square;
	
	Cube(double length)
	{
		this.length = length;
		setCounter(getCounter() + 1);
		square = new Square(length, 0);
	}
	public static int getCounter() {
		return counter;
	}

	public static void setCounter(int counter) {
		Cube.counter = counter;
	}
	

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

//	public int getCounter() {
//		return counter;
//	}
//
//	public void setCounter(int counter) {
//		this.counter = counter;
//	}
	public double getBaseArea()
	{
		return getLength() * getLength();
	}
	public double getArea()
	{
		return 6.0 *getLength() * getLength();
	}
	public double getVolume()
	{
		return getLength() * getLength() *getLength() ;
	}
	public void printName()
	{
		System.out.println("Name: Cube" + getCounter());
	}

	
}
