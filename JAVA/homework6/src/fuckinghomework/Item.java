package fuckinghomework;

public abstract class Item implements ForSale{
	public String itemID;
	public int importPrice;
		
	public Item(String itemID, int importPrice) {
		this.itemID = itemID;
		this.importPrice = importPrice;
	}

	public String getItemID() {
		return itemID;
	}
	
	
	public abstract int getSalePrice();

	public abstract String getInfo();

	public int getImportPrice() {
		return importPrice;
	}

	
}
