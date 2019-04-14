package lab06.tutorial;

public class Circle extends TwoDimensionalShape {
	// constructor
	public Circle(String name, double r) {
		super(name, r, r);
	}

	@Override
	// return current class name
	public String getClassName() {
		return "Circle";
	}

	public double getRadius() {
		return super.getDimension1();
	}

	public void setRadius(double r) {
		super.setDimension1(r);
		super.setDimension2(r);
	}
	
	public double getArea() {
		return Math.PI * super.getDimension1() * super.getDimension1();
	}
}
