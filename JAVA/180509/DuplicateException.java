package project;

public class DuplicateException extends Exception {
	public DuplicateException(){
		super("The number is existed in array");
	}
	public DuplicateException(String msg){
		super(msg);
	}
	
}
