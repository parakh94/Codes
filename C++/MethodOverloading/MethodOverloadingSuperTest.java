import junit.framework.TestCase;

public class MethodOverloadingSuperTest extends TestCase {

	public MethodOverloadingSuperTest(String testName){
		super(testName);
	}
	
	public void setUp() throws Exception {
	}

	
	public void tearDown() throws Exception {
	}

	
	public void test1() {
		String arg = "Apple";
		int returnindex = MethodOverloadingSuper.checkOverloading(arg);
		int returnexpected = 1;
		assertEquals(returnindex,returnexpected);
	}
	
	public void test2(){
		int arg=5;
		int returnindex = MethodOverloadingSuper.checkOverloading(arg);
		int returnexpected = 2;
		assertEquals(returnindex,returnexpected);
	}
	
	public void test3(){
		double arg=5.5;
		int returnindex = MethodOverloadingSuper.checkOverloading(arg);
		int returnexpected = 3;
		assertEquals(returnindex,returnexpected);
	}
}
