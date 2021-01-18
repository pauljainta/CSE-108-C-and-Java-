package Offline2;

import java.text.DecimalFormat;
import java.util.Scanner;



public class Main {

	public static void main(String[] args)
	{
		
		int option =0;
		Scanner sc = new Scanner(System.in);
		
		do{
			showList();
			
			try{
				option = sc.nextInt();
				
				if(option<0 || option>5)
					throw new MyException();
				
				if(option == 1){
					System.out.println("Enter radius: ");
					double radius1 = 0;
					try{
						radius1 = sc.nextDouble();
						if(radius1<0) throw new MyException();
						Circle circle = new Circle(radius1);
						circle.printName();
						double value =Double.parseDouble(new DecimalFormat("##.####").format(circle.getArea()));
						System.out.println("Area: "+ value );
						
					}catch(MyException e){
						e.f1();
					}
					
				}
				
				
				else if(option ==2){
					try{
					System.out.println("Enter radius: ");
					double radius2 = sc.nextDouble();
					if(radius2<0) throw new MyException();
					System.out.println("Enter height: ");
					double height = sc.nextDouble();
					if(height<0) throw new MyException();
					Cylinder cylinder = new Cylinder(radius2, height);
					cylinder.printName();
					double value =Double.parseDouble(new DecimalFormat("##.####").format(cylinder.getBaseArea()));
					System.out.println("Area of the base: "+ value);
					double value2 =Double.parseDouble(new DecimalFormat("##.####").format(cylinder.getSurfaceArea()));
					System.out.println("Area of the surface: "+ value2);
					double value3 =Double.parseDouble(new DecimalFormat("##.####").format(cylinder.getVolume()));
					System.out.println("Volume : "+ value3);
					}catch(MyException e){
						e.f1();
					}
				}
					
					
				else if(option == 3){
					try{
					System.out.println("Enter radius: ");
					double radius3 = sc.nextDouble();
					if(radius3<0) throw new MyException();
					Sphere sphere = new Sphere(radius3);
					sphere.printName();
					double value1 =Double.parseDouble(new DecimalFormat("##.####").format(sphere.getBaseArea()));
					System.out.println("Area of the base: "+value1 );
					double value2 =Double.parseDouble(new DecimalFormat("##.####").format(sphere.getArea()));
					System.out.println("Area: "+ value2);
					double value3 =Double.parseDouble(new DecimalFormat("##.####").format(sphere.getVolume()));
					System.out.println("Volume: "+ value3);
					}catch(MyException e){
						e.f1();
					}
				}
					
					
				else if(option == 4){
					try{
					System.out.println("Enter length: ");
					double length1 = sc.nextDouble();
					if(length1<0) throw new MyException();
					Square square = new Square(length1);
					square.printName();
					double value =Double.parseDouble(new DecimalFormat("##.####").format(square.getArea()));
					System.out.println("Area: "+value);
					}catch(MyException e){
						e.f1();
					}
				}
					
					
				else if(option == 5){
					try{
					System.out.println("Enter length: ");
					double length2 = sc.nextDouble();
					if(length2<0) throw new MyException();
					Cube cube = new Cube(length2);
					cube.printName();
					double value1 =Double.parseDouble(new DecimalFormat("##.####").format(cube.getBaseArea()));
					System.out.println("Area of the base: "+value1);
					double value2 =Double.parseDouble(new DecimalFormat("##.####").format(cube.getArea()));
					System.out.println("Area: "+ value2);
					double value3 =Double.parseDouble(new DecimalFormat("##.####").format( cube.getVolume()));
					System.out.println("Volume: "+  value3 );
				}catch(MyException e){
					e.f1();
				}
				}
				
			}catch(MyException e){
				e.f2();
			}
					
				
			
			
			
		}while(true);
	}
	static void showList()
	{
		System.out.println("Please select your choice:\n1. Circle\n2. Cylinder\n3. Sphere\n4. Square\n5. Cube");
	}
}
