package Offline2;

public class MyException extends Exception{

	MyException(){}
	
	
	void f1()
	{
		System.out.println("You cannot enter negative value.");
	}
	void f2()
	{
		System.out.println("You cannot enter invalid value.");
	}
}
