package aboutAbstract;

public class PayrollSystemTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Employee[] employees = new Employee[4];
		
		employees[0] =	new SalariedEmployee("John", "Smith", "111-11-1111",800.00);	
		employees[1] =	new HourlyEmployee("Karen", "Price", "222-22-2222", 16.75,40);
		employees[2] =	new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000,.06);
		employees[3] =	new BasePlusCommissionEmployee("Bob", "Lewis","444-44-4444",5000, .04, 300);

	}

}
