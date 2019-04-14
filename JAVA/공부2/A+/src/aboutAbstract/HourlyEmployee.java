package aboutAbstract;

public class HourlyEmployee extends Employee {
	private double wage;
	private double hours;
	
	public HourlyEmployee(String first, String last, String ssn, double wage, double hours) {
		super(first, last, ssn);
		setWage(wage);
		setHours(hours);
	}

	public double getWage() {
		return wage;
	}




	public void setWage(double wage) {
		this.wage = wage;
	}




	public double getHours() {
		return hours;
	}




	public void setHours(double hours) {
		this.hours = hours;
	}




	@Override
	public String toString() {
		return String.format( "hourly employee: %s\n%s: $%,.2f; %s:%,.2f",
				 super.toString(), "hourly wage", getWage(),
				 "hours worked", getHours() );

	}

	@Override
	public double earnings() {
		if ( getHours() <= 40 ) // no overtime
			 return getWage() * getHours();
		else
			 return 40 * getWage() + ( getHours() - 40 ) * getWage() *
			1.5;
	}

}
