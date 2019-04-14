package fuckinghomework;

import java.util.*;

public class CD extends Item{

	public String cdTitle;
	public String cdArtist;
	public int pubYear;
	public int year = Calendar.getInstance().get(Calendar.YEAR);
	public CD(String itemID, int importPrice,String title, String artist, int year) {
		super(itemID, importPrice);
		cdTitle=title;
		cdArtist=artist;
		pubYear=year;
		// TODO Auto-generated constructor stub
	}
	

	public String getCdArtist() {
		return cdArtist;
	}
	public int getPubYear() {
		return pubYear;
	}
	
	@Override
	public int getSalePrice() {
		if(year-pubYear<=1)
			return (int) (1.5*super.getImportPrice());
		else if(year-pubYear>1 && year-pubYear<=2)
			return super.getImportPrice();
		else
			return (int) (0.7*super.getImportPrice());
	}
	@Override
	public String getInfo() {
		// TODO Auto-generated method stub
		return cdTitle+" - "+cdArtist+"\t\t";
	}

}
