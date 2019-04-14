
public class Oops {
	public static void main(String[] args) {
		int x=0;
		System.out.println("x is " + x);	// 초기화 안되있어서 error
		x = 15;
		System.out.println("x is" + x);
		int []array = new int[10];
		for(int i=1;i<=10;i++) {
			array[i] = x+i;
		}
		System.out.println("First and last number of array are:" + array[1] +"and"+array[10]);
	}
}
