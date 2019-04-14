package lab06.tutorial;

public class Rectangle extends TwoDimensionalShape implements Sizable{
	public Rectangle(String name, double width, double height) {
		// store width in field demension1, height in field demension2
		super(name, width, height);
	}

	@Override
	public String getClassName(){
		return "Rectangle"; 
	}
	
	public double getWidth() {
		return super.getDimension1();
	}

	public double getHeight() {
		return super.getDimension2();
	}

	public void setSize(double w, double h){
		super.setDimension1(w);
		super.setDimension2(h);
	}
	
	public double getArea() {
		return super.getDimension1() * super.getDimension2();
	}

	
}
