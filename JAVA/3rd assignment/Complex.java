import java.util.Scanner;

public class Complex {

	/** real number */
	private double r;

	/** imaginary number */
	private double i;

	/** Constructer with two parameter Complex */
	Complex(double real, double imagin) {
		r = real;
		i = imagin;
	}
	/** Constructer with no parameter Comlpex */
	Complex(){
		r=0;
		i=0;
	}
	/** print method to print out the complex number */
	public void printComplex() {
		if (getReal() > 0) {
			if (getImaginary() > 0) {
				System.out.print(getReal() + "+" + getImaginary() + "i");
			} else if (getImaginary() == 0) {
				System.out.print(getReal());
			} else if (getImaginary() < 0) {
				System.out.print(getReal() +""+ getImaginary() + "i");
			}
		}

		else if (getReal() == 0) {
			if (getImaginary() > 0) {
				System.out.print( getImaginary() + "i");
			} else if (getImaginary() == 0) {
				System.out.print('0');
			} else if (getImaginary() < 0) {
				System.out.print(getImaginary() + "i");
			}
		} else if (getReal() < 0) {
			if (getImaginary() > 0) {
				System.out.print(getReal() + "+" + getImaginary() + "i");
			} else if (getImaginary() == 0) {
				System.out.print(getReal());
			} else if (getImaginary() < 0) {
				System.out.print(getReal() +""+ getImaginary() + "i");
			}
		}
	}

	/** Return the Real number */
	public double getReal() {
		return r;
	}

	/** Return the Imaginary number */
	public double getImaginary() {
		return i;
	}

	/** Return the absolute of a complex number */
	public double absolute() {
		return Math.sqrt(r * r + i * i);
	}
	
	/** Add two Complexes */
	public static Complex add(Complex c1, Complex c2) {
		return new Complex(c1.r + c2.r, c1.i + c2.i);
	}
	
	/** Subtract two Complexes */
	public static Complex subtract(Complex c1, Complex c2) {
		return new Complex(c1.r - c2.r, c1.i - c2.i);
	}

	/** Multiply two Complexes */
	public static Complex multiply(Complex c1, Complex c2) {
		return new Complex(c1.r * c2.r - c1.i * c2.i, c1.r * c2.i + c1.i * c2.r);
	}

	public static Complex divide(Complex c1, Complex c2) {
		return new Complex((c1.r * c2.r + c1.i * c2.i) / (c2.r * c2.r + c2.i * c2.i),
				(c1.i * c2.r - c1.r * c2.i) / (c2.r * c2.r + c2.i * c2.i));
	}

	public void sampleOut() {
		double real1, imagin1, real2, imagin2;
		  
		  Scanner scan = new Scanner(System.in);
		  
		  System.out.print("Input First real number : ");
		  
		  real1 = scan.nextDouble();
		  System.out.print("Input First imaginary number : ");
		  
		  imagin1 = scan.nextDouble();
		  
		  System.out.print("Input Second real number : ");
		  
		  real2 = scan.nextDouble();
		  System.out.print("Input Second imaginary number : ");
		  
		  imagin2 = scan.nextDouble();
		  
		  
		  Complex a =new Complex(real1,imagin1);
		  Complex b =new Complex(real2,imagin2);
		  Complex c =new Complex();
		  
		  System.out.print("First number is:");
		  a.printComplex();
		  System.out.print("\n");
		  
		  System.out.print("Second number is:");
		  b.printComplex();
		  System.out.print("\n");
		  c=c.add(a, b);
		  System.out.print("Result of addition is:");
		  c.printComplex();
		  System.out.print("\n");
		  c=c.subtract(a, b);
		  System.out.print("Result of subtraction is:");
		  c.printComplex();
		  System.out.print("\n");
		  c=c.multiply(a, b);
		  System.out.print("Result of multiplication is:");
		  c.printComplex();
		  System.out.print("\n");
		  
		  
		  
	}
	
	public static void main(String[] args) {
	  
	  Complex a = new Complex();
	  a.sampleOut();
	 
	  
	  
  }

}