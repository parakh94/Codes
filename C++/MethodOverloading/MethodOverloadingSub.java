
public class MethodOverloadingSub {

	public static int checkOverloading(String argument){
		System.out.println("Value Passed in Subclass method 1:"+argument);
		return 1;
	}
	
	public static int checkOverloading(int argument){
		System.out.println("Value Passed in SubClass method 2:"+argument);
		return 2;
	}
}
