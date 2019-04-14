
public class Rectangle extends TwoDimensionalShape{

	static final String CLASS_NAME = "Rectangle";
	
	Rectangle(String name, double width, double height){
		super(name,width,height);
	}

	
	
	String getClassName() {
		// TODO Auto-generated method stub
		return CLASS_NAME;
	}



	double getArea() {
		// TODO Auto-generated method stub
		return getWidth()*getHeight();
	}


	public double getWidth() {
		// TODO Auto-generated method stub
		return super.getDimension1();
	}

	
	public double getHeight() {
		// TODO Auto-generated method stub
		return super.getDimension2();
	}
	public void setSize(double w, double h) {
		super.setDimension1(w);
		super.setDimension2(h);
	}
	
public String toString() {
	return String.format("%s is a[%s], and is a [%s]", super.getName(),getClassName(),super.getClassName());	
	}
}
