
public class Square extends Rectangle{

	static final String CLASS_NAME = "Square";
	
	public Square(String name, double side) {
		super(name,side,side);
	}
	
	

	String getClassName() {
		// TODO Auto-generated method stub
		return CLASS_NAME;
	}

	public double getSide() {
		// TODO Auto-generated method stub
		return super.getDimension1();
	}
	
	public void setSide(double dimension1) {
		// TODO Auto-generated method stub
		super.setDimension1(dimension1);
	}
	public String toString() {
		return String.format("%s is a[%s], and is a [%s]", super.getName(),getClassName(),super.getClassName());	
		}
}
