package fuckinghomework;

import java.util.Calendar;

public class Movie extends Item{
	public String cdTitle;
	public int pubYear;
	public int year = Calendar.getInstance().get(Calendar.YEAR);
	
	public Movie(String itemID, int importPrice, String title, int year) {
		super(itemID, importPrice);
		cdTitle = title;
		pubYear = year;
	}
	
	



	public int getPubYear() {
		return pubYear;
	}

	@Override
	public int getSalePrice() {
		if(year-pubYear<=1)
			return (int)2.0*super.getImportPrice();
		else
			return (int) super.getImportPrice()/2;
			
	}
	@Override
	public String getInfo() {
		// TODO Auto-generated method stub
		return cdTitle+"\t\t";
	}
	
	
}
