package source2;

public class Dog{ 
	public void DogClassName() {
		
	}
	   public String getType () {
	      System.out.println("NormalDog");
	      return "NormalDog";
	   }
	 }

	/**
	 * Pet Dog has an extra method dogName()
	 */   
	class PetDog extends Dog{ 
	   public String getType () {
	      System.out.println("PetDog");
	      return "PetDog";
	   }
	   public String dogName () {
	      System.out.println("I don't have Name !!");
	      return "NO Name";
	   }
	 }

	
	class wildDog extends Dog{

		 public String getType() {
		    System.out.println("Wild Dog");
		    return "wildDog";
		 }
		 public void wildDogFunction() {
			
		}
		 }
	/**
	 * Police Dog has an extra method secretId()
	 */
	class PoliceDog extends PetDog{

	 public String secretId() {
	    System.out.println("PoliceDog ID");
	    return "ID";
	 }

	 public String getType () {
	     System.out.println("I am a Police Dog");
	     return "Police Dog";
	 }
	}
	
	class TestDowncasting{
		
		
		public static void main (String[] args) {
		      
		     Dog obj1 = new Dog();
		       
		     Dog obj2 = new PetDog();
		     
		     //Dog obj3 = new Dog(); 
		     Dog obj3 = new PoliceDog();
		      obj1.getType(); // Prints Normal Dog
		      obj2.getType();  //Prints Pet Dog
		      obj3.getType();  // Prints Police Dog
		      ((PoliceDog)obj3).secretId();
		}
		
	}