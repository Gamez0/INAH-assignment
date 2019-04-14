package Exercise2;

public class test {
	A var1 = new A();
	A var2 = new B();
	B var3 = new D();
	C var4 = new C();
	D var5 = new D();
	Object var6 = new B ();
	
	var1.method1();	// A1
	var2.method1();	// B1 A1
	var3.method1();	// B1 A1
	var4.method1();	// B1 A1
	var5.method1();	// B1 A1
	var6.method1();	// COMPILER ERROR
	
	var1.method2();	// A1 A2
	var2.method2();	// B1 A1 A2		"this is a good question"
	var3.method2();	// C2 D2
	var4.method2();	// C2
	var5.method2();	// C2 D2
	var6.method2();	// COMPILER ERROR
	
	var3.method3();	// COMPILER ERROR
	var5.method3();	// B1 A1 C3
	
	((B)var1).method1(); // Run time error var1 is no polymorphism object downcasting for var1 
	((C)var2).method2(); // Run time error also /if A var2 = new C(); it works
	((D)var5).method1(); // B1 A1 
	((C)var3).method3(); // B1 A1 C3	object D
	((D)var4).method3(); // Run time error
	((C)var6).method3(); // Run time error

}
