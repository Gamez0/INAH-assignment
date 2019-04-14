package aboutAbstract;

public class SalariedEmployee extends Employee {

	private double weeklySalary;

	public SalariedEmployee(String first, String last, String ssn, double weeklySalary) {
		super(first, last, ssn);
		setWeeklySalary(weeklySalary);
	}

	public double getWeeklySalary() {
		return weeklySalary;
	}

	public void setWeeklySalary(double salary) {
		if (salary >= 0.0)
			weeklySalary = salary;
		else
			throw new IllegalArgumentException("Weekly salary must be >= 0.0");
	}

	@Override
	public double earnings() {
		// TODO Auto-generated method stub
		return getWeeklySalary();
	}

	@Override
	public String toString() {
		return String.format("salaried employee: %s\n%s: $%,.2f", super.toString(), "weekly salary", getWeeklySalary());

	}
}