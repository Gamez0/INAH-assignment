
public class Circle extends TwoDimensionalShape{

	static final String CLASS_NAME="Circle";
	double diameter;
	Circle(String name, double r1){
		super(name,r1,r1);
	}
	
	

	String getClassName() {
		// TODO Auto-generated method stub
		return CLASS_NAME;
	}


	
	public double getRadius() {
		// TODO Auto-generated method stub
		return super.getDimension1();
	}

	
	public void setRadius(double r) {
		// TODO Auto-generated method stub
		super.setDimension1(r);
		super.setDimension1(r);
	}
	
	

	public double getDiameter() {
		return diameter;
	}


	public void setDiameter() {
		diameter = 2*getDimension1();
	}


	double getArea() {
		// TODO Auto-generated method stub
		return Math.PI*super.getDimension1()*super.getDimension2();
	}
	
	public String toString() {
		return String.format("%s is a[%s], and is a [%s]", super.getName(),getClassName(),super.getClassName());	
		}

	
}
