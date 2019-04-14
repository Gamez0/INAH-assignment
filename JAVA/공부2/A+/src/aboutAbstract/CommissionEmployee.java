package aboutAbstract;

public class CommissionEmployee extends Employee {

	private double grossSales;
	private double commissionRate;
	
	
	
	public CommissionEmployee(String first, String last, String ssn, double grossSales, double commissionRate) {
		super(first, last, ssn);
		setGrossSales(grossSales);
		setCommissionRate(commissionRate);
	}

	public double getGrossSales() {
		return grossSales;
	}



	public void setGrossSales(double sales) {
		if(sales>=0.0)
			grossSales=sales;
		else
			throw new IllegalArgumentException();
	}


	public double getCommissionRate() {
		return commissionRate;
	}



	public void setCommissionRate(double rate) {
		if ( rate > 0.0 && rate < 1.0 )
			 commissionRate = rate;
		else
			 throw new IllegalArgumentException();
	}



	
	public double earnings() {
		// TODO Auto-generated method stub
		return getCommissionRate()+getGrossSales();
	}


	public String toString() {
		// TODO Auto-generated method stub
		return String.format( "%s: %s\n%s: $%,.2f; %s:%.2f",
				 "commission employee", super.toString(),
				 "gross sales", getGrossSales(),
				 "commission rate", getCommissionRate() );
	}

}
