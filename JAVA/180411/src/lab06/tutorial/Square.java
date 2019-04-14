package lab06.tutorial;

public class Square extends Rectangle {
	public Square(String name, double side) {
		// this will call the constructor of Rectangle
		super(name, side, side);
	}
	
	@Override
	public String getClassName(){
		return "Square"; 
	}
	
	public double getSide() {
		return super.getWidth();
	}
	
	public void setSide(int side) {
		super.setSize(side, side);		
	}
}