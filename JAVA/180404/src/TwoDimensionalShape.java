import java.util.*;

public class TwoDimensionalShape {

	static final String CLASS_NAME = "2D Shape";
	private String name;
	private double dimension1;
	private double dimension2;
	
	public TwoDimensionalShape(String name, double d1, double d2){
		this.name=name;
		this.dimension1=d1;
		this.dimension2=d2;
	}

	String getClassName() {
		return CLASS_NAME;
	}
	
	double getArea() {
		return 0;
	}
	
	public String getName() {
		return name;
	}


	public double getDimension1() {
		return dimension1;
	}


	public void setDimension1(double dimension1) {
		this.dimension1 = dimension1;
	}


	public double getDimension2() {
		return dimension2;
	}


	public void setDimension2(double dimension2) {
		this.dimension2 = dimension2;
	}


	@Override
	public String toString() {
		return "2D Shape";
	}

}
