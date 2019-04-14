package lab06.tutorial;

import java.util.Arrays;

public class ShapeTester {
	public static void main(String[] args) {

		// create an object
		TwoDimensionalShape[] myShapes = new TwoDimensionalShape[5];
		myShapes[0] = new Circle("C1", 3);
		myShapes[1] = new Rectangle("R1", 3, 4);
		myShapes[2] = new Square("S1", 6);
		myShapes[3] = new Rectangle("R2", 4, 5);
		myShapes[4] = new Circle("C2", 5);
		System.out.println("Five shapes have been created.");
		
		//myShapes[0].getRadius();	//TDS class 에 있는 method만 가능	
		
		Circle[] myShapes2 = new Circle[1];
		myShapes2[0] = new Circle("C1",3);
		myShapes2[0].getRadius();	// Circle class 타입이라 가능
		
		
		
		for (int i = 0; i < myShapes.length; i++) {
			//myShapes[i].resize(2.0);
			System.out.println(myShapes[i]);
			System.out.println("area:"+myShapes[i].getArea());
		}
		
		//System.out.println("shape 0 " + myShapes[0].compareTo(myShapes[2]) + " shape 2");
		
	}
}
