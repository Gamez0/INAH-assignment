import java.util.*;
public class test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Circle cir1 = new Circle("Cir one",3.0);
		Rectangle rec1 = new Rectangle("Rect One",3.0,4.0);
		Square sq1 = new Square("Square One",6.0);
		
		System.out.println("Circle area: "+cir1.getArea()+" radius : "+cir1.getRadius()+" diameter : "+cir1.getDiameter());
		System.out.println("Rectangle area: "+rec1.getArea()+" widht : "+rec1.getWidth()+" height : "+rec1.getHeight());
		System.out.println("Square : "+sq1.getArea()+" side : "+sq1.getSide());

		System.out.println(cir1);
		System.out.println(rec1);
		System.out.println(sq1);
	
	}

}
